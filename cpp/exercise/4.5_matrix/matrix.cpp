#include "matrix.h"
#include<iostream>
using namespace std;

matrix::matrix(int r1,int r2,int r3,int r4)
{
				for(int i=0;i<4;i++){
								array[0][i]=r1;
								array[1][i]=r2;
								array[2][i]=r3;
								array[3][i]=r4;
				}
}

matrix::matrix(int nums[])
{
				for(int i=0;i<4;i++){
								array[0][i]=nums[i];
								array[1][i]=nums[4+i];
								array[2][i]=nums[8+i];
								array[3][i]=nums[12+i];
				}
}
matrix matrix::operator+ (matrix& m2)
{
				matrix res;
				for(int i=0;i<16;i++)
					res.array[i/4][i%4]=this->array[i/4][i%4] + m2.array[i/4][i%4];
				return res;

}
matrix& matrix::operator+=(matrix& m2)
{
				matrix res;
				res = *this + m2;
				for(int i=0;i<16;i++)
								this->array[i/4][i%4]=res.array[i/4][i%4];
				return *this;
}
matrix matrix::operator * (matrix& m2)
{
				matrix res;
				int p=4;
				for(int i=0;i<16;i++){
								int row=i/4;
								int col=i%4;
								int sum=0;
								for(int j=0;j<p;j++){
												sum += array[row][j]*m2.array[j][col];
								}
								res.array[row][col] = sum;
				}
				return res;
}
int matrix::operator() (int row,int col)
{
				if(row<4 && col<4)
								return this->array[row][col];
				else
								return -1;
}
ostream&  operator<< (ostream& out,matrix& mat) 
{
				out<<"---------------------\n";
				for(int i=0;i<16;i++){
								if(i%4==0 && i>0)
												out<<"\n";
								out<<mat.array[i/4][i%4]<<",";
				}
				out<<endl;
				out<<"---------------------\n";
}
