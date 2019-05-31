#include <stdlib.h>
#include<stdio.h>
#define JAVA_HOME "/usr/local/java"

int main(void)
{
	const char* java_home;
	java_home=getenv("JAVA_HOME");
	if(java_home==NULL)
		java_home=JAVA_HOME;
	
	printf("java home is:[%s]\n",java_home);
	return 0;
}
