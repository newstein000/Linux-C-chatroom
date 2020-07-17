#ifndef __SERVER_H__
#define __SERVER_H__

#include <sys/types.h>  //bind、socket、accept函数
#include <sys/socket.h>  //listen、memset函数
#include <string.h>
#include <arpa/inet.h>  //htonl htons 函数
#include <pthread.h>    //线程
#include <stdio.h>
#include "error.h"     //自定义头文件，用于错误输出
#include "network.h"   //自定义头文件
 
#define PORT 9999        //服务器端口
#define NOW_MAX 20 	 	 //最大允许并行客户端数量
 
typedef struct now_client   //在线人数
{
	char name[20];
	int socket;
}NowClient;
 
int Socket_init (void); //套接字初始化
 
int Socket_Accept (int listen_socket); //服务器链接
 
int Make_Server (void); //创建服务器
 
void * hanld_client (void* v); //操作客户端
 
int regis(int client_socket, Msg *msg); //注册
 
int entry(int client_socket, Msg *msg); //登录
 
void User_server(int client_socket, Msg *msg);   //login界面
 
void server_chatall(int client_socket, Msg * msg); //群聊
 
void server_chatone(int client_socket, Msg * msg);//私聊
 
void server_entryout(int client_socket, Msg * msg); //退出登录
 
void see_nowuser(int client_socket, Msg * msg);    //查看在线人数
 
void server_revise_sign(int client_socket, Msg * msg);//修改个性签名
 
void server_revise_password(int client_socket, Msg * msg);//修改密码
 
void server_transfer_file(int client_socket, Msg * msg);//收到开始传输文件命令
 
void server_transfer_file_y(Msg * msg);//接受文件
 
void server_transfer_file_n(Msg * msg);//拒绝文件
 
void server_start_transfer_file(Msg * msg);//开始文件传输

#endif
 