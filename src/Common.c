#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <com/Common.h>

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
char* messGetLastErrorString()
{
    return strerror(errno);
}

/***
 *  void messAllocateMemory()
 *
 *  Returns a pointer to a buffer.
 *  
 *  
 *
 *
 *  Paramaters:
 *    The size of the buffer to allocate.
 *
 *
 *  Returns:
 *    A pointer to the buffer if successfull,
 *    NULL if there was a problem.
 *
 *
 **/
void* messAllocateMemory(unsigned int size)
{
    void* buffer;
    buffer = malloc(size);
    if(buffer == NULL) {
        return NULL;
    }
    
    return buffer;
}
