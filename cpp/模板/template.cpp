#include<iostream>
#include<vector>
#include<string>

template<typename T>
void display(const std::vector<T>& vec)
{
				for(int i=0;i<vec.size();i++){
								std::cout<<vec[i]<<",";
				}
				std::cout<<std::endl;
}
int main()
{
				int size=5;
				std::string nums[size]={"abc","def","g","hkl","mac"};
				std::vector<std::string> vec(nums,nums+size);
				display(vec);
				return 0;				
}
