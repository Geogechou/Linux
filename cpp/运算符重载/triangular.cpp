#include<iostream>
#include "triangular.h"

//在类实现文件中使用，需要提前声明一下
std::vector<int> Triangular::elems;
int Triangular::max_elems=1024;
Triangular::Triangular(Triangular& tri)
			:length(tri.length),beg_pos(tri.beg_pos)
			{
							//elems=new int[tri.length];
							//for(int i=0;i<tri.length;i++)
							//				elems[i]=tri.elems[i];
			}

//在类函数中使用static成员，像正常类成员一样使用
Triangular::Triangular(int len,int bp):length(len>0?len:1),beg_pos(bp)
{
				//elems=new int[len];
				std::cout<<"len: "<<len<<",bp:"<<bp<<std::endl;
				//访问static成员，也像一般成员一样访问即可
				if(elems.size()<bp+len)
				    for(int i=0,size=elems.size();i<bp+len-size;i++)
				        elems.push_back(0);
                for(int i=bp;i<bp+len;i++)
                    elems[i]=i*3;

}
/*
 * 函数写在头文件中会报错，内容是定义多次
 * 原因应该是triangular.cpp文件包含了triangular.h
 * 同时main.cpp也包含了triangular.h，造成了函数的重复定义
 * 解决的方法有生明函数为inline
*/
std::ostream& operator <<(std::ostream &os,Triangular &rhs)
{
    std::cout<<"("<<rhs.beg_pos<<","<<rhs.length<<")"<<std::endl;
    for(int i=rhs.beg_pos;i<rhs.beg_pos+rhs.length;i++)
        std::cout<<Triangular::elems[i]<<",";
    std::cout<<std::endl;
}

