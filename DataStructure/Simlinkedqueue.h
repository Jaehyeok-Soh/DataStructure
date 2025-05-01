#pragma once
#include "simdef.h"

class QueueNode
{
public:
	SimCustomer data;
	QueueNode* next = nullptr;;

	QueueNode();
	QueueNode(SimCustomer data);
	~QueueNode();
};

class Simlinkedqueue
{
public:
	int currentElementCount;
	QueueNode* pFront;
	QueueNode* pRear;

	Simlinkedqueue();
	~Simlinkedqueue();

	bool enqueueLQ(QueueNode element);
	QueueNode* dequeueLQ();
	QueueNode* peekLQ();
	void deleteLinkedQueue();
	bool isLinkedQueueFull();
	bool isLinkedQueueEmpty();

	void displayLinkedQueue();

	//�� ���� ť�� �� �߰�
	void insertCustomer(int arrivalTime, int serviceTime);
	//�� ���� ó��
	void processArrival(int currentTime, Simlinkedqueue* pWaitQueue);
	//���� ���� ó��
	QueueNode* processServiceNodeStart(int currentTime, Simlinkedqueue* pWaitQueue);
	//���� ���� ó��
	QueueNode* processServiceNodeEnd(int currentTime, QueueNode* pServiceNode, int* pServiceUserCount, int* pTotalWaitTime);
	//���� ���¸� ���
	void printSimCustomer(int currentTime, SimCustomer customer);
	//��� ���� ���¸� ���
	void printWaitQueueStatus(int currentTime);
	//���� �ùķ��̼� ���(���ġ) ���
	void printReport(int serviceUserCount, int totalWaitTime);
};