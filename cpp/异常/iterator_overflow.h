#ifndef ITERATOR_OVERFLOW_H_
#define ITERATOR_OVERFLOW_H_
#include <exception>
#include <sstream>
#include <iostream>
class iterator_overflow:public std::exception{
	public:
		iterator_overflow(int index,int max):_index(index),_max(max) {}
		virtual const char* what()  const _GLIBCXX_USE_NOEXCEPT
		{
			std::ostringstream ex_msg;
			ex_msg<<"Invalid index "<<_index<<", exceed maxium bound "<<_max<<std::endl;
			//string类转成const char*的一个方法是c_str()
			std::cout<<ex_msg.str().c_str();
			return ex_msg.str().c_str();
		}
	private:
		int _index;
		int _max;
};
/*
const char* iterator_overflow::what() const noexcept
{
}
*/
#endif
