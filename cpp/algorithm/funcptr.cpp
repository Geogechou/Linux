#include<iostream>
#include<vector>
#include<algorithm>

bool less_than(int v1,int v2)
{
				return v1<v2;
}
//返回一个符合比较器的筛选条件的vector，第三个参数是函数指针
std::vector<int> filter_vec(const std::vector<int>&vec,
							int value,bool (*ptr)(int,int)){

					std::vector<int> res;
					for(int i=0;i<vec.size();i++){
									if(ptr(vec[i],value))													
													res.push_back(vec[i]);
					}
					return res;
}
//使用内置的 binder adapter
std::vector<int> filter_vec(const std::vector<int>&vec,int value)
{
				std::vector<int> res;
				std::vector<int>::const_iterator iter=vec.begin();
				//使用find_if(),第三个参数是function object adapter
				//将value绑定在第二个参数上,即it<value
				while((iter=find_if(iter,vec.end(),
									bind2nd(std::less<int>(),value)))!=vec.end())
				{
								res.push_back(*iter);
								iter++;
				}
				return res;
}
void traverse(std::vector<int>& vec)
{
				for(int i=0;i<vec.size();i++)
								std::cout<<vec[i]<<",";
				std::cout<<std::endl;								
}
int main(void)
{
				int nums[]={1,3,4,7,9,22,11,20};
				int size=(int)(sizeof(nums)/sizeof(int));
				std::vector<int> vec(nums,nums+size);
				traverse(vec);
				int threshold=10;
				std::vector<int> res=filter_vec(vec,threshold,less_than);
				traverse(res);
				
				std::vector<int> res2=filter_vec(vec,12);
				traverse(res2);
				return 0;				
}
