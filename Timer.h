
#pragma once

#include <chrono>
#include <iostream>

/// <summary>
/// Scope based Timer
/// </summary>
class Timer
{
public:
	Timer()
	{
		startTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		auto micros = end - start;
		double millis = micros * 0.001;

		std::cout << micros << "micros (" << millis << "millis)" << std::endl;
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTimepoint;
};