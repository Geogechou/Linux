#include<iostream>
#include<vector>
#include<string>

int main(void)
{
				int size=5;
				std::string strs[size]={"abc","def","ghi","jkl","kkk"};
				std::vector<std::string> svec(strs,strs+size);
				//迭代器，vector.begin()返回一个迭代器的指针
				std::vector<std::string>::iterator iter=svec.begin();
				for(;iter!=svec.end();iter++){
						*iter=*iter+"_connect";
						std::cout<<*iter<<",";				
				}
				std::cout<<std::endl;
				return 0;								
}
