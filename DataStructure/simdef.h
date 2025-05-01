#pragma once
enum SimStatus {arrival, start, end};

struct SimCustomer
{
	SimStatus status;
	int arrivalTime;
	int serviceTime;
	int startTime;
	int endTime;

	SimCustomer() = default;
	SimCustomer(int _arrivalTime, int _serviceTime)
	{
		status = arrival;
		arrivalTime = _arrivalTime;
		serviceTime = _serviceTime;
		startTime = 0;
		endTime = 0;
	};
};