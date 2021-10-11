#pragma once
#include <iostream>
#include "AirportQueue.h"
#include "Report.h"

// TakeoffQueue IS-A type of AirportQueue
//		It differs from the other queues because planes are removed from the queue 
//		after it has waited some constant time at the front of the queue.
class TakeoffQueue : public AirportQueue
{
public:
	TakeoffQueue(Random *random, Report *report, int takeoff_time, bool verbose) : 
	  AirportQueue(random), m_report(report), m_takeoff_time(takeoff_time), m_verbose(verbose) {}
	void update(int t) 
	{
		if (m_queue.empty())  // nothing to do
			return;
		Plane *plane = m_queue.front();
		// set the start of the takeoff time for plane at front of takeoff queue
		if (plane->m_start_takeoff_time == -1) 
			plane->m_start_takeoff_time = t;
		else if (t - plane->m_start_takeoff_time > m_takeoff_time)
		{
			m_queue.pop(); // remove plane from takeoff queue
			plane->m_takeoff_time = t; // set the planes actual takeoff time
			if (m_verbose)
				std::cout << "Plane " << plane->m_plane_id << " has taken off at time " << t << std::endl;
			m_report->update_report(plane); // update the report
			delete plane; // plane has left the airspace, so we delete it
		}
	}
private:
	Report *m_report;
	int m_takeoff_time;
	bool m_verbose;
};
