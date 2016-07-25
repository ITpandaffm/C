//
//  main.c
//  找素数
//
//  Created by ffm on 15-2-2.
//  Copyright (c) 2015年 ffm. All rights reserved.
//在控制台输出0到100万之间的所有素数
//7.10优化
/*
 使用sqrt()开平方运算来缩小运算范围
 当一个数不能被刚好开方的时候，那么就会得到比这个数小的最大的能开方的数的开方
 如： 82，83，84，到99 的sqrt()运算都是返回9 （因为包含81，
 一个数 n 如果是合数，那么它的所有的因子不超过sqrt(n)--n的开方
 
 同时直接略过偶数
 
 7.10二次更新，修复了错误，（通过if直接略过偶数不用进入isPrime()中判断就减少了开方运算的开销）
 
 7.11凌晨 第三次更新 （希望是最后一次了。😂） 在去偶数判断的时候别遗漏了最小的素数2 同时注意了一下代码规范，整洁性。
 **if的括号还是不要省为妙 苹果在2014年2月 SSL/TLS 发现了知名的goto fail错误 就是省略了if的花括号的问题
 */
#include <stdio.h>
#include <math.h>

int isPrime (int i) {
    for (int j = 3; j <= sqrt(i); j++) {
        if ( i%j == 0) {
           return 1;
        }
    }
    return 0;
}

int main()
{
    for (int i = 2; i <= 1000000; i++) {
        if ( i%2 == 0 && i != 2) {
            continue;                   //偶数直接略过，开始新一轮
        }
        if ( isPrime(i) == 0) {
            printf("%d\n",i);
        }
    }
    return 0;
}





/*
 版本1.0效率太低
 效率太低 舍弃
 */

//    int m, n;
//    for(m=3; m<=1000000; m++){
//        for(n=2; n<m; n++){
//            if(m%n == 0)       //什么条件下跳出当前循环
//             break;                 //这里应该退出当前循环了
//            }
//            if(m == n)   //n循环结束后，如果m=n的话就输出m
//            printf("%d  ",m);
//    }
