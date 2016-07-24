//
//  Object.c
//  DynamicsArray
//
//  Created by ffm on 16/7/11.
//  Copyright © 2016年 ITPanda. All rights reserved.
//

#include "Object.h"

void ObjectRetain (Object *obj) {
    obj->retainCount_++;
}

void ObjectRelease (Object *obj) {
    obj->retainCount_--;
    if (obj->retainCount_<=0) {
        free(obj);
        printf("this obj has been freed!\n");
    }
}

int ObjectRetainCount (Object *obj) {
    return obj->retainCount_;
}