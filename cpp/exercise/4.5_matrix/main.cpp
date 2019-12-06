#include "matrix.h"
int main(void)
{
				matrix m;
				int nums[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
				matrix m2(nums);
				std::cout<<m;
				std::cout<<m2;
				matrix tmp=m+m2;
				std::cout<<"m+m2"<<std::endl;
				std::cout<<tmp;
				matrix tmp2= m*m2;
				std::cout<<"m * m2\n"<<tmp2<<std::endl;
				m += m2;
				std::cout<<"m+=m2\n"<<m<<std::endl;
				std::cout<<"m矩阵的(3,3)元素是:"<<m(3,3)<<std::endl;
				return 0;
}
