#include <iostream>
#include <string>
#include "iterator_overflow.h"

void visit(int pos)
{
	int max=10;
	if(pos > max){
		//所谓异常时某种类，被抛出的异常属于特定的异常类
		throw iterator_overflow(pos,max);
	}
	//可以分情况 throw 出不同的异常
	if(pos > 1024)
		throw "position is too masivie incur bound overflow!";
	if(pos < 0)
		throw -1;
}

int main()
{
	try{
		visit(20);
	}
	catch(iterator_overflow & e){
		e.printStackTrace();
	}
	catch(int eno){
		std::cout<<"error no: "<<eno<<std::endl;
	}
	catch(const char* estr){
		//常量字符串必须用const char*, 不可用string
		std::cout<<"error info: "<<estr<<std::endl;
	}
	return 0;
}
