//
//  Element.h
//  DynamicsArray
//
//  Created by ffm on 16/7/11.
//  Copyright © 2016年 ITPanda. All rights reserved.
//

#ifndef Element_h
#define Element_h

#include <stdio.h>
#include <stdlib.h>
#include "Object.h"

typedef struct People_ {
    int retainCount_;         //引用计数一定要放在第一位，不然后面强制转换成Object类型会出错
    char *name_;
    int32_t age_;            //int32_t类型兼容所有平台
} People;

People * PeopleNew (char *name, int32_t age);
char * PeopleGetName (People *people);
int32_t PeopleGetAge (People *people);

#endif /* Element_h */
