#include <stdio.h>
#include <sys/time.h>
#include "sqlite3.h"
//gcc test.c -o test  -L/root/dvlp/sqlite3/lib -I/root/dvlp/sqlite3/include  -lsqlite3 -ldl
void insert_test(sqlite3 *db,size_t rows){
	sqlite3_stmt *stmt = 0;
	int i,len;
	char var[12];
	struct timeval start, end;
	gettimeofday(&start, NULL);
	
	sqlite3_prepare_v2(db, "INSERT INTO t1(c2_t) VALUES(?)",-1, &stmt, 0);
	//sqlite3_exec(db, "begin", NULL, 0, NULL);//use transation will save much time
	for(i=0;i<rows;i++){
		len = snprintf(var,sizeof(var),"011%d",i);
		sqlite3_bind_text(stmt, 0, var, len, 0);
		sqlite3_step(stmt);
		sqlite3_reset(stmt);
	}
	sqlite3_finalize(stmt);
	//sqlite3_exec(db, "commit", NULL, 0, NULL);
	
	
	gettimeofday(&end, NULL);
	
	double ms = (double)end.tv_sec * 1000.0 + (double)end.tv_usec/1000.0  
	-  (double)start.tv_sec * 1000.0 - (double)start.tv_usec/1000.0;
	
	printf("select %ld rows taken %.0fms, %.0f insert/second \n",rows, ms ,rows*1000/ms);
}


void select_test(sqlite3 *db,size_t rows){
	sqlite3_stmt *stmt = 0;
	int var, i, rc;
	int c1_i;
	const unsigned char *c2_t;
	
	struct timeval start, end;
	gettimeofday(&start, NULL);
	
	sqlite3_prepare_v2(db, "SELECT c1_i,c2_t FROM t1 WHERE c1_i = ?",-1, &stmt, 0);
	for(i = 0; i< rows; i++){
		var = i+1;
		sqlite3_bind_int(stmt, 1, var);
		while( (rc = sqlite3_step(stmt)) == SQLITE_ROW ){
			c1_i = sqlite3_column_int(stmt, 0 );
			c2_t = sqlite3_column_text(stmt, 1);
		}
		sqlite3_reset(stmt);
	}

	sqlite3_finalize(stmt);
	
	gettimeofday(&end, NULL);
	double ms = (double)end.tv_sec * 1000.0 + (double)end.tv_usec/1000.0  
	-  (double)start.tv_sec * 1000.0 - (double)start.tv_usec/1000.0;
	
	printf("select %ld rows taken %.0fms, %.0f select/second \n",rows, ms ,rows*1000/ms);
	
}

int main(int argc, char* argv[])
{
	size_t rows;
	if(argc == 2)
		rows = atoi(argv[1]);
	else
		rows = 3000000;
	
	sqlite3 *db;
	sqlite3_open(":memory:", &db);
	sqlite3_exec(db, "CREATE TABLE t1(c1_i INTEGER PRIMARY KEY,c2_t text)", NULL, 0, NULL);

	insert_test(db,rows);
	select_test(db,rows);

	sqlite3_close(db);
	return 0;
}
