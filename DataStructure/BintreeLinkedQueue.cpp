#include "pch.h"
#include "BintreeLinkedQueue.h"

BintreeLinkedQueue::~BintreeLinkedQueue()
{
    deleteLinkedQueue();
}

bool BintreeLinkedQueue::enqueueLQ(BinTreeNode* element)
{
    bool ret = false;
    BintreeLinkedQueueNode* newNode = new BintreeLinkedQueueNode();
    newNode->data = element;

    if (newNode)
    {
        if (pFront == nullptr)
        {
            pFront, pRear = newNode;
        }
        else
        {
            newNode->prev = pRear;
            pRear->next = newNode;
            pRear = newNode;
        }

        currentElementCount++;
        ret = true;
    }

    return ret;
}

BintreeLinkedQueueNode* BintreeLinkedQueue::dequeue()
{
    BintreeLinkedQueueNode* pReturn = nullptr;

    if (currentElementCount != 0)
    {
        pReturn = pFront;
        pFront = pFront->next;
        pFront->prev = nullptr;
        
        pReturn->next = nullptr;

        currentElementCount--;
    }

    return pReturn;
}

void BintreeLinkedQueue::deleteLinkedQueue()
{
    BintreeLinkedQueueNode* current = pFront;
    BintreeLinkedQueueNode* delNode = nullptr;

    while (current != nullptr)
    {
        delNode = current;
        current = current->next;
        SAFE_DELETE(delNode);
    }
}
