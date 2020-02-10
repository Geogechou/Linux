#ifndef NUM_SEQUENCE_H_
#define NUM_SEQUENCE_H_
#include<vector>
#include <iostream>
class num_sequence{
	public:
		//凡基类有一个(多个)虚函数，应该将destructor声明未virtual
		virtual ~num_sequence(){};
		//虚函数与纯虚函数的区别在于，纯虚函数的类无法生成实例，虚函数的方法要求实现
		virtual int elem(int pos) const=0;
		virtual const char* what_am_i() const=0;
		virtual std::ostream& print(std::ostream & os=std::cout) const=0;
		void display(std::ostream &os, int pos);
		int length() const {return _length;}
		int beg_pos() const {return _beg_pos;}
		//static函数无法声明为虚函数
		static int max_elems() {return _max_elems;}
	protected:
		num_sequence(int length,int beg_pos,std::vector<int> *re=0)
			:_length(length),_beg_pos(beg_pos),_relems(re) {}
		virtual void gen_elems(int pos) const=0;
		bool check_integrity(int pos,int size) const;
		const static int _max_elems = 1024;
		int _length;
		int _beg_pos;
		std::vector<int> *_relems;
};
void num_sequence::display(std::ostream& os,int pos)
{
	os<<"The element at position "<<pos<<" for the "<<what_am_i()<<" sequence is: "<<elem(pos)<<std::endl;
}
bool num_sequence::check_integrity(int pos,int size) const
{
	if(pos<0 || pos>_max_elems){
		std::cout<<"invalid position: "<<pos<<std::endl;
		return false;
	}
	if(pos>size)
		gen_elems(pos);
	return true;
}
std::ostream& operator<< (std::ostream& os, const num_sequence & ns)
{
	return ns.print(os);
}

#endif
