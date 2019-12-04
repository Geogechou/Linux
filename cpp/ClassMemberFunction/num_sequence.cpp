#include<vector>
#include<iostream>
#include "num_sequence.h"

const int num_sequence::num_seq;
std::vector < std::vector < int >>num_sequence::seq(num_seq);

num_sequence::PtrType num_sequence::func_tbl[num_seq] = {
    0,
//类函数前需要用&取地址运算符，普通函数不用
&num_sequence::fibonacci,
	&num_sequence::pell,
	&num_sequence::lucas,
	&num_sequence::triangular,
	&num_sequence::square, &num_sequence::pentagonal};
void num_sequence::fibonacci(int n)
{
    std::cout << "call fib function" << std::endl;
    elem = seq[0];
//std::cout<<elem.size()<<std::endl;
    for (int i = elem.size(); i <= n; i++)
	elem.push_back(0);
    elem[0] = 1;
    elem[1] = 1;
    for (int i = 2; i <= n; i++) {
	elem[i] = elem[i - 1] + elem[i - 2];
    }
//std::cout<<elem[n];
}

void num_sequence::square(int n)
{
	std::cout<<"call triangular function"<<std::endl;
	elem=seq[5];
    for (int i = elem.size(); i <= n; i++)
	elem.push_back(0);
	for(int i=0;i<=n;i++)
					elem[i]=i*i;
}
int num_sequence::get_elem(int pos)
{
    if (pos > elem.size()) {
	//通过class函数指针,调用类函数
	(this->*pmf) (pos);
    }
    return elem[pos];
}

void num_sequence::ns_type(int ix)
{
    if (ix < num_seq)
	pmf = func_tbl[ix];
}
