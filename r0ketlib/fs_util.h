#ifndef _FS_UTIL_H
#define _FS_UTIL_H 1

#include <fatfs/ff.h>

void fsInit(void);
int readFile(char * filename, char * data, int len);
int readTextFile(char * filename, char * data, int len);
int writeFile(char * filename, const char * data, int len);
const char* f_get_rc_string (FRESULT rc);

#endif /* _FS_UTIL_H */
