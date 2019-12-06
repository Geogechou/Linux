#ifndef MATRIX_H_
#define MATRIX_H_
#include<iostream>
class matrix{
				friend std::ostream& operator<< (std::ostream& out,matrix& mat);
				public:
					matrix(int r1=1,int r2=1,int r3=1,int r4=1);
					matrix(int nums[]);
					matrix operator+ (matrix& m2);
					matrix operator* (matrix& m2);
					matrix& operator+=(matrix& m2);
					int operator()(int row,int col);
				private:
					int array[4][4];

};
#endif
