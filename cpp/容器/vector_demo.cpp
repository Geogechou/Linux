#include<iostream>
#include<vector>

int main(void)
{
		int seq_size=5;
		std::vector<int> pell_seq(seq_size);
		for(int i=0;i<seq_size;i++)
						pell_seq[i]=i*2;
		for(int t:pell_seq)
						std::cout<<t<<" ,";
		std::cout<<"\n";
		//第二种初始化vector的方式
		int elem_vals[seq_size]={1,2,3,4,5};
		std::vector<int> elem_seq(elem_vals,elem_vals+seq_size);

		for(int i=0;i<elem_seq.size();i++)
						std::cout<<elem_seq[i]<<" ,";
		return 0;
}
