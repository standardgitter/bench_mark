#include <stdio.h>
#include <mysql.h>

int main() 
{ 
        MYSQL mysql; 
        MYSQL_RES *result; 
        MYSQL_FIELD *fields; 
        MYSQL_ROW rows; 
      
        int numOfRows, numOfFields; 
      
        mysql_init(&mysql); 
      
        if (!mysql_real_connect(&mysql,"127.0.0.1","debian-sys-maint","ad3saLOdw4u7xizj","mysql",0,"/var/run/mysqld/mysqld.sock",0)){ 
            fprintf(stderr, "Failed to connect to database: Error: %s\n", 
                mysql_error(&mysql)); 
      
            return -1; 
        } 
      
        printf("MYSQL VERSON IS : %s\n",mysql_get_server_info(&mysql)); 
  
      return 0;
}


