#include "num_sequence.h"
#include "fibonacci.h"

int main(void)
{
	fibonacci fib(10);
	std::cout<<fib;
	fibonacci fib2(5,11);
	std::cout<<fib2;
	return 0;
}
