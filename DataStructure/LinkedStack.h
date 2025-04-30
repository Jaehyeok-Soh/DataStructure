#pragma once
#include "Exprdef.h"
#include "MapDef.h"

/// <summary>
/// TODO: To template
/// 2025 04 29
/// </summary>
class StackNode
{
public :
	StackNode* next;

	virtual StackNode* Clone() const = 0;
	StackNode();
	virtual ~StackNode();

	virtual char getCharData() const = 0;
	virtual ExprToken getExprData() const = 0;
	virtual MapPosition getMapData() const = 0;
};

class CharStackNode : public StackNode
{
public :
	char data;

	virtual CharStackNode* Clone() const override;
	CharStackNode() = default;
	CharStackNode(char _cData);
	~CharStackNode();

	virtual char getCharData() const override;
	virtual ExprToken getExprData() const override;
	virtual MapPosition getMapData() const override;
};

class MapStackNode : public StackNode
{
public:
	MapPosition data;

	virtual StackNode* Clone() const override;
	MapStackNode();
	~MapStackNode();

	virtual char getCharData() const override;
	virtual ExprToken getExprData() const override;
	virtual MapPosition getMapData() const override;
};

class ExprStackNode : public StackNode
{
public:
	ExprToken data;

	virtual ExprStackNode* Clone() const override;
	ExprStackNode() = default;
	ExprStackNode(ExprToken _eData);
	~ExprStackNode();

	virtual char getCharData() const override;
	virtual ExprToken getExprData() const override;
	virtual MapPosition getMapData() const override;
};


class LinkedStack
{
public :
	int currentElementCount;
	StackNode* pTopElement;

	LinkedStack();
	~LinkedStack();

	bool pushLS(StackNode& element);
	StackNode* popLS();
	StackNode* peekLS();
	void deleteLinkedStack();
	bool isLinkedStackFull();
	bool isLinkedStackEmpty();
	void displayLinkedStack();

	//StackUtil
	char* reverseString(char* pSource);
	bool checkBracketMatching(char* pSource);

	//Expression
	void calcExpr(ExprToken* pExprTokens, int tokenCount);
	bool pushLSExprToken(ExprToken data);
	void convertInfexToPostFix(ExprToken* pExprTokens, int tokenCount);
	int inStackPrecedence(Precedence oper);
	int outStackPrecedence(Precedence oper);
	void printToken(ExprToken element);

	//map
	void findPath(int mazeArray[HEIGHT][WIDTH],	MapPosition startPos, MapPosition endPos);
	bool pushLSMapPosition(MapPosition data);
	void showPath(int mazeArray[HEIGHT][WIDTH]);
	void printMaze(int mazeArray[HEIGHT][WIDTH]);
};