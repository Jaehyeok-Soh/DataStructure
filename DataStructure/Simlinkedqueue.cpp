#include "pch.h"
#include "Simlinkedqueue.h"

QueueNode::QueueNode()
{
}

QueueNode::QueueNode(SimCustomer _data)
{
	data = _data;
	next = nullptr;
}

QueueNode::~QueueNode()
{
}

Simlinkedqueue::Simlinkedqueue()
{
	currentElementCount = 0;
	pFront = nullptr;
	pRear = nullptr;
}

Simlinkedqueue::~Simlinkedqueue()
{
	deleteLinkedQueue();
}

bool Simlinkedqueue::enqueueLQ(QueueNode element)
{
	bool ret = false;

	QueueNode* pNode = nullptr;
	pNode = new QueueNode();
	if (pNode)
	{
		*pNode = element;
		pNode->next = nullptr;

		if (isLinkedQueueEmpty())
		{
			pFront = pNode;
			pRear = pNode;
		}
		else
		{
			pRear->next = pNode;
			pRear = pNode;
		}
		currentElementCount++;
		ret = true;
	}
	else
	{
		std::cout << "error, allocate memory" << std::endl;
	}

	return ret;
}

QueueNode* Simlinkedqueue::dequeueLQ()
{
	QueueNode* pReturn = nullptr;

	if (!isLinkedQueueEmpty())
	{
		pReturn = pFront;
		pFront = pFront->next;
		pReturn->next = nullptr;
		currentElementCount--;
		if (isLinkedQueueEmpty())
		{
			pRear = nullptr;
		}
	}
	else
	{
		std::cout << "error, Queue is empty" << std::endl;
	}

	return pReturn;
}

QueueNode* Simlinkedqueue::peekLQ()
{
	QueueNode* pReturn = nullptr;

	if (!isLinkedQueueEmpty())
	{
		pReturn = pFront;
	}

	return pReturn;
}

void Simlinkedqueue::deleteLinkedQueue()
{
	QueueNode* pNode = nullptr;
	QueueNode* pDelNode = nullptr;

	pNode = pFront;
	while (pNode)
	{
		pDelNode = pNode;
		pNode = pNode->next;

		SAFE_DELETE(pDelNode);
	}
	pFront = nullptr;
	pRear = nullptr;
}

bool Simlinkedqueue::isLinkedQueueFull()
{
	bool ret = false;
	return ret;
}

bool Simlinkedqueue::isLinkedQueueEmpty()
{
	bool ret = false;

	if (currentElementCount == 0)
	{
		ret = true;
	}

	return ret;
}

void Simlinkedqueue::displayLinkedQueue()
{
	int i(0);
	QueueNode* current = nullptr;
	std::cout << "Current element count : " << currentElementCount << std::endl;

	current = pFront;
	while (current)
	{
		//std::cout << i << "-" << current->data. << std::endl;
		i++;
		current = current->next;
	}
}

void Simlinkedqueue::insertCustomer(int arrivalTime, int serviceTime)
{
	SimCustomer data = SimCustomer(arrivalTime, serviceTime);
	QueueNode node = QueueNode(data);
	enqueueLQ(node);
}

void Simlinkedqueue::processArrival(int currentTime, Simlinkedqueue* pWaitQueue)
{
	QueueNode* pArrivalNode = nullptr;
	bool isEmpty = isLinkedQueueEmpty();

	while (isEmpty == false)
	{
		pArrivalNode = peekLQ();
		if (pArrivalNode->data.arrivalTime == currentTime)
		{
			pWaitQueue->enqueueLQ(*pArrivalNode);
			printSimCustomer(currentTime, pArrivalNode->data);
			QueueNode* tempNode = dequeueLQ();
			SAFE_DELETE(tempNode);
		}
		else
		{
			break;
		}
		isEmpty = isLinkedQueueEmpty();
	}
}

QueueNode* Simlinkedqueue::processServiceNodeStart(int currentTime, Simlinkedqueue* pWaitQueue)
{
	QueueNode* pReturn = nullptr;
	QueueNode* pServiceNode = nullptr;
	bool isEmpty = false;

	if (pWaitQueue == nullptr)
	{
		return nullptr;
	}

	isEmpty = pWaitQueue->isLinkedQueueEmpty();
	if (isEmpty == false)
	{
		pServiceNode = pWaitQueue->dequeueLQ();
		if (pServiceNode)
		{
			pServiceNode->data.status = start;
			pServiceNode->data.startTime = currentTime;
			printSimCustomer(currentTime, pServiceNode->data);

			pReturn = pServiceNode;
		}
	}

	return pReturn;
}

QueueNode* Simlinkedqueue::processServiceNodeEnd(int currentTime, QueueNode* pServiceNode, int* pServiceUserCount, int* pTotalWaitTime)
{
	int endTime(0), waitTime(0);
	QueueNode* pReturn = nullptr;

	if (pServiceNode == nullptr || pServiceUserCount == nullptr || pTotalWaitTime == nullptr)
	{
		return nullptr;
	}

	endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
	if (endTime <= currentTime)
	{
		waitTime = pServiceNode->data.startTime - pServiceNode->data.arrivalTime;

		(*pServiceUserCount)++;
		(*pTotalWaitTime) += waitTime;

		pServiceNode->data.status = end;
		pServiceNode->data.endTime = currentTime;
		printSimCustomer(currentTime, pServiceNode->data);

		SAFE_DELETE(pServiceNode);
		pReturn = nullptr;
	}
	else
	{
		pReturn = pServiceNode;
	}

	return pReturn;
}

void Simlinkedqueue::printSimCustomer(int currentTime, SimCustomer customer)
{
	std::cout << currentTime << ",\n";

	switch (customer.status)
	{
	case arrival:
		std::cout << "customer arrival\n";
		break;
	case start:
		std::cout << "service start, ";
		std::cout << "arrival time-" << customer.arrivalTime << ", wait time-" << customer.startTime - customer.arrivalTime << std::endl;
		break;
	case end:
		std::cout << "service close";
		std::cout << ", arrival time-" << customer.arrivalTime
			<< ", start time-" << customer.startTime
			<< ", wait time-" << customer.startTime - customer.arrivalTime
			<< ", service time-" << customer.endTime - customer.startTime
			<< std::endl;
		break;
	}
}

void Simlinkedqueue::printWaitQueueStatus(int currentTime)
{
	std::cout << currentTime << ", 현재 대기 고객 수" << currentElementCount << std::endl;
}

void Simlinkedqueue::printReport(int serviceUserCount, int totalWaitTime)
{
	std::cout << "REPORT\n";
	std::cout << "service user count : " << serviceUserCount << std::endl;
	if (serviceUserCount > 0)
	{
		std::cout << "average waiting time : "
			<< (float)totalWaitTime / (float)serviceUserCount
			<< std::endl;
	}
	std::cout << "current customer count : " << currentElementCount << std::endl;
}
