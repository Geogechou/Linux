#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<string>
using std::cin; using std::cout; using std::endl;
using std::map; using std::set;
using std::string;

int main(int argc,char** argv)
{
				if(argc<2){
								cout<<"参数1：需要统计单词的文件名"<<endl;
								return -1;
				}
				std::ifstream is(argv[1]);
				if(!is){
								cout<<"打开文件失败"<<endl;
								return -1;
				}
				string line;
				string forbid_arr[]={"is","an","a","for","but","the","or","but"};
				int size=sizeof(forbid_arr)/sizeof(string);
				set<string> forbid(forbid_arr,forbid_arr+size);
				map<string,int> dict;
				while(is>>line){
								if(!forbid.count(line))
												dict[line]++;
				}
				map<string,int>::const_iterator it=dict.begin();
				for(;it!=dict.end();it++)
								cout<<it->first<<":"<<it->second<<endl;
				cout<<endl;
				return 0;
}
