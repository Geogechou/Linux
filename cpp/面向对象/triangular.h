#ifndef TRIANGULAR_H_
#define TRIANGULAR_H_

#include<vector>
class Triangular {
  private:
    int length;
    int beg_pos;
  public:

    static std::vector < int >array;
    //copy constructor
     Triangular(Triangular & tri);
     Triangular(int len = 1, int bp = 1);
    //静态函数
    static void tranverse();
};

#endif
