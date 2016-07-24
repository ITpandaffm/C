//
//  Element.c
//  DynamicsArray
//
//  Created by ffm on 16/7/11.
//  Copyright © 2016年 ITPanda. All rights reserved.
//  此处进行数据的封装

#include "Element.h"

People * PeopleNew (char *name, int32_t age) {
    People *people = malloc(sizeof(People));
    OBJECT_RETAIN(people);
    people->name_ = name;
    people->age_ = age;
    return people;
}

char * PeopleGetName (People *people) {
    return people->name_;
}


int32_t PeopleGetAge (People *people) {
    return people->age_;
}

