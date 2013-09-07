#include<stdio.h>
#include<mysql/mysql.h>

struct variables
{
	char *server;
	char *user;
	char *password;
	char *bd;
};
	
int main()
{
	MYSQL *con=mysql_init(NULL);
	MYSQL_RES *res;
	MYSQL_ROW row;
	struct variables var;
	var.server="localhost";
	var.user="root";
	var.password="root";
	var.bd="sakila";
	
	if(!mysql_real_connect(con,var.server,var.user,var.password,var.bd,0,NULL,0))
	{
		printf("Error %s\n",mysql_errno(con));
	}
	mysql_query(con,"select * from actor limit 10");
	res=mysql_use_result(con);
	while((row=mysql_fetch_row(res))!=NULL)
	{
		printf("%s %s %s\n",row[0],row[1],row[2]);
	}
	mysql_close(con);
	return 0;
}
