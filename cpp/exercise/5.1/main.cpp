#include "LIFO_Stack.h"
#include "Stack.h"
int main()
{
	LIFO_Stack s;
	int num1=1;
	int num2=2;
	s.push(num1);
	s.push(num2);
	std::cout<<s;
	std::cout<<"stack size is:"<<s.size()<<std::endl;
	int top=s.peek();
	std::cout<<"top elem is: "<<top<<std::endl;
	return 0;
}
