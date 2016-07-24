//
//  main.m
//  DynamicsArray
//
//  Created by ffm on 16/7/11.
//  Copyright © 2016年 ITPanda. All rights reserved.

//用C语言实现一个动态数组，
//并对外暴露出对数组的增、删、改、查函数（可以存储任意类型的元素，要求有准确的内存管理）
//实现对数组也进行引用计数
/*
 7.12更新：
 补充了漏掉的查询功能，输入index，可以获取到对应位置上的元素。
 同时舍弃断言功能，改为控制台输出，提高流畅程度。
 */


#import <Foundation/Foundation.h>
#include "Array.h"
#include "Element.h"            //因为这两个头文件都已经引入了Object.h，故无需再导入


void printArr (Array *arr);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Array *arr = ArrayCreate ();
        
        People *p1 = PeopleNew("小明", 20);
        People *p2 = PeopleNew("大明", 21);
        People *p3 = PeopleNew("小李", 22);
        People *p4 = PeopleNew("小张", 24);
        People *p5 = PeopleNew("小🐴", 28);
        People *p6 = PeopleNew("小陈", 29);
        People *p7 = PeopleNew("小蔡", 25);
        People *p8 = PeopleNew("小王", 26);

        ArrayAdd(arr, p1);
        ArrayAdd(arr, p2);
        ArrayAdd(arr, p3);
        ArrayAdd(arr, p4);
        ArrayAdd(arr, p5);
        ArrayAdd(arr, p6);
        ArrayAdd(arr, p7);
        ArrayAdd(arr, p8);

        OBJECT_RETAIN_RELEASE(p1);
        OBJECT_RETAIN_RELEASE(p2);
        OBJECT_RETAIN_RELEASE(p3);
        OBJECT_RETAIN_RELEASE(p4);
        OBJECT_RETAIN_RELEASE(p5);
        OBJECT_RETAIN_RELEASE(p6);
        OBJECT_RETAIN_RELEASE(p7);
        OBJECT_RETAIN_RELEASE(p8);
        
        printArr(arr);
        
        
        printf("把小李删掉再打印一遍\n");
        ArrayRemove (arr, 2);
        printArr (arr);
        
        printf("欢迎老王！\n");
        People *peop = PeopleNew ("老王👳🏽", 50);
        ArrayInsert (arr, peop, 5);
        OBJECT_RETAIN_RELEASE(peop);
        printArr(arr);
        
        printf("你要找第几个人（1～8）？\n");
        int index ;
        scanf("%d", &index);
        People *temp = ArrayGet (arr, index-1);
        
        char *tmpName = PeopleGetName (temp);       //就不考虑输入字母啥的啦，别乱输了吧。。
        int tmpAge = PeopleGetAge (temp);
        printf("第%d个人在第%d个位置上，是%s, 年龄是%d\n",index,index,tmpName,tmpAge);
        
        ArrayDestroy(arr);
        
    }
    return 0;
}


void printArr (Array *arr){
    for (int i = 0 ; i < ArrayGetLength(arr); i++) {
        char *name = PeopleGetName(((People*)ArrayGet(arr,i)));
        int age = PeopleGetAge(((People*)ArrayGet(arr,i)));
        printf("位置：%d, 姓名：%s, 年龄：%d\n", i+1, name, age);
    }
    printf("\n");
}

/*
 本来想利用循环创建感觉很方便，但是不知道为啥 创建完之后这个for执行完毕之后数组中所有元素的name都被改写为与末尾元素同名。。。我也是醉了。没想通是为什么。。。。（在for中创建名字的时候还是正常的 执行完之后整个数组中的元素的name都被统一了。。）
 
 7.12更新补充： 这个是因为＊n指针一直指的是同一块地址。与堆栈的知识有关
 
for (int i = 0; i<8; i++) {
    char name[3] = {};
    for (int j = 0; j<3; j++) {
        name[j] = (char)(65+i);
    }
    char *n = name;
    People *p = PeopleNew(n, 20+i);
    ArrayAdd(arr, p);
    OBJECT_RETAIN_RELEASE(p);
    printf("%s\n",PeopleGetName(((People*)ArrayGet(arr,0))));
}
*/