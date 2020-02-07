#ifndef FIBONACCI_H_
#define FIBONACCI_H_
#include <vector>
#include "num_sequence.h"
class fibonacci: public num_sequence{
	public:
		fibonacci(int len=1,int beg_pos=1):_length(len),_beg_pos(beg_pos){}
		virtual const char* what_am_i() const{ return "fibonacci";}
		virtual int elem(int pos) const;
		virtual std::ostream& print(std::ostream &os=std::cout) const;
		//新增方法
		int length() const {return _length;}
		int beg_pos() const {return _beg_pos;}
	
	protected:
		virtual void gen_elems(int pos) const;
		int _length;
		int _beg_pos;
		static std::vector<int> _elems;
};

//静态变量要提前声明，否则编译要报错undefine
std::vector<int> fibonacci::_elems;

int fibonacci::elem(int pos) const
{
	if(!check_integrity(pos, _elems.size()))
		return 0;
	if(pos >= _elems.size())
		fibonacci::gen_elems(pos);//在编译时完成解析，不用多态
	return _elems[pos];
}
void fibonacci::gen_elems(int pos) const
{
	if(_elems.empty()){
		_elems.push_back(1);
		_elems.push_back(1);
	}
	if(_elems.size()<=pos){
		int ix = _elems.size();
		int n2=_elems[ix-2];
		int n1=_elems[ix-1];
		for(;ix<=pos;++ix){
			int el=n2+n1;
			_elems.push_back(el);
			n2=n1;
			n1=el;
		}
	}
}

std::ostream& fibonacci::print(std::ostream& os) const
{
	int elem_pos=_beg_pos-1;
	int end_pos=elem_pos+_length;
	if(end_pos > _elems.size()){
		fibonacci::gen_elems(end_pos);
	}
	while(elem_pos < end_pos){
		os<<_elems[elem_pos++]<<" ";
	}
	os<<std::endl;
	return os;
}

/*
bool fibonacci::check_integrity(int pos) const
{
	if(!num_sequence::check_integrity(pos))
		return false;
	if(pos>_elems.size())
		fibonacci::gen_elems(pos);
	return true;
}
*/

#endif

