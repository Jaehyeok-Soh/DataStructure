#pragma once

//Expression
//Postfix Notation

enum Precedence
{
	/// <summary>
	/// (
	/// </summary>
	lparen,

	/// <summary>
	/// )
	/// </summary>
	rparen,
	times,
	divide,
	plus,
	minus,
	operand
};

/// <summary>
/// LinkedStack
/// </summary>
struct ExprToken
{
	float value;
	Precedence type;
};