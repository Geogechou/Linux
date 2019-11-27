#include<iostream>
#include<vector>
#include<time.h>
#include "lessthan.h"
using std::vector;
using std::cout; using std::endl;

int count_less_than(const vector<int>&vec,int comp)
{
				LessThan lt(comp);
				int cnt=0;
				for(int tmp:vec){
								if(lt(tmp))
												cnt++;
				}
				return cnt;
}
int main()
{
				vector<int> nums;
				srand(time(0));
				cout<<"less than 10 number is blinking"<<endl;
				for(int i=0;i<20;i++)
								nums.push_back(rand()%20);
				for(int tmp:nums)
								if(tmp<10)
									cout<<"\033[5m"<<tmp<<",";
								else
									cout<<"\033[0m"<<tmp<<",";
				int n=count_less_than(nums,10);
				std::cout<<endl<<"\033[0mless than 10 cnt: "<<n<<endl;
				return 0;
}
