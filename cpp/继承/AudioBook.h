#ifndef AUDIOBOOK_H_
#define AUDIOBOOK_H_
#include "book.h"
class AudioBook:public Book{
				public:
					AudioBook(const std::string &title,
						const std::string &author,const std::string &narr)
					:Book(title,author),narrator(narr)
					{
									std::cout<<"AudioBook::AudioBook()\n";
					}
					~AudioBook(){
									std::cout<<"AudioBook::~AudioBook()\n";
					}
					void print() const{
									std::cout<<"AudioBook::print()\n";
									std::cout<<"title:"<<title
														<<",author:"<<author
														<<",narrator:"<<narrator<<std::endl;
					}
				protected:
					std::string narrator;
};
#endif
