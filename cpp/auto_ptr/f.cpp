#include <memory>
#include <iostream>
int main()
{
	//使用auto_ptr 必须包含memory头文件, auto_ptr申请的内存会在异常发生时自动释放
	std::auto_ptr<int> p(new int(5));
	std::cout<<*p<<std::endl;
	return 0;
}
