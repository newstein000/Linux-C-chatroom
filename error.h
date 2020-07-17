#ifndef __ERROR_H__
#define __ERROR_H__
 
#include<stdio.h>
 
#define SOCKET_INIT			 -1     //初始化套接字失败
#define SOCKET_ACCEPT		 -2		//链接客户端失败
#define CREATE_SQLITE        -3     //打开数据库失败
#define SAVE_SQLITE          -4     //数据库插入数据失败
 
int errno ;

void myerror (char *str);//向屏幕输出错误原因

char * myStrError (void);//保存错误原因
 
#endif
 