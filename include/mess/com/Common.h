#ifndef COMMON_H_
#define COMMON_H_
#include <errno.h>
#include <string.h>

/***
 *  void messGetLastErrorString()
 *
 *  Returns the last error string set by
 *  Errno
 *  
 *
 *
 *  Paramaters:
 *    none
 *
 *
 *  Returns:
 *    the error string
 *
 **/
char* messGetLastErrorString();
#endif
