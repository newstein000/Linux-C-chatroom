#ifndef __NETWORK_H__
#define __NETWORK_H__
 
#include <sqlite3.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
 
#define SIZE 1024
 
typedef struct msg          //表示聊天时的信息
{
	char msg[SIZE];   		//消息内容
	char localname[20];		//消息目的名称
	char fromname[20];      //消息来源名称
	char password[20];      //用户密码   
	char signname[40];      //个性签名   
	int cmd;                //工作模式
	int num;                //用于保存文件复制的字节数
}Msg;
 
 
//***************************服务器数据库**************************************
 
//保存账号密码保存在数据库里
sqlite3 * Create_Sqlite(void);
 
//初测时保存用户账号和密码
int Save_User(Msg *msg, sqlite3 *datebase);
 
//登录
int Entry_User(Msg *msg, sqlite3 *datebase);
 
//修改个性签名
int revise_sign_sqlite(Msg * msg);
 
//修改密码
int revise_password_sqlite(Msg * msg);
 
//***************************客户端操作****************************************
 
//创建聊天记录
sqlite3 * Create_user_sqlite(Msg * msg);
 
//保存聊天记录
void save_Chat(Msg *msg);
 
//查看聊天记录
void see_chat(Msg * msg);
 
#endif
 