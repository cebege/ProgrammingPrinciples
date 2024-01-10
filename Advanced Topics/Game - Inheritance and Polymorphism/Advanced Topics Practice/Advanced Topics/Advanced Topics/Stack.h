#pragma once
template <typename Type>
class Stack
{
	static const int k_sizestack = 10;

	Type m_data[k_sizestack];
	int m_top;

public:
	Stack()
		: m_top(-1)
	{
		memset(m_data, 0, sizeof(Type) * k_sizestack);
	}

	void Push(Type data)
	{
		++m_top;
		m_data[m_top];
	}

	Type Pop()
	{
		Type value = m_data[m_top];
		--m_top;
		return value;

	}



};