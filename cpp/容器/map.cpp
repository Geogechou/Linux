#include<iostream>
#include<map>
#include<string>
using std::map;
using std::string;
using std::cout;
using std::endl;

int main(void)
{
				map<string,int> words;
				words["hello"]=1;
				words["world"]=2;
				map<string,int>::iterator it=words.begin();
				for(;it!=words.end();it++){
								cout<<it->first<<":"<<it->second<<endl;
				}
				string key="world";
				it=words.find(key);
				if(it!=words.end()){
								cout<<"find "<<key<<":"<<it->second<<endl;
				}else
					cout<<key<<" doesn't exist"<<endl;
				return 0;				
}
