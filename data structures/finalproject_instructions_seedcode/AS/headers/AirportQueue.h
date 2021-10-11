#pragma once
#include <queue>
#include "Plane.h"
#include "Random.h"

// There are 3 special types of AirportQueue in the simulator:
//    LandingQueue, ServiceQueue, TakeoffQueue
// All inherit the pure virtual update() method.
class AirportQueue
{
public:
	AirportQueue(Random *random) : m_random(random) 
	{}
	std::queue<Plane *> m_queue;
	Random *m_random;
	virtual void update(int t) = 0;
};