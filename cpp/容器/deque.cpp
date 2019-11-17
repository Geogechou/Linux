#include<iostream>
#include<deque>

void traverse(const std::deque<int> &line)
{
				//if(line==NULL) return ;
				std::deque<int>::const_iterator iter=line.begin();
				for(;iter<line.end();iter++)
								std::cout<<*iter<<",";
				std::cout<<std::endl;
}
int main(void)
{
				
				std::deque<int> line;
				line.push_back(1);
				line.push_back(2);
				line.push_back(3);
				int front=line.front();
				std::cout<<"the first element is:"<<front<<std::endl;
				line.pop_front();
				traverse(line);
				//insert函数
				std::deque<int>::iterator  iter=line.begin();
				//容器通用的insert(iterator iter,value)方法
				line.insert(iter,10);
				traverse(line);

				return 0;				
}
