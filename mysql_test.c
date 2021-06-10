#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <mysql.h>

void insert_test_innodb(MYSQL *mysql,size_t rows){
        MYSQL_STMT    *stmt;
        MYSQL_BIND    bind[1];
        int i;
	long unsigned int len;
        char var[12];
        struct timeval start, end;
	
	mysql_query(mysql,"drop table if exists t1");
	mysql_query(mysql,"CREATE TABLE t1(c1_i int(11) PRIMARY KEY auto_increment, c2_t varchar(16))engine=innodb");
	mysql_autocommit(mysql, 1);//default
	
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
		len = snprintf(var,sizeof(var),"%011d",i);
                if(mysql_stmt_execute(stmt) != 0)
		{
			printf(" %s\n", mysql_stmt_error(stmt));
			break;
		}		
//mysql_commit(mysql);
	}
        
        mysql_stmt_close(stmt);
//mysql_commit(mysql);
        
        gettimeofday(&end, NULL);
        double ms = (double)end.tv_sec * 1000.0 + (double)end.tv_usec/1000.0  
	-  (double)start.tv_sec * 1000.0 - (double)start.tv_usec/1000.0;
        
        printf("insert innodb %d rows taken %.0fms, %.0f insert/second \n",i, ms ,rows*1000/ms);
	
	mysql_query(mysql,"SELECT count(*) FROM t1");
	MYSQL_RES *result = mysql_store_result(mysql);
	
	MYSQL_FIELD *fields; 
	while (fields = mysql_fetch_field(result)){ 
                printf("%s\t",fields->name); 
	} 
	
	int numOfFields = mysql_num_fields(result); 
	MYSQL_ROW result_rows;
	while (result_rows = mysql_fetch_row(result)){
		for (i=0; i<numOfFields; i++){ 
                    printf("%s\t",result_rows[i]); 
                } 
                printf("\n"); 
	}
	mysql_free_result(result); 
}

void insert_test_innodb_batch(MYSQL *mysql,size_t rows){
        MYSQL_STMT    *stmt;
        MYSQL_BIND    bind[1];
        int i;
	long unsigned int len;
        char var[12];
        struct timeval start, end;
	
	mysql_query(mysql,"drop table if exists t1");
	mysql_query(mysql,"CREATE TABLE t1(c1_i int(11) PRIMARY KEY auto_increment, c2_t varchar(16))engine=innodb");
	mysql_autocommit(mysql, 0);
	
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
		len = snprintf(var,sizeof(var),"%011d",i);
                if(mysql_stmt_execute(stmt) != 0)
		{
			printf(" %s\n", mysql_stmt_error(stmt));
			break;
		}		
		//mysql_commit(mysql);
	}
        
        mysql_stmt_close(stmt);
	mysql_commit(mysql);
        
        gettimeofday(&end, NULL);
        double ms = (double)end.tv_sec * 1000.0 + (double)end.tv_usec/1000.0  
	-  (double)start.tv_sec * 1000.0 - (double)start.tv_usec/1000.0;
        
        printf("insert innodb batch %d rows taken %.0fms, %.0f insert/second \n",i, ms ,rows*1000/ms);
	
	mysql_query(mysql,"SELECT count(*) FROM t1");
	MYSQL_RES *result = mysql_store_result(mysql);
	
	MYSQL_FIELD *fields; 
	while (fields = mysql_fetch_field(result)){ 
                printf("%s\t",fields->name); 
	} 
	
	int numOfFields = mysql_num_fields(result); 
	MYSQL_ROW result_rows;
	while (result_rows = mysql_fetch_row(result)){
		for (i=0; i<numOfFields; i++){ 
                    printf("%s\t",result_rows[i]); 
                } 
                printf("\n"); 
	}
	mysql_free_result(result); 
}

void insert_test_myisam(MYSQL *mysql,size_t rows){
        MYSQL_STMT    *stmt;
        MYSQL_BIND    bind[1];
        int i;
	long unsigned int len;
        char var[12];
        struct timeval start, end;
	
	mysql_query(mysql,"drop table if exists t1");
	mysql_query(mysql,"CREATE TABLE t1(c1_i int(11) PRIMARY KEY auto_increment, c2_t varchar(16))engine=myisam");
	
	gettimeofday(start, NULL);
        
        stmt = mysql_stmt_init(mysql);
        mysql_stmt_prepare(stmt, "INSERT INTO t1(c2_t) VALUES(?)", strlen("INSERT INTO t1(c2_t) VALUES(?)"));
        
        bind[0].buffer_type= MYSQL_TYPE_STRING;
        bind[0].buffer= (char *)var;
        bind[0].buffer_length= sizeof(var);
        bind[0].is_null= 0;
        bind[0].length= &len;
	
        mysql_stmt_bind_param(stmt, bind);

        for(i=0;i<rows;i++){
		len = snprintf(var,sizeof(var),"%011d",i);
                if(mysql_stmt_execute(stmt) != 0)
		{
			printf(" %s\n", mysql_stmt_error(stmt));
			break;
		}		
	}
        mysql_stmt_close(stmt);
	
        gettimeofday(&end, NULL);
        double ms = (double)end.tv_sec * 1000.0 + (double)end.tv_usec/1000.0  
	-  (double)start.tv_sec * 1000.0 - (double)start.tv_usec/1000.0;
        
        printf("insert myisam %d rows taken %.0fms, %.0f insert/second \n",i, ms ,rows*1000/ms);
	
	mysql_query(mysql,"SELECT count(*) FROM t1");
	MYSQL_RES *result = mysql_store_result(mysql);
	
	MYSQL_FIELD *fields; 
	while (fields = mysql_fetch_field(result)){ 
                printf("%s\t",fields->name); 
	} 
	
	int numOfFields = mysql_num_fields(result); 
	MYSQL_ROW result_rows;
	while (result_rows = mysql_fetch_row(result)){
		for (i=0; i<numOfFields; i++){ 
                    printf("%s\t",result_rows[i]); 
                } 
                printf("\n"); 
	}
	mysql_free_result(result); 
}


