#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
	double dd;
	//convert string to double
	dd=atof("12.3321");
	printf("atof result: %lf\n",dd);
	//float's abs
	double absN=fabs(-100.273);
	printf("fabs = %lf\n",absN);
	//fpow
	double p=pow(2.3,3.5);
	printf("double pow test:%lf\n",p);
	//round(),舍掉小数部分，例如该例子返回13.00
	double r=round(12.56);
	printf("round equal %lf\n",r);
	//ceil(),向上取整
	printf("ceil equal %lf\n",ceil(12.56));
  //floor(),向下取整
	printf("floor equal %lf\n",floor(12.56));
	//fmod() 使用该函数时，要在编译选项时选择-lm，意味链接math动态链接库
	//fmod返回a/b的余数
	printf("fmod(返回除法余数) equal %lf\n",fmod(12,5));
	//double modf(double val,double* ip),val为输入的值，ip为返回的整数部分，函数返回余数部分
	//int_sec是2.00 f_sec为0.78
	double int_sec=0;
	double f_sec=	modf(2.78,&int_sec);
	printf("modf函数,2.78的整数部分是:%lf,小数部分是%lf\n",int_sec,f_sec);
	//科学计数法,只保留两位小数
	double sc_d=123000000;
	printf("科学计数法%.2e\n",sc_d);
	return 0;
}
