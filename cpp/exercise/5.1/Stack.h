#ifndef STACK_H_
#define STACK_H_
#include<ostream>
class Stack{
	public:
		virtual ~Stack() {};
		virtual void pop() =0;
		virtual void push(int & elem)=0;
		virtual int size() const =0;
		virtual bool empty() const =0;
		virtual bool full() const =0;
		virtual int peek() const =0;
		virtual void print() const=0;
};

std::ostream& operator << (std::ostream& os, const Stack& s)
{
	s.print();
	return os;
}
#endif
