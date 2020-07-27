#include <stdio.h>
#include "max.h"
#include "min.h"

int main()
{
	int m = max(5,3);
	int n = min(5,3);

	printf("max:%d,min=%d\n",m,n);
	return 0;
}
