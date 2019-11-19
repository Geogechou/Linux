#include<iostream>
#include<vector>
#include<algorithm>

int main(void)
{
	int size=5;
	int nums[]={1,3,5,7,9};
	std::vector<int> vec(nums,nums+size);
	int value=10;
	bool exist=binary_search(vec.begin(),vec.end(),value);
	std::cout<<value<<" exist in vector "<<std::endl;
	std::vector<int>::iterator max=max_element(vec.begin(),vec.end() );
	std::cout<<"the biggest value is "<<*max<<std::endl;

	return 0;				
}
