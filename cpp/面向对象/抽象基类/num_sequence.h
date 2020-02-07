#ifndef NUM_SEQUENCE_H_
#define NUM_SEQUENCE_H_

#include <iostream>
class num_sequence{
	public:
		//凡基类有一个(多个)虚函数，应该将destructor声明未virtual
		virtual ~num_sequence(){};
		//虚函数与纯虚函数的区别在于，纯虚函数的类无法生成实例，虚函数的方法要求实现
		virtual int elem(int pos) const=0;
		virtual const char* what_am_i() const=0;
		virtual std::ostream& print(std::ostream & os=std::cout) const=0;
		//static函数无法声明为虚函数
		static int max_elems() {return _max_elems;}
	protected:
		virtual void gen_elems(int pos) const=0;
		bool check_integrity(int pos,int size) const;
		const static int _max_elems = 1024;
};

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
