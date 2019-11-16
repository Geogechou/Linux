#include<iostream>
int sum(int a,int b)
{
				return a+b;
}
int main(void)
{
				//声明一个函数指针
				int (*func)(int,int);
				//给函数指针赋值
				func=sum;
				//调用函数指针
				int res=func(1,2);
				std::cout<<"res="<<res<<std::endl;
				return 0;
}
