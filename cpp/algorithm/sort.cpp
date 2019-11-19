#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
void traverse(std::vector<int>& vec)
{
		for(int t:vec)
						std::cout<<t<<" ";
		std::cout<<std::endl;
				
}
int main(void)
{
		int data[]={10,9,23,24,10};
		std::vector<int> nums(data,data+5);
		sort(nums.begin(),nums.end());
		traverse(nums);
		//第三个参数，传递给一个function object,是标准库预定义的
		//按照逆序排序，默认sort第三个参数相当于是 less<>

		sort(nums.begin(),nums.end(),std::greater<int>());
		traverse(nums);
		return 0;
}
