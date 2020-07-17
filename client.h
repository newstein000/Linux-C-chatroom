#ifndef __CLIENT_H__

#define __CLIENT_H__

 

#define PORT 9999 

 

#include <sys/types.h>  //bind、socket、accept函数

#include <sys/socket.h>  //listen、memset函数

#include <string.h>

#include <arpa/inet.h>  //htonl htons 函数

#include <stdio.h>

#include <sys/stat.h>  //文件操作

#include <fcntl.h>		//文件操作



#include <unistd.h>     //文件操作

#include <stdlib.h>
#include "network.h"  //自定义头文件

#include <strings.h>

#define BACKSPACE 127   //删除的asccll码值 

void expression(char name[],char msg[]);


int Connect_Server(void);//服务器连接

void handle_password(char *pass);

 

int Ask_server(int client_socket);//服务器访问 

 

void main_menu(void);//主界面

 

void user_menu(void);//登录界面

 

void regis(int client_socket);//注册 



int entry(int client_socket);//登录

 

void User_used(int client_socket);//用户界面

 

void * readMsg (void *v);//读写分离



void chat_all(int client_socket);//群聊

 

void chat_one(int client_socket);//私聊

 

void entry_out(int client_socket);//退出登录

 

void look_chat(void);//查看聊天记录

 

void see_now_time(int client_socket);//显示当前在线人数

 

void revise_sign(int client_socket);//修改个性签名

 

void revise_password(int client_socket);//修改密码

 

void transfer_file(int client_socket);//传输文件

 

void transfer_file_y(int client_socket);//同意接受文件

 

void transfer_file_n(int client_socket);//拒绝接受文件

 

void start_transfer_file(int client_socket);//开始传输文件

 

void save_transfer_file(Msg * buf);//接受文件

  

#endif

 

 