#include<iostream>
#include<fstream>

int main(void)
{

		std::fstream iofile("msg.txt",std::ios_base::in|std::ios_base::app);
		if(!iofile){
				std::cerr<<"打开文件失败"<<std::endl;
		}else{
				//调整读入的位置
				iofile.seekg(0);
				std::string s;
				iofile>>s;
				iofile<<"测试iofile"<<std::endl;
				std::cout<<s<<std::endl;
		}
		return 0;
}
