#include<iostream>
#include<fstream>
int main(void)
{
				//第二个参数表示追加，如果不加就是覆盖
				std::ofstream outfile("msg.txt",std::ios_base::app);
				if(!outfile)
								std::cerr<<"打开文件失败\n";
				else
								outfile<<"输出一些信息"<<std::endl;
				
				return 0;				
}
