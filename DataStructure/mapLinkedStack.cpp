#include "pch.h"
#include "LinkedStack.h"

StackNode* MapStackNode::Clone() const
{
    return new MapStackNode(*this);
}

MapStackNode::MapStackNode()
{
    data = { 0, };
}

MapStackNode::~MapStackNode()
{
}

MapPosition MapStackNode::getMapData() const
{
    return data;
}

char MapStackNode::getCharData() const
{
    return 0;
}

ExprToken MapStackNode::getExprData() const
{
    return ExprToken();
}

void LinkedStack::findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos)
{
    MapStackNode* pNode = nullptr;
    bool isEmpty = false, isFound = false;
    int markArray[HEIGHT][WIDTH] = { 0, };

    MapPosition newPosition = startPos;
    newPosition.direction = 0;
    pushLSMapPosition(newPosition);

    while (!isEmpty && !isFound)
    {
        pNode = dynamic_cast<MapStackNode*>(popLS());

        if (pNode)
        {
            int x = pNode->getMapData().x;
            int y = pNode->getMapData().y;
            int direction = pNode->getMapData().direction;

            while (!isFound && direction < NUM_DIRECTIONS)
            {
                int newX = x + DIRECTION_OFFSETS[direction][0];
                int newY = y + DIRECTION_OFFSETS[direction][1];

                if (newX >= 0 && newX < WIDTH
                    && newY >= 0 && newY < HEIGHT
                    && mazeArray[newY][newX] == NOT_VISIT
                    && markArray[newY][newX] == NOT_VISIT)
                {
                    MapPosition newPosition;
                    newPosition.x = x;
                    newPosition.y = y;
                    newPosition.direction = direction + 1;
                    pushLSMapPosition(newPosition);
                    markArray[y][x] = VISIT;

                    x = newX;
                    y = newY;
                    direction = 0;

                    if (newX == endPos.x && newY == endPos.y)
                    {
                        isFound = true;
                        newPosition.x = newX;
                        newPosition.y = newY;
                        newPosition.direction = 0;
                        pushLSMapPosition(newPosition);
                        markArray[newY][newX] = VISIT;
                    }
                }
                else
                {
                    direction++;
                }
            }
            SAFE_DELETE(pNode);
        }
        isEmpty = isLinkedStackEmpty();
    }
}

bool LinkedStack::pushLSMapPosition(MapPosition data)
{
    MapStackNode node;
    node.data = data;

    return pushLS(node);
}

void LinkedStack::showPath(int mazeArray[HEIGHT][WIDTH])
{
    StackNode* pNode = nullptr;
    int resultArray[HEIGHT][WIDTH] = { 0, };
    bool isEmpty = false;

    for (auto i = 0; i < HEIGHT; i++)
    {
        for (auto j = 0; j < WIDTH; j++)
        {
            resultArray[i][j] = mazeArray[i][j];
        }
    }

    int i(0);
    while (!isEmpty)
    {
        pNode = popLS();
        if (pNode)
        {
            int x = pNode->getMapData().x;
            int y = pNode->getMapData().y;
            resultArray[y][x] = VISIT;
            if (i > 0)
            {
                std::cout << "<-";
            }
            std::cout << "{" << x << ", " << y << "}";
            i++;
            SAFE_DELETE(pNode);
        }
        isEmpty = isLinkedStackEmpty();
    }
    std::cout << std::endl;
    printMaze(resultArray);

    
}

void LinkedStack::printMaze(int mazeArray[HEIGHT][WIDTH])
{

    for (auto i = 0; i < HEIGHT; i++)
    {
        for (auto j = 0; j < WIDTH; j++)
        {
            if (mazeArray[i][j] == WALL)
            {
                std::cout << '*';
            }
            else if (mazeArray[i][j] == VISIT)
            {
                std::cout << '.';
            }
            else
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}