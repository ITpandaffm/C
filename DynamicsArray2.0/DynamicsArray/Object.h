//
//  Object.h
//  DynamicsArray
//
//  Created by ffm on 16/7/11.
//  Copyright © 2016年 ITPanda. All rights reserved.
//

#ifndef Object_h
#define Object_h

#include <stdio.h>
#include <stdlib.h>


#define OBJECT_RETAIN(obj) ObjectRetain ((Object *)obj)
#define OBJECT_RETAIN_RELEASE(obj) ObjectRelease ((Object *)obj)
#define OBJECT_RETAIN_COUNT(obj) ObjectRetainCount ((Object *)obj)

typedef struct Object_ {
    int retainCount_;
} Object;

void ObjectRetain (Object *obj);
void ObjectRelease (Object *obj);
int ObjectRetainCount (Object *obj);




#endif /* Object_h */
