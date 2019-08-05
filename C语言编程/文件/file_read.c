#include<stdio.h>

void read_file(const char* path)
{
    FILE* file=fopen(path,"rw");
    if(file==NULL){
        printf("open failure\n");
    }
    char buffer[1024];
    char utf[1024];
    while(fgets(buffer,1024,file)){
        printf("%s",buffer);
    }
    fclose(file);
}
int main()
{
	read_file("china.txt");
	return 0;
}