void insert_test_memory(MYSQL *mysql,size_t rows){
        MYSQL_STMT    *stmt;
        MYSQL_BIND    bind[1];
        int i;
	long unsigned int len;
        char var[12];
        struct timeval start, end;
	
	mysql_query(mysql,"drop table if exists t1");
	mysql_query(mysql,"CREATE TABLE t1(c1_i int(11) PRIMARY KEY auto_increment, c2_t varchar(16))engine=memory");
	
	gettimeofday(start, NULL);
        
        stmt = mysql_stmt_init(mysql);
        mysql_stmt_prepare(stmt, "INSERT INTO t1(c2_t) VALUES(?)", strlen("INSERT INTO t1(c2_t) VALUES(?)"));
        
        bind[0].buffer_type= MYSQL_TYPE_STRING;
        bind[0].buffer= (char *)var;
        bind[0].buffer_length= sizeof(var);
        bind[0].is_null= 0;
        bind[0].length= &len;
	
        mysql_stmt_bind_param(stmt, bind);

        for(i=0;i<rows;i++){
		len = snprintf(var,sizeof(var),"%011d",i);
                if(mysql_stmt_execute(stmt) != 0)
		{
			printf(" %s\n", mysql_stmt_error(stmt));
			break;
		}		
	}
        mysql_stmt_close(stmt);
	
        gettimeofday(&end, NULL);
        double ms = (double)end.tv_sec * 1000.0 + (double)end.tv_usec/1000.0  
	-  (double)start.tv_sec * 1000.0 - (double)start.tv_usec/1000.0;
        
        printf("insert memory %d rows taken %.0fms, %.0f insert/second \n",i, ms ,rows*1000/ms);
	
	mysql_query(mysql,"SELECT count(*) FROM t1");
	MYSQL_RES *result = mysql_store_result(mysql);
	
	MYSQL_FIELD *fields; 
	while (fields = mysql_fetch_field(result)){ 
                printf("%s\t",fields->name); 
	} 
	
	int numOfFields = mysql_num_fields(result); 
	MYSQL_ROW result_rows;
	while (result_rows = mysql_fetch_row(result)){
		for (i=0; i<numOfFields; i++){ 
                    printf("%s\t",result_rows[i]); 
                } 
                printf("\n"); 
	}
	mysql_free_result(result); 
}

//mysql_test user password  rows

int main(int argc, char* argv[]) 
{ 
	if(argc != 4){
		printf("./mysql_test user password  rows \ndemo : /mysql_test debian-sys-maint ad3saLOdw4u7xizj 3000000\n");
		return -1;
	}
	size_t rows = atol(argv[3]);
	
	
        MYSQL mysql;

        mysql_init(&mysql); 
      
        if (!mysql_real_connect(&mysql,"localhost",argv[1],argv[2],"mysql",0,"/var/run/mysqld/mysqld.sock",0)){ 
            fprintf(stderr, "Failed to connect to database: Error: %s\n", 
                mysql_error(&mysql)); 
      
            return -1; 
        } 
      
        printf("MYSQL VERSON IS : %s\n",mysql_get_server_info(&mysql)); 
        mysql_set_character_set(&mysql, "utf-8"); 
	//mysql_autocommit(&mysql, 0); // 1(on) is default, turn the autocommit on meaning commit every ddl sql, so it very slow.
	insert_test_myisam(&mysql,rows);
	insert_test_memory(&mysql,rows);
	insert_test_innodb(&mysql,rows);
	insert_test_innodb_batch(&mysql,rows);
	//mysql_query(&mysql,"drop table if exists t1");
//mysql_query(&mysql,"CREATE TABLE t1(c1_i int(11) PRIMARY KEY auto_increment, c2_t varchar(16))engine=innodb");
	//mysql_query(&mysql,"CREATE TABLE t1(c1_i int(11) PRIMARY KEY auto_increment, c2_t varchar(16))engine=myisam");
	//mysql_query(&mysql,"CREATE TABLE t1(c1_i int(11) PRIMARY KEY auto_increment, c2_t varchar(16))engine=memory");
	

	
	mysql_close(&mysql);
  
        return 0;
}


