#pragma once

#include "LandingQueue.h"
#include "ServiceQueue.h"
#include "TakeoffQueue.h"
#include "Report.h"
#include "Random.h"

// Simulator HAS AirportQueues
class Simulator
{
public:
	Simulator(int total_time, int landing_rate, int min_service_time, int max_service_time, int takeoff_time, bool verbose) :
	  m_max_run(total_time), m_verbose(verbose)
	{
		// initialize my simulator
		m_random = new Random;
		m_report = new Report;
		// Two landing queues
		LandingQueue *landing1 = new LandingQueue(m_random, landing_rate, "LandingQueue1", m_verbose);
		LandingQueue *landing2 = new LandingQueue(m_random, landing_rate, "LandingQueue2", m_verbose);
		m_queues.push_back(landing1);
		m_queues.push_back(landing2);
		// One takeoff queue
		TakeoffQueue *takeoff1 = new TakeoffQueue(m_random, m_report, takeoff_time, m_verbose);
		m_queues.push_back(takeoff1);
		// One service queue
		m_queues.push_back(new ServiceQueue(m_random, landing1, landing2, takeoff1, min_service_time, max_service_time, m_verbose));
	}

	void run() 
	{
		for (int t = 0; t < m_max_run; ++t)
		{
			for (unsigned int i = 0; i < m_queues.size(); ++i)
				m_queues[i]->update(t);  // POLYMORPHISM at work

		}
	}

	void report()
	{
		m_report->print_report(); // Print report statistics
	}

private:
	int m_max_run;
	std::vector<AirportQueue *> m_queues;
	Report *m_report;
	Random *m_random;
	bool m_verbose;
};