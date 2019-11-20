/**
* 从标准输入一些数字，按照奇数和偶数写入到两个文件中，用copy_if来写入
*/
#include<iostream>
#include<iterator>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
bool is_even(int n){return n%2==0;}
bool is_odd(int n){return n%2==1;}
void traverse(vector<int>& vec)
{
				for(int n:vec)
								cout<<n<<",";
				cout<<endl;

}
int main(void)
{
				vector<int> nums;
				istream_iterator<int> is(cin);
				istream_iterator<int> eof;
				//将标准输入拷贝到vector中
				copy(is,eof,back_inserter(nums));

				ofstream odd("odd.txt");
				ofstream even("even.txt");
				if(!odd.is_open()||!even.is_open()){
								cout<<"打开文件失败"<<endl;
								return -1;
				}
				ostream_iterator<int> os_odd(odd," ");
				ostream_iterator<int> os_even(even,"\n");
				//函数指针
				bool (*evenFunc) (int)=is_even;
				bool (*oddFunc) (int)=is_odd;
				//用copy_if把vector中内容拷贝到文件中
				copy_if(nums.begin(),nums.end(),os_odd,oddFunc);
				copy_if(nums.begin(),nums.end(),os_even,evenFunc);
				traverse(nums);
				cout<<"输出到文件成功"<<endl;
				return 0;
}
