#include<iostream>
#include<fstream>
#include<string>

int main(void)
{
				std::ifstream infile("msg.txt");
				if(!infile){
						std::cerr<<"打开文件失败\n";
				}
				std::string s;
				while(infile>>s){
					std::cout<<"读取到的信息是:"<<s;				
					//s/td::cout<<"i"<<std::endl;
				}
				return 0;
}
