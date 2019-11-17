#include<iostream>
#include<vector>

template <typename T>
void traverse(const std::vector<T> &vec)
{
				typename std::vector<T>::const_iterator iter;
				for(iter=vec.begin();iter<vec.end();iter++){
								std::cout<<*iter<<",";
				}
				std::cout<<std::endl;
}
int main(void)
{
		int seq_size=5;
		//初始化一个固定大小
		std::vector<int> pell_seq(seq_size);
		for(int i=0;i<seq_size;i++)
						pell_seq[i]=i*2;
		traverse(pell_seq);
		//初始化固定大小，全部给同一个值
		std::vector<std::string> svec(5,"hello");
		traverse(svec);
		//根据某个容器，产生新容器
		std::vector<std::string> svec2(svec);
		svec2[0]="world";
		traverse(svec);
		traverse(svec2);

		//第二种初始化vector的方式
		int elem_vals[seq_size]={1,2,3,4,5};
		std::vector<int> elem_seq(elem_vals,elem_vals+seq_size);
		//弹出最后一个元素
		elem_seq.pop_back();
		traverse(elem_seq);
		return 0;
}
