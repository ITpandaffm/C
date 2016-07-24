//
//  Array.h
//  DynamicsArray
//
//  Created by ffm on 16/7/11.
//  Copyright © 2016年 ITPanda. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Object.h"

typedef struct Array_ {
    int retainCount_;
    int length_;
    int capacity_;
    void **value_;
} Array;


Array * ArrayCreate();          
int ArrayGetLength (Array *arr);
void ArrayAdd (Array *arr, void *value);
void ArrayInsert (Array *arr, void *value, int index);
void * ArrayGet (Array *arr, int index);
void ArrayDestroy (Array *arr);
void ArrayRemove (Array *arr, int index);


#endif /* Array_h */
