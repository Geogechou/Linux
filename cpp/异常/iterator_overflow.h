#ifndef ITERATOR_OVERFLOW_H_
#define ITERATOR_OVERFLOW_H_
#include <ostream>
	class iterator_overflow{
		public:
			iterator_overflow(int index,int max):_index(index),_max(max) {}
			void printStackTrace(std::ostream & os=std::cerr){
				os<<"Invalid index "<<_index<<", exceed maxium bound "<<_max<<std::endl;
			}
		private:
			int _index;
			int _max;
	};
#endif
