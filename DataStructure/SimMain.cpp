#include "pch.h"
#include "Simlinkedqueue.h"

int simMain()
{
	int currentTime = 0;
	int endTime = 10;
	int serviceUserCount = 0;
	int totalWaitTime = 0;

	Simlinkedqueue* pArrivalQueue = new Simlinkedqueue();
	Simlinkedqueue*	pWaitQueue = new Simlinkedqueue();
	QueueNode* pServiceNode1 = nullptr;

	pArrivalQueue->insertCustomer(0, 3); //arrivalTime, serviceTime
	pArrivalQueue->insertCustomer(2, 2);
	pArrivalQueue->insertCustomer(4, 1);
	pArrivalQueue->insertCustomer(6, 1);
	pArrivalQueue->insertCustomer(8, 3);

	for (currentTime = 0; currentTime < endTime; currentTime++)
	{
		pArrivalQueue->processArrival(currentTime, pWaitQueue);
		if (pServiceNode1)
		{
			pServiceNode1 = pArrivalQueue->processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
		}

		if (!pServiceNode1)
		{
			pServiceNode1 = pArrivalQueue->processServiceNodeStart(currentTime, pWaitQueue);
		}

		pWaitQueue->printWaitQueueStatus(currentTime);
	}

	pWaitQueue->printReport(serviceUserCount, totalWaitTime);

	SAFE_DELETE(pArrivalQueue);
	SAFE_DELETE(pWaitQueue);
	SAFE_DELETE(pServiceNode1);

	return 0;
}