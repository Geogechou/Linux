/**
*重载(),作为function Object，传入泛型算法中使用
*/
#ifndef LESSTHAN_H_
#define LESSTHAN_H_
class LessThan{
    public:
		  LessThan(int v):val(v) {}
			//读取
			int comp_val() const {return val;}
			//写入
			void comp_val(int v){val=v;}
			//重载了()运算符,实现function Object
			bool operator()(int v) const;
		private:
		  int val;
};

inline bool LessThan::operator()(int v) const
{
    return v < this->val;
}

#endif
