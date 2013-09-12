#include <mess/fs/FileSystem.h>

/***
* void messOpenFile()
*
* Opens a file
*
*
* Paramaters:
* Path to the file to open
*
*
* Returns:
* A pointer contain file specifics.
*
**/
MessFile* messOpenFile(const char* filename, FileOpenType openType) {
    
    assert(filename != NULL);

    MessFile* messFile_p;
    
    /* allocating memory */
    messFile_p = malloc(sizeof(MessFile));
    if(messFile == NULL) {
        messMessage(MESSSAGE_ERROR, "malloc", messGetLastErrorString(), 
        "Unable to alocate memory!");
        return NULL;
    }

    /* clear out memory */
    memset(messFile_p, 0, sizeof(MessFile));
    
    /* set values */
    switch(openType) {
        case FILE_READ:
        {
            messFile_p->fd = open(filename, O_RDONLY);
            if(messFile_p->fd == -1) {
                messMessage(MESSSAGE_ERROR, "open", messGetLastErrorString(), "");
                return NULL;
            }
        }
        break;
        
        case FILE_WRITE: 
        {
            messFile_p->fd = open(filename, O_WRONLY);
            if(messFile_p->fd == -1) {
                messMessage(MESSSAGE_ERROR, "open", messGetLastErrorString(), "");
                return NULL;
            }
        }
        break;

        case ((openType & (FILE_READ | FILE_WRITE)) == 0): 
        {
            messFile_p->fd = open(filename, O_RDWR);
            if(messFile_p->fd == -1) {
                messMessage(MESSSAGE_ERROR, "open", messGetLastErrorString(), "");
                return NULL;
            } 
        }
        break;

        case ((openType & (FILE_READ | FILE_APPEND)) == 0):
        {
             messFile_p->fd = open(filename, O_RDONLY | O_APPEND);
            if(messFile_p->fd == -1) {
                messMessage(MESSSAGE_ERROR, "open", messGetLastErrorString(), "");
                return NULL;
            }
        }
        break;
    }
    
    /* if the code reached this far
     * the file is opened.*/
    messFile_p->status = TRUE;

    if(stat(filename, &(messFile_p->stats)) == -1) {
         messMessage(MESSSAGE_ERROR, "stat", messGetLastErrorString(), "");
                return NULL;
    }

    return messFile_p;
}

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
void messCloseFile(const MessFile* messFile_p) {
    assert(messFile_p);
    
    close(messFile_p->fd);
    messFile_p->status = FALSE;
    memset(&(messFile_p->stats), 0, sizeof(messFile));
}

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
void messDeleteFile(const char* filename) {
    assert(filename != NULL);

    if(remove(filename) == -1) {
           messMessage(MESSSAGE_ERROR, "remove", messGetLastErrorString(), "");
    }
}
