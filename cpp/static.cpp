#include<iostream>
#include<vector>
const std::vector<int>* fibon_seq(int n)
{
				if(n<=0||n>1024){
								std::cerr<<"size不合法"<<std::endl;
								return 0;
				}
				static std::vector<int> elems;
				for(int i=elems.size();i<n;i++){
						if(i==0||i==1)
										elems.push_back(1);
						else
										//elems[i]=elems[i-1]+elems[i-2];
									elems.push_back(elems[i-1]+elems[i-2]);
				}
				return &elems;
}
int main(void)
{
		int size=10;
		const std::vector<int>* ptr=fibon_seq(size);
		for(int i=0;i<size;i++)
						std::cout<<(*ptr)[i]<<",";
		std::cout<<std::endl;
		return 0;
}
