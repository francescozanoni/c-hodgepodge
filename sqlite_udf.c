#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT1

static void fz(sqlite3_context *context, int argc, sqlite3_value **argv){
	  sqlite3_result_text(context, "fzfz", -1, SQLITE_TRANSIENT); 
}

#ifdef _WIN32
__declspec(dllexport)
#endif

	int sqlite3_extension_init(
			  sqlite3 *db, 
			    char **pzErrMsg, 
			      const sqlite3_api_routines *pApi
			){
		  int rc = SQLITE_OK;
		    SQLITE_EXTENSION_INIT2(pApi);
		      sqlite3_create_function_v2(db, "fz", 1, SQLITE_UTF8, 0, fz, 0, 0, 0);
		        return rc;
	}

// https://sqlite.org/c3ref/create_function.html
// // https://www.sqlite.org/loadext.html
// // https://www.sqlite.org/contrib/download/extension-functions.c?get=25
//
// // $ gcc -g -fPIC -shared fz.c -o fz.so
// // sqlite> .load ./fz
//
// // $ sudo apt-get install gcc libsqlite3-dev
