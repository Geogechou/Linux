//
// Created by george on 2019/10/26.
//

#include<stdio.h>
#include "ps.h"

ps ps_init(int alloc,int max,int pid) {
    ps p;
    p.alloc = alloc;
    p.max = max;
    p.pid=pid;
    p.mark = false;
    return p;
}
//尝试去分配
bool ps_request(ps p,int n)
{
    if(n > p.max-p.alloc){
        printf("request more than need, deny allocate!");
        return false;
    }
    return true;
}

int psFree(ps p)  {   return p.alloc==p.max ? p.alloc : 0;   }
void psAlloc(ps* p,int alloc){  p->alloc += alloc; }
int getNeed(ps p) {     return p.max-p.alloc;  }
int findMinReq(ps p[],int len)
{
    int minI=-1;
    int tmp=10000;
    for(int i=0;i<len;i++){
        if(!p[i].mark && getNeed(p[i]) < tmp){
            tmp=getNeed(p[i]);
            minI=i;
        }
    }
    if(minI != -1)
        p[minI].mark=true;
    return minI;
}
bool findSafeSequence(ps p[],int len,int total)
{
    int minI=findMinReq(p,len);
    printf("pid(source)-->pid(source)-->...\n");
    while(minI != -1){
        printf("%d(%d)-->",minI,total);
        int need=getNeed(p[minI]);
        bool flag=ps_request(p[minI],need);
        if(flag && need <= total){
            psAlloc(&p[minI],need);
            total -= need;
            total += psFree(p[minI]);
        }else
            return false;
        minI=findMinReq(p,len);
    }
    return true;
}
//分配资源函数,用银行家算法检测是否可以进行分配
//process[]为进程数组,len为数组长度,curr为当前请求资源的进程,req为请求的数量，total为剩余的资源数量
bool alloc(ps process[],int len,int curr,int req,int total)
{
    bool legal=ps_request(process[curr],req);
    if(!legal)
        return false;
    psAlloc(&process[curr],req);
    total -= req;
    return findSafeSequence(process,len,total);
}