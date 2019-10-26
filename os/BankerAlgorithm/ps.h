//
// Created by george on 2019/10/26.
//

#ifndef BANKER_PS_H
#define BANKER_PS_H

#include <stdbool.h>

typedef struct process{
    //alloc为已分派, need为总需求,mark为算法遍历时访问标志,pid为进程标志
    int alloc;
    int max;
    bool mark;
    int pid;

}ps;

ps ps_init(int alloc,int max,int pid);

bool alloc(ps process[],int len,int curr,int req,int total);

#endif //BANKER_PS_H
