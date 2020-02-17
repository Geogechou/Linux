#ifndef LIFO_STACK_H_
#define LIFO_STACK_H
#include "Stack.h"
#include <stack>
#include <iostream>
class LIFO_Stack:public Stack{
	public:
		void pop();
		void push(int& elem);
		int size() const;
		bool empty() const;
		bool full() const { return false;}
		int peek() const { return s.top(); }
		void print() const;
	private:
		std::stack<int> s;
};
void LIFO_Stack::print() const
{
	std::cout<<"stack doesn't support print() method!";
	std::cout<<std::endl;
}
void LIFO_Stack::pop()
{
	s.pop();
}

void LIFO_Stack::push(int& elem)
{
	s.push(elem);
}
int LIFO_Stack::size() const
{
	return s.size();
}
bool LIFO_Stack::empty() const
{
	return s.empty();
}

#endif
