#include<iostream>
#include<set>

int main(void)
{
			//set默认是按照less-than来排序
			int a[]={1,3,5,8,5,3,1,8,7};
			std::set<int> nums(a,a+9);
			//直接插入
			nums.insert(10);
			int vals[]={100,101,102};
			//范围插入
			nums.insert(vals,vals+3);
			std::set<int>::iterator it=nums.begin();
			for(;it!=nums.end();it++)
							std::cout<<*it<<",";
			std::cout<<std::endl;
			return 0;				
}
