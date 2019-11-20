/**
*@function: sort words by their length ascendly, words where input by file
*@date: 2019-11-20/21:52:30
*@Author: george
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//定义的比较函数，用函数指针传给sort函数
bool str_comp(string s1,string s2)
{
				return s1.length()<s2.length();
}
int main(int argc,char** argv)
{
				if(argc<2){
								cout<<"参数1:文件名"<<endl;
								return -1;				
				}
				ifstream is(argv[1]);
				vector<string> bag;
				string words;
				while(is>>words){
								bag.push_back(words);
				}
				bool (*ptr)(string,string)=str_comp;
				sort(bag.begin(),bag.end(),ptr);
				for(string s:bag)
								cout<<s<<",";
				cout<<endl;
}
