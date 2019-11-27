#ifndef TRIANGULAR_H_
#define TRIANGULAR_H_

#include<vector>

class Triangular_iterator{
public:
    Triangular_iterator(int index){
        this->index=index;
    }
    bool operator ==(const Triangular_iterator& )const;
    bool operator !=(const Triangular_iterator& )const;
    Triangular_iterator& operator =(int val);
    int operator *() const;
    //前置++运算符重载
    Triangular_iterator operator ++();
    //后置++重载,靠(int)与前置++作区别
    Triangular_iterator operator ++(int);
    void check_integrity() const;
private:
    int index;
};

class Triangular{
    //生明Triangular_iterator两个函数具有访问私有变量的能力
    //friend可以声明整个类或者逐个函数
    friend class Triangular_iterator;
    friend std::ostream& operator <<(std::ostream &os,Triangular &rhs);
    //friend int Triangular_iterator::operator *() const;
    //friend void Triangular_iterator::check_integrity() const;
    private:
        int length;
        int beg_pos;
        static int max_elems;
        static std::vector<int> elems;
    public:
        //copy constructor
        Triangular(Triangular& tri);
        Triangular(int len=1,int bp=0);
        int get_length()const {return length;}
        typedef Triangular_iterator iterator;
        Triangular_iterator begin()const
        {
                        return Triangular_iterator(beg_pos);
        }
        Triangular_iterator end() const
        {
                        return Triangular_iterator(beg_pos+length);
        }

};
inline bool Triangular_iterator::operator ==(const Triangular_iterator& rhs)const
{
    return this->index==rhs.index;
}

inline bool Triangular_iterator::operator !=(const Triangular_iterator& rhs)const
{
    return !(*this==rhs);
}

inline int Triangular_iterator::operator *()const
{
    check_integrity();

    return Triangular::elems[index];
}

inline void Triangular_iterator::check_integrity() const
{
    if(index >= Triangular::max_elems){
        std::cout<<"index超出了max_elems"<<std::endl;
    }
    //扩展vector容量
}

inline Triangular_iterator Triangular_iterator::operator ++()
{
    ++index;
    check_integrity();
    return *this;
}
//++后置重载运算符
inline Triangular_iterator Triangular_iterator::operator ++(int)
{
    return ++(*this);
}
//在头文件中声明inline或者在cpp文件中声明为普通函数，都可以
inline Triangular_iterator& Triangular_iterator::operator =(int val)
{
    Triangular::elems[this->index]=val;
    return *this;
}
#endif
