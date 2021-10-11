#pragma once
#include <iostream>
#include "AirportQueue.h"

// ServiceQueue IS-A type of AirportQueue
//		It differs from the other queues because:
//		1, it is a queue of only 1 item (plane)
//		2, it randomly picks a plane from 2 queues of the LandingQueue type
//		3, puts a plane after servicing into a queue of the TakeoffQueue type
class ServiceQueue : public AirportQueue
{
public:
	ServiceQueue(Random *random, AirportQueue *l1, AirportQueue *l2, AirportQueue *t1,
		int min_service_time, int max_service_time, bool verbose) :
	AirportQueue(random), m_landing1(l1), m_landing2(l2), m_takeoff1(t1),
	m_min_service_time(min_service_time), m_max_service_time(max_service_time), m_verbose(verbose) {}

	void update(int t) 
	{
		if (m_queue.empty()) //  currently not servicing any planes
		{
			AirportQueue *landing;
			if (m_landing1->m_queue.empty() && m_landing2->m_queue.empty())
				return;  // both queues are empty
			else if (m_landing1->m_queue.empty() || m_landing2->m_queue.empty())
			{
				landing = (m_landing1->m_queue.empty() ? m_landing2 : m_landing1);
			} 
			else 
			{
				landing = (m_random->next_double() < 0.5 ? m_landing1 : m_landing2); // randomly service a queue
			}
			// get the plane from the front of the selected landing queue
			Plane *plane = landing->m_queue.front();  
			plane->m_landing_time = t;
			landing->m_queue.pop(); // remove the plane from the landing queue
			
			// determine a random service time between the min and max service times
			int duration = m_max_service_time - m_min_service_time;
			m_service_time = m_min_service_time + m_random->next_int(duration); 
			// set the start of the service time for the plane
			m_start_service_time = t;
			m_queue.push(plane); // push the plane into the service queue
			if (m_verbose)
				std::cout << "Starting to service plane " << plane->m_plane_id << " at time " << t << std::endl;
		} 
		else if (t - m_start_service_time > m_service_time) // plane has been in the queue longer then its service time
		{
			Plane *plane = m_queue.front();
			// remove plane from the service queue, and put it in the takeoff queue
			m_queue.pop();
			plane->m_end_service_time = t;
			m_takeoff1->m_queue.push(plane);
			if (m_verbose)
				std::cout << "Plane " << plane->m_plane_id << " has finished service at time " << t << std::endl;
		}
	}

private:
	AirportQueue *m_landing1, *m_landing2, *m_takeoff1;
	int m_min_service_time;
	int m_max_service_time;
	int m_service_time;
	int m_start_service_time;
	bool m_verbose;
};