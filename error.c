#include"error.h"
 
//往屏幕输出错误原因
void myerror (char *str)
{
	char *msg = myStrError ();
	
	printf("%s: %s\n",str,msg);
	
 
}
 
//输入错误原因
char * myStrError (void)
{
	switch (errno)
	{
		case SOCKET_INIT :
			return "初始化套接字失败.";	
		case SOCKET_ACCEPT :
			return "链接客户端失败.";
		case CREATE_SQLITE:
			return "打开数据库失败.";
		case SAVE_SQLITE:
			return "数据库插入数据失败,";
	}
	
}
 