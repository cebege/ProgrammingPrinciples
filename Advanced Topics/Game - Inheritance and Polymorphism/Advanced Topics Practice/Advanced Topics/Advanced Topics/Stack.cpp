#pragma once
#include "1. Constructor and Operators.h"
template <typename Type>
class Stack
{
	static const int k_sizestack = 10; // size of stack, for example number of enemies.

	Type m_data[k_sizestack];
	int m_top; // element we have access to.

public:
	Stack()
		: m_top(-1) // indicates it is empty i.e. adding one would mean accessing position 0 within the array 
	{
		memset(m_data, 0, sizeof(Type) * k_sizestack); // sets values to zero
	}

	void Push(Type data)
	{
		++m_top;
		m_data[m_top];
	}

	Type Pop()
	{
		Type value = m_data[m_top]; // accessing the data on the top.
		--m_top; // decrements to the next position
		return value; // returns value
	}
};


int main() {

	Stack<int> intStack;
	intStack.Push(10);
	intStack.Push(20);

	Stack<Point*> pointStack;
	pointStack.Push(new Point(10, 20));
	pointStack.Push(new Point(20, 40));
	pointStack.Pop();

}