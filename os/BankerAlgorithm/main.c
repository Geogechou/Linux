//
// Created by george on 2019/10/26.
//

#include <stdio.h>
#include "ps.h"

int main(void)
{
    int source=3;
    ps arr[4];
    arr[0]=ps_init(2,6,0);
    arr[1]=ps_init(2,4,1);
    arr[2]=ps_init(1,3,2);
    arr[3]=ps_init(0,5,3);
    bool success=alloc(arr,sizeof(arr)/sizeof(ps),1,2,source);
    success?printf("\nallocation success!"):
                printf("\nallocation failed!");
    return 0;
}