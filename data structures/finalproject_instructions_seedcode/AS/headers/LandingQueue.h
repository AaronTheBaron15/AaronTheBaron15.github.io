#pragma once
#include <iostream>
#include <string>
#include "AirportQueue.h"

// LandingQueue IS-A type of AirportQueue
//		It differs from the other queues because planes can be added to it at 
//		some arrival rate.
class LandingQueue : public AirportQueue
{
public:
	LandingQueue(Random *random, int landing_rate, std::string name, bool verbose) : 
	  AirportQueue(random), m_landing_rate(landing_rate), m_name(name), m_verbose(verbose) 
	{
		m_rate_per_min = landing_rate/60.0;
	}

	void update(int t) 
	{
		
		if (m_random->next_double() < m_rate_per_min)  // add planes to landing queue based on arrival rate
		{
			Plane *plane = new Plane(t);
			m_queue.push(plane);
			if (m_verbose)
				std::cout << "Plane " << plane->m_plane_id << " added to queue " << m_name << " at time " << t << std::endl;
		}
	}

private:
	int m_landing_rate;
	double m_rate_per_min;
	std::string m_name;
	bool m_verbose;
};