#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(void){
   char buf[100];
   int num=0;
   const char* tips="please enter the character and will be store in store.txt\n";
   write(STDOUT_FILENO,tips,strlen(tips));
   if((num=read(STDIN_FILENO,buf,20))==-1){
	  printf("read error\n");
	 // perror(-1);
   }else{
     //write to standard output,i.e screen	   
      write(STDOUT_FILENO,buf,num);
      printf("\n");
      //create a file as store.txt, which store from screen input
      //character
      int flag=creat("store.txt",0777);
      if(flag!=-1){
     	 int n1=write(flag,buf,num);
     	 if(n1!=-1)
		  close(flag); 
     	 }
   }
   return 0;
}
