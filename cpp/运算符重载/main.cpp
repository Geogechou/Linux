#include<iostream>
#include "triangular.h"
int main()
{
    Triangular tri(10,20);
    Triangular::iterator it=tri.begin();
    Triangular::iterator end=tri.end();
    std::cout<<"Triangular series of "<<tri.get_length()<<" elements\n";
    //重新定义=重载，直接复制整数
    it = 1000;
		
    while(it != end){
        std::cout<<*it<<" ";
        ++it;
    }
    std::cout<<std::endl;
    std::cout<<tri;
    return 0;
}
