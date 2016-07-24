//
//  Array.c
//  DynamicsArray
//
//  Created by ffm on 16/7/11.
//  Copyright © 2016年 ITPanda. All rights reserved.
//

#include "Array.h"




//根据分配空间分配内存，没有必要对外声明，所以只写在.c文件中（没有在头文件中声明）
static void ** allocMemoryByCapacity (Array *arr) {
    return malloc(sizeof(void *) * arr->capacity_);
}

//创建数组
Array * ArrayCreate () {
    Array *arr = malloc(sizeof(Array));
    arr->length_ = 0;
    arr->capacity_ = 32;
    arr->value_ = allocMemoryByCapacity(arr);
    OBJECT_RETAIN(arr->value_);
    OBJECT_RETAIN(arr);
    return arr;
}

//获取数组长度
int ArrayGetLength (Array *arr) {
    return arr->length_;
}

//数组增加元素
void ArrayAdd (Array *arr, void *value) {
    if (arr->length_>=arr->capacity_) {   //如果数组越界，饱和了则重新分配新的更大的内存，并拷贝内存
        arr->capacity_ *= 2;
        void **oldValues = arr->value_;
        arr->value_ = allocMemoryByCapacity(arr);
        memcpy(arr->value_, oldValues, arr->length_*sizeof(void *));
        free(oldValues);
    }
    arr->value_[arr->length_] = value;
    OBJECT_RETAIN(arr->value_[arr->length_]);
    arr->length_++;

}

//插入元素
void ArrayInsert (Array *arr, void *value, int index) {
    if (arr->length_+1>=arr->capacity_) {   //如果数组越界，饱和了则重新分配新的更大的内存，并拷贝内存 (这里是＋1 ，因为要后移）
        arr->capacity_ *= 2;
        void **oldValues = arr->value_;
        arr->value_ = allocMemoryByCapacity(arr);
        memcpy(arr->value_, oldValues, arr->length_*sizeof(void *));
        free(oldValues);
    }
    for (int i = arr->length_; i>index ; i--) {
        arr->value_[i] = arr->value_[i-1];              //index开始后面元素后移腾出位置
    }
    arr->value_[index] = value;
    OBJECT_RETAIN(arr->value_[index]);
    arr->length_++;
}

//查
void * ArrayGet (Array *arr, int index) {
//    assert(index>=0 && index<arr->length_);    //因为没有异常机制，所以用原始的断言方法
    if (index<0 || index>=arr->length_) {
        printf("所要获得索引越界啦越界啦\n");
    }
    return arr->value_[index];
}

//销毁数组
void ArrayDestroy (Array *arr) {
    //先销毁value，再销毁arr   因为有引用计数 所以交给引用计数去释放！
    for (int i = 0; i <ArrayGetLength(arr); i++) {
        OBJECT_RETAIN_RELEASE(arr->value_[i]);
    }
    OBJECT_RETAIN_RELEASE(arr);
}

//删除元素
void ArrayRemove (Array *arr, int index) {
//    assert(index>=0 && index<=arr->length_);
    if (index<0 || index>=arr->length_) {
        printf("所要获得索引越界啦越界啦\n");
    }
    OBJECT_RETAIN_RELEASE(ArrayGet(arr, index));
    arr->length_--;
    for (int i = index; i<arr->length_; i++) {
        arr->value_[i] = arr->value_[i+1];
    }
}



