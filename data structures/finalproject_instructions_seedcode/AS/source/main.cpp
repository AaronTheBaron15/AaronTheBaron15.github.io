#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <ios>
#include "..\headers\Simulator.h"

// Remember this from HW03
int read_int(const std::string &prompt)
{
	std::cin.exceptions(std::ios_base::failbit);
	int num = 0;
	while (true) {
		try {
			std::cout << prompt;
			std::cin >> num;
			std::cout << std::endl;
			return num;
		} catch (std::ios_base::failure &ex) {
			std::cout << "Bad numeric string -- try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
	}
}

int main()
{
	int landing_rate = read_int("Please enter the landing rate [planes/hour]: ");
	
	int min_service_time = read_int("Please enter the min service time [mins]: ");
	int max_service_time = read_int("Please enter the max service time [mins]: ");
	if (max_service_time < min_service_time)
	{
		std::cerr << "Max time must be greater than min time\n";
		exit(1);
	}

	int takeoff_time = read_int("Please enter takeoff time [mins]: ");

	int total_time = read_int("Please enter the total simulation time [hours]: ");
	total_time *= 60;  // convert hours to minutes

	bool verbose = false;
	std::string ans;
	std::cout << "Verbose output? [Y] ";
	std::cin >> ans;
	if (ans == "Y" || ans == "y")
		verbose = true;

	// Create the simulator
	Simulator sim(total_time, landing_rate, min_service_time, max_service_time, takeoff_time, verbose);
	sim.run(); // run the simulation
	sim.report(); // report the run statistics
	
}