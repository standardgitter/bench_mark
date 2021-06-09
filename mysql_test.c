#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <mysql.h>

void insert_test(MYSQL *mysql,size_t rows){
        MYSQL_STMT    *stmt;
        MYSQL_BIND    bind[1];
        int i,len;
        char var[12];
        struct timeval start, end;
	gettimeofday(&start, NULL);
        
        stmt = mysql_stmt_init(mysql);
        mysql_stmt_prepare(stmt, "INSERT INTO t1(c2_t) VALUES(?)", strlen("INSERT INTO t1(c2_t) VALUES(?)"));
        
        bind[0].buffer_type= MYSQL_TYPE_STRING;
        bind[0].buffer= (char *)var;
        bind[0].buffer_length= sizeof(var);
        bind[0].is_null= 0;
        bind[0].length= &len;
	
        mysql_stmt_bind_param(stmt, bind);
        
        for(i=0;i<rows;i++){
		len = snprintf(var,sizeof(var),"011%d",i);
                mysql_stmt_execute(stmt);
		mysql_commit(mysql);
	}
        
        mysql_stmt_close(stmt);
	//mysql_commit(mysql);
        
        gettimeofday(&end, NULL);
        double ms = (double)end.tv_sec * 1000.0 + (double)end.tv_usec/1000.0  
	-  (double)start.tv_sec * 1000.0 - (double)start.tv_usec/1000.0;
        
        printf("insert %d rows taken %.0fms, %.0f insert/second \n",i, ms ,rows*1000/ms);

}


int main(int argc, char* argv[]) 
{ 
	size_t rows;
	if(argc == 2)
		rows = atol(argv[1]);
	else
		rows = 3000000;
	
        MYSQL mysql; 

        mysql_init(&mysql); 
      
        if (!mysql_real_connect(&mysql,"127.0.0.1","debian-sys-maint","ad3saLOdw4u7xizj","mysql",0,"/var/run/mysqld/mysqld.sock",0)){ 
            fprintf(stderr, "Failed to connect to database: Error: %s\n", 
                mysql_error(&mysql)); 
      
            return -1; 
        } 
      
        printf("MYSQL VERSON IS : %s\n",mysql_get_server_info(&mysql)); 
        mysql_set_character_set(&mysql, "utf-8"); 
        
        mysql_query(&mysql,"CREATE TABLE t1(c1_i int(11) PRIMARY KEY auto_increment, c2_t char(16))engine=innodb charset = utf8");
        
        insert_test(&mysql,rows);
	
	mysql_close(&mysql);
  
        return 0;
}


