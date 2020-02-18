#ifndef BOOK_H_
#define BOOk_H_
#include<iostream>
#include<string>
#include "LibMat.h"

class Book: public LibMat{
				public:
					Book(const std::string& title_,const std::string &author_)
						:title(title_),author(author_){
										std::cout<<"Book::book()\n";
					}
					virtual ~Book(){
									std::cout<<"Book::~Book()\n";
					}
					void print() const{
									std::cout<<"Book::print(),I'm A book object\n"
										<<"title:"<<title
										<<",author:"<<author<<"\n";
					}
				//proteced关键字修饰的成员，只能在派生类中访问，外界无法访问
				protected:
					std::string title;
					std::string author;
};
#endif
