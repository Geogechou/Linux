#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

int main(int argc,char** argv)
{
				map<string,vector<string>> family;
				string names[]={"alex","fonts","sugar","swite"};
				int size=sizeof(names)/sizeof(string);
				vector<string> vec(names,names+size);
				family["zhou"]=vec;
				map<string,vector<string>>::const_iterator it=family.begin();
				for(;it!=family.end();it++){
								cout<<it->first<<":";
								for(string s:it->second)
												cout<<s<<",";
								cout<<endl;
				}
				return 0;
}
