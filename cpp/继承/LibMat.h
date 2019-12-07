#ifndef LIBMAT_H_
#define LIBMAT_H_
#include<iostream>
class LibMat{
				public:
					LibMat(){
									std::cout<<"LibMat::LibMat()\n";
					}
					virtual ~LibMat(){
									std::cout<<"LibMat::~LibMat()\n";
					}
					//加上virtual的作用,其他函数调用LibMat对象时(包括派生类)，使用的是派生类对象
					virtual void print() const{
									std::cout<<"LibMat::print() --I am a LibMat object!\b";
					}
};
void print(const LibMat &mat)
{
				std::cout<<"--------<print>-------\n";
				std::cout<<"in global print(): about to print mat.print()\n";
				mat.print();
				std::cout<<"--------</print>-------\n";
}
#endif
