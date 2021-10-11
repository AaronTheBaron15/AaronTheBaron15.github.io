#pragma once

// A plane has attributes like when it arrived, when it landed, when it was serviced, when it takes off, etc.
struct Plane
{
	Plane(int t) : 
	m_arrival_time(t), m_landing_time(-1), m_end_service_time(-1), m_takeoff_time(-1), m_start_takeoff_time(-1)
	{
		m_plane_id = plane_count_id++;
	}

	static int plane_count_id;
	int m_plane_id;
	int m_arrival_time;
	int m_landing_time;
	int m_end_service_time;
	int m_takeoff_time;
	int m_start_takeoff_time;
};

int Plane::plane_count_id = 0;
