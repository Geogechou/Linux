#include <cstdio>
#include <cstdlib>
#include <mysql.h>

void delete_by_id(MYSQL* conn, int id)
{
	char query_string[128];
	sprintf(query_string,"delete from teacher where id=%d;",id);
	int rtn = mysql_query(conn,query_string);
	if(rtn){
		perror(mysql_error(conn));
		exit(1);
	}else{
		printf("删除成功,id=%d\n",id);
	}

}
void insert_data(MYSQL* conn,const char* name,int id=-1)
{
	char query_string[128];
	if(id<0)
		sprintf(query_string,"insert into teacher(name) values('%s');",name);
	else
		sprintf(query_string,"insert into teacher(id,name) values('%d','%s');",id,name);
	int rtn = mysql_query(conn,query_string);
	if(rtn){
		perror(mysql_error(conn));
		exit(1);
	}else{
		printf("插入成功\n");
	}
}
void query_data(MYSQL* conn)
{
    int res = mysql_query(conn, "select * from teacher");
    if(res){
        printf("mysql_query: %s\n", mysql_error(conn));
        exit(1);
    } else {
        MYSQL_RES *result = mysql_store_result(conn);
        if(result){
            for(int i = 0; i < mysql_num_rows(result); i++){
                MYSQL_ROW row = mysql_fetch_row(result);
                for(int j = 0; j < mysql_num_fields(result); j++){
                    printf("%s\t", row[j]);
                }
                printf("\n");
            }
        }
        mysql_free_result(result);
    }

}

int main()
{
    MYSQL *conn = mysql_init(NULL);
    //mysql_real_connect(mysql,host,user,passwd,db,port,unix_socket,client_flag)
    conn = mysql_real_connect(conn, "localhost", "root", "newworld", "university", 0, NULL, 0);
    if(!conn){
        perror("mysql_real_connect,连接出错");
        exit(1);
    }

    query_data(conn);
    delete_by_id(conn, 3);
    insert_data(conn,"jazz");
    insert_data(conn,"mick",6);
    mysql_close(conn);
    return 0;
}
