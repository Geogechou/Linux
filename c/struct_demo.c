#include "pch.h"
/*
*
*使用结构体计算复数，复数可以用极坐标或者直角坐标系来表达
*用枚举量来定义是直角坐标还是极坐标
*/
#include <stdio.h>
#include<math.h>
enum coordinate_type {RECTANGULAR,POLAR};
struct struct_complex {
	enum coordinate_type t;
	double a;
	double b;
};
void print_struct_complex(struct struct_complex c) {
	printf("x=%f,y=%f\n", c.a, c.b);
}
struct struct_complex from_polar_to_rect(struct struct_complex c) {
	double x = c.a*cos(c.b);
	double y = c.a*sin(c.b);
	struct struct_complex temp;
	temp.a = x;
	temp.b = y;
	temp.t = RECTANGULAR;
	return temp;
}
struct struct_complex plus(struct struct_complex c1, struct struct_complex c2) {
	if (c1.t == 1)
		c1 = from_polar_to_rect(c1);
	if (c2.t == 1)
		c2 = from_polar_to_rect(c2);
	struct struct_complex temp;
	temp.a = c1.a + c2.a;
	temp.b = c1.b + c2.b;
	temp.t = RECTANGULAR;
	return temp;
}

struct struct_complex make_from_xy(double x, double y) {
	struct struct_complex temp;
	//用枚举表示直角坐标
	temp.t = RECTANGULAR;
	temp.a = x;
	temp.b = y;
	return temp;
}
struct struct_complex make_from_polar(double r, double angle) {
	struct struct_complex temp;
	temp.t = POLAR;
	temp.a = r;
	temp.b = angle;
	return temp;
}
int main()
{
	struct struct_complex num1 = make_from_xy(1, 2);
	struct struct_complex num2 = make_from_polar(1, acos(-1));
	struct struct_complex sum = plus(num1, num2);
	print_struct_complex(sum);
	return 0;
}
