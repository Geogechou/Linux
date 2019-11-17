#include<iostream>
#include<list>
#include<algorithm>
#include<stdio.h>
void traverse(const std::list<int>& line)
{
				std::list<int>::const_iterator iter=line.begin();
				//因为list是链表，所以没有<或者>的比较方法，只能用!=方法比较
				for(;iter!=line.end() ;iter++)
								std::cout<<*iter<<",";
				std::cout<<std::endl;
}
int main(void)
{

				int size=5;
				int arr[]={1,2,3,4,5};
				std::list<int> line(arr,arr+size);
				traverse(line);
				std::list<int>::iterator iter= find(line.begin(),line.end(),3);
				//insert(iter,count,value),在iter位置插入count个value
				line.insert(iter,5,3);
				traverse(line);
				
				line.erase(iter);
				traverse(line);
				//earse(iter1,iter2),删除[iter1,iter2)的元素
				iter=find(line.begin(),line.end(),3);
				std::list<int>::iterator iter2= find(line.begin(),line.end(),4);
				line.erase(iter,iter2);
				traverse(line);
				return 0;

}
