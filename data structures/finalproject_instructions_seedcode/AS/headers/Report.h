#pragma once
#include "Plane.h"

// This is our report.  We have a print_report() method that generates the required report.
class Report
{
public:
	Report() : m_total_service_time(0), m_planes(0), 
		m_total_landing_waittime(0), 
		m_total_takeoff_waittime(0) {}
	void update_report(Plane *plane)
	{
		++m_planes;
		m_total_service_time += plane->m_takeoff_time - plane->m_arrival_time;
		m_total_landing_waittime += plane->m_landing_time - plane->m_arrival_time;
		m_total_takeoff_waittime += plane->m_takeoff_time - plane->m_end_service_time;
	}
	void print_report()
	{
		std::cout << "Total planes serviced: " << m_planes << std::endl;
		std::cout << "Average service time: " << (double)m_total_service_time/m_planes << std::endl;
		std::cout << "Average landing wait time: " << (double)m_total_landing_waittime/m_planes << std::endl;
		std::cout << "Average takeoff wait time: " << (double)m_total_takeoff_waittime/m_planes << std::endl;
		std::cout << "Overall wait time: " << (double)(m_total_landing_waittime+m_total_takeoff_waittime)/m_planes << std::endl;
	}
private:
	int m_planes;
	int m_total_service_time;
	int m_total_landing_waittime;
	int m_total_takeoff_waittime;
};