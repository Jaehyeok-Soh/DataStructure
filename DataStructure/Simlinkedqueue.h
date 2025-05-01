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

	//고객 도착 큐에 고객 추가
	void insertCustomer(int arrivalTime, int serviceTime);
	//고객 도착 처리
	void processArrival(int currentTime, Simlinkedqueue* pWaitQueue);
	//서비스 시작 처리
	QueueNode* processServiceNodeStart(int currentTime, Simlinkedqueue* pWaitQueue);
	//서비스 종료 처리
	QueueNode* processServiceNodeEnd(int currentTime, QueueNode* pServiceNode, int* pServiceUserCount, int* pTotalWaitTime);
	//고객의 상태를 출력
	void printSimCustomer(int currentTime, SimCustomer customer);
	//대기 열의 상태를 출력
	void printWaitQueueStatus(int currentTime);
	//최종 시뮬레이션 결과(통계치) 출력
	void printReport(int serviceUserCount, int totalWaitTime);
};