/*
  AUTHORS: Cam0, N0per
  DESCRIPTION: This is the FileSystem header, it manages ALL the file-system related stuff.
*/

#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
    int fd;
    struct stat stat;
    OpenFileType
    bool status;
    
} MessFile;

typedef enum {  
                FILE_READ = 0x1,
                FILE_WRITE,
                FILE_APPEND,
} OpenFileType;
 
/***
 *  void messOpenFile()
 *
 *  Opens a file
 *
 *
 *  Paramaters:
 *    Path to the file to open
 *
 *
 *  Returns:
 *    A pointer contain file specifics.
 *
 **/
MessFile* messOpenFile(const char* filename);
 
 
/***
 *  void messCloseFile()
 *
 *  Closes an open file, if the
 *  file is not open nothing is
 *  done, note: it also dealocates
 * 
 *
 *
 *  Paramaters:
 *    MessFile pointer.
 *
 *
 *  Returns:
 *    nothing, check MessFile.status 
 *    for status.
 *
 **/
void messCloseFile(const MessFile* messFile_p);

 
/***
 *  void messDeleteFile()
 *
 *  deletes a file given the path.
 *
 *
 *  Paramaters:
 *    Path to the file to delete as
 *    a string.
 *
 *
 *  Returns:
 *    none
 *
 **/
void messDeleteFile(const char* filename);

 
/***
 *  void messDeleteFileByPointer()
 *
 *  deletes a file given a MessFile
 *  pointer that points to an open
 *  file.
 *
 *
 *  Paramaters:
 *    A MessFile pointer, that is opened.
 *
 *
 *  Returns:
 *    nothing
 *
 **/
void messDeleteFileByPointer(const MessFile* messFile_p);

 
/***
 *  void messRenameFile()
 *
 *  renames originalFilename to newFilename,
 *  make sure the path is the same accept for the
 *  filenames.
 *
 *
 *  Paramaters:
 *    2 strings, original path of the file
 *    and new file path.
 *
 *
 *  Returns:
 *    nothing
 *
 **/
void messRenameFile(const char* originalFilename,
                    const char* newFilename);

 
/***
 *  void messCreateFile()
 *
 *  Creates an empty file
 *
 *
 *  Paramaters:
 *    Path including the filename
 *
 *
 *  Returns:
 *    none
 *
 **/
void messCreateFile(const char* filename);

/***
 *  void messCopyFile()
 *
 *  Copies srcFilename to destFilename
 *  given the complete paths of files.
 *
 *
 *  Paramaters:
 *    Path to source and path
 *    destination.
 *
 *
 *  Returns:
 *    none
 *
 **/
 
void messCopyFile(const char* srcFilename, const char* destFilename);

/***
 *  void messReadFile()
 *
 *  Reads file contents into
 *  destBuffer. destination buffer
 *  is allocated for you.
 *
 *
 *  Paramaters:
 *    A MessFile pointer to an open file, 
 *    destination buffer.
 *    strings.
 *
 *
 *  Returns:
 *    none
 *
 **/
void messReadFile(const MessFile* messFile_p, void* destBuffer);

/***
 *  void messReadFileFromPath()
 *
 *  Reads a file given the path
 *  to it. destination buffer is
 *  allocated for you.
 *
 *  Paramaters:
 *    Path including the filename, destination buffer.
 *    
 *
 *
 *  Returns:
 *    none
 *
 **/
void messReadFileFromPath(const char* filename, void* destBuffer);

/***
 *  void messFileExists)
 *
 *  Checks if a file exists. 
 *  
 *  
 *
 *  Paramaters:
 *    Path to file.
 *    
 *
 *
 *  Returns:
 *    true if file exist, false if not.
 *
 **/
bool messFileExists(const char* filename);
#endif 
