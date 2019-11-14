#include<iostream>
#include<vector>
#include<algorithm>
int main(void)
{
		int data[]={10,9,23,24,10};
		std::vector<int> nums(data,data+5);
		sort(nums.begin(),nums.end());
		for(int t:nums)
						std::cout<<t<<" ";
		std::cout<<std::endl;
		return 0;
}
