#include<stdio.h>
#include "stack.h"

int main(void)
{
		push('a');
		push('b');
		push('c');
		printf("abc\n");
		while(!is_empty())
			putchar(pop());
		putchar('\n');
		return 0;
}
