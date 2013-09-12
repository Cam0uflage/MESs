#ifndef COMMON_H_
#define COMMON_H_

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
void* messAllocateMemory(unsigned int size);
#endif
