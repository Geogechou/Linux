#ifndef _NUM_SEQUENCE_H_
#define _NUM_SEQUENCE_H_

#include<vector>
#include<iostream>
class num_sequence {
  public:
    num_sequence() {
	//std::cout<<"init success"<<std::endl;
    }
    //定义类型,将类成员函数指针定义为PtrType
		typedef void (num_sequence::*PtrType) (int);
    void fibonacci(int);
    void pell(int) {
    }
    void lucas(int) {
    }
    void triangular(int){
		}
    void square(int);
    void pentagonal(int) {
    }
    int get_elem(int n);
    //设置class函数指针
    void ns_type(int ix);
  private:
    PtrType pmf;
    std::vector < int >elem;
    static const int num_seq = 7;
    static PtrType func_tbl[num_seq];
    //需要注意，不能写成vector<vector<>>,因为>>会被解释为输入运算符
    static std::vector < std::vector < int >>seq;
};

#endif
