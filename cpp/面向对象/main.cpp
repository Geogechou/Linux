#include<iostream>
#include "triangular.h"

int main(void)
{

    Triangular t1;
    Triangular t2(3, 0);
    //t2.setValue(0,10);
    //t2.setValue(1,20);
    Triangular t3 = t2;
    //t2.setValue(2,30);
    std::cout << "t2 tranverse\n";
    Triangular::tranverse();
    std::cout << "t3 tranverse\n";
    Triangular::tranverse();
  for (int tmp:Triangular::array)
	std::cout << tmp << ",";
    return 0;
}
