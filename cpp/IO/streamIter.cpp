#include<iostream>
#include<algorithm>
#include<iterator>
#include<string>
#include<vector>
using namespace std;
int main(void)
{
				istream_iterator<string> is(cin);
				istream_iterator<string> eof;
				
				vector<string> text;
				//用到iterator中的特性，动态插入
				//将标准输入的内容插入到text中
				copy(is,eof,back_inserter(text));
				sort(text.begin(),text.end());
				//标准输出，并且两个元素以","为分隔符打印
				ostream_iterator<string> os(cout,",");
				copy(text.begin(),text.end(),os);
				return 0;

}
