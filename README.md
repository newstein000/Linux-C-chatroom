# Linux-C-聊天室
运行在Linux系统平台，基于TCP/IP的聊天室程序
首先是系统目录(用户.db为系统为每个登录用户创建的数据库文件，chat.db为聊天记录,client server为用户端和服务器端)


先看功能，再看主要代码分析

登录界面，主要功能是注册，登录，退出




1、注册功能（考虑实用，这里没有密文处理）：

2 、登录功能（密文处理，密码可删除）：

 3、退出功能：



Linux C 实现密码的密文输入，*输出，可删除

---------------------------------------------------------------------------------------------------------------------------------------------------------

用户主界面：
个性签名功能：



表情功能（很简单好玩的功能）：






void expression(char name[],char msg[])
{
	if(strcmp(msg,"/xl") == 0)
	{
	    sprintf(msg,"表情：%s 做了个笑脸 ☺:-D",name);
	}
	if(strcmp(msg,"/js") == 0)
	{
	    sprintf(msg,"表情：%s 很沮丧 ☹ :-(",name);
	}
	if(strcmp(msg,"/jy") == 0)
	{
	    sprintf(msg,"表情：%s 很惊讶 :-O",name);
	}
	if(strcmp(msg,"/hh") == 0)
	{
	    sprintf(msg,"表情：哈哈 ^_^");
	}
	if(strcmp(msg,"/kkl") == 0)
	{
	    sprintf(msg,"表情：%s 快哭了 T_T",name);
	}
	if(strcmp(msg,"/zk") == 0)
	{
	    sprintf(msg,"表情：%s 抓狂 >_<",name);
	}
	if(strcmp(msg,"/mmj") == 0)
	{
	    sprintf(msg,"表情：喵喵叫 (=^_^=)");
	}
	if(strcmp(msg,"/yd") == 0)
	{
	    sprintf(msg,"表情：晕 (×_×)");
	}
	if(strcmp(msg,"/zt") == 0)
	{
	    sprintf(msg,"表情：猪头 ^(oo)^");
	}
	if(strcmp(msg,"/dgx") == 0)
	{
	    sprintf(msg,"表情：大狗熊  (￣(工)￣)");
	}
	if(strcmp(msg,"/bz") == 0)
	{
	    sprintf(msg,"表情：闭嘴吧你 :-x");
	}
}
 表情格式为 /+表情缩写，如 /js 表示表情沮丧 /zt 表示表情猪头




功能选项


私聊、群聊功能（这里设置一个数组，保存用户在线状态，默认0，每次用户上线为1，群发即对每个状态为1的用户发消息）：

1、群聊


2、私聊：


3、退出登录


4、查看聊天记录（读sqlite3数据库数据） 



5、查看在线人数：


6、修改个性签名


7、修改密码（这里为了实用密码也没有密文处理）


这里在修改密码成功后并没有立刻退出（感兴趣的可以在我代码上在密码修改成功后加上正常退出功能） 

为了整体编译，写了个Makefile

all:client server
client:client.o error.o sqlite3.o
	gcc client.o error.o sqlite3.o -o client -lsqlite3 -lpthread
server:sqlite3.o server.o error.o
	gcc sqlite3.o server.o error.o -o server -lsqlite3 -lpthread

sqlite3.o:sqlite3.c
	gcc -c sqlite3.c
server.o:server.c
	gcc -c server.c
client.o:client.c
	gcc -c client.c
error.o:error.c
	gcc -c error.c	


.PHONY:clean
clean:
	rm -f *.o
	rm -f server
	rm -f client
	rm -f *.db

 
clear:
	rm *.db
 8、文件传输，亟待完善
