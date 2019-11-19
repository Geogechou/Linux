/*
*这里用泛型实现，根据比较器类型comp与val值相比
*是否决定将start到end的值插入到start2中
*/
#include<vector>
#include<iostream>
#include<string>
#include<iterator>
#include<algorithm>
template<typename iter,typename outIter,typename comp,typename elemType>
void filter(iter start,iter end,outIter start2,elemType val,comp pred)
{
				while((start=find_if(start,end,bind2nd(pred,val)))!=end){
								*start2=*start;
								start2++;
								start++;
				}
}
void traverse(std::vector<std::string>& svec)
{
				std::cout<<"size:"<<svec.size()<<std::endl;
				//迭代器，vector.begin()返回一个迭代器的指针
				std::vector<std::string>::iterator iter=svec.begin();
				for(;iter!=svec.end();iter++){
						std::cout<<*iter<<",";				
				}
				std::cout<<std::endl;
				
}
int main(void)
{
				int size=5;
				std::string strs[size]={"abc","def","ghi","jkl","kkk"};
				std::vector<std::string> svec(strs,strs+size);
				traverse(svec);

				std::vector<std::string> selects;
				std::string threshold="ggg";
				//其中第三个参数,用了back_inserter可以不用实现分配足够大的空间
				//back_insert函数会把=运算符换成push_back()函数来操作
        //back_insert函数在头文件<iterator>中
				filter(svec.begin(),svec.end(),back_inserter(selects),
						threshold,std::less<std::string>());
				traverse(selects);
				return 0;								
}
