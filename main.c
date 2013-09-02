#include<stdio.h>
#include<mysql/mysql.h>
#include"index.h"

int main()
{
	MYSQL *con=mysql_init(NULL);
	MYSQL_RES *res;
	MYSQL_ROW row;
	if(!mysql_real_connect(con,SERVER,USER,PASSWORD,BD,0,NULL,0))
	{
		printf("Error %s\n",mysql_errno(con));
	}
	mysql_query(con,"show processlist");
	res=mysql_use_result(con);
	while((row=mysql_fetch_row(res))!=NULL)
	{
		printf("%s \n",row[0]);
	}
	mysql_close(con);
	return 0;
}
