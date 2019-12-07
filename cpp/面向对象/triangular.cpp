#include<iostream>
#include "triangular.h"

//静态成员,在类实现文件中使用，需要提前声明一下
std::vector < int >Triangular::array;

//拷贝构造函数，用在Class b=a;场景，把动态分配的内容也做重新分配
Triangular::Triangular(Triangular & tri)
:  length(tri.length), beg_pos(tri.beg_pos)
{
    //array=new int[tri.length];
    //for(int i=0;i<tri.length;i++)
    //                              array[i]=tri.array[i];
}

//在类函数中使用static成员，像正常类成员一样使用
Triangular::Triangular(int len, int bp):length(len > 0 ? len : 1),
beg_pos(bp)
{
    //array=new int[len];
    std::cout << "len: " << len << ",bp:" << bp << std::endl;
    //访问static成员，也像一般成员一样访问即可
    if (array.size() < bp + len)
	for (int i = 0; i < bp + len - array.size(); i++)
	    array.push_back(0);
}

void Triangular::tranverse()
{
    std::cout << "static tranverse function";
    std::cout << std::endl;
}
