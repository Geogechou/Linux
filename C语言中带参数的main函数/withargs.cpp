#include<stdlib.h>
#include<stdio.h>
int main(int argc,char**argv,char** envp){
        //	int a=argc<2?0:atoi(argv[1]);
	printf("argc is:%d\n",argc);
	int i=0;
	while(argv[i++])
	printf("%d-th arg is: %s\n",i,argv[i]);
	i=0;
	while(envp[i++])
	printf("%d-th env arg is: %s\n",i,envp[i]);
	return 0;
}
