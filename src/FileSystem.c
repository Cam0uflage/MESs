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
        messMessage(MESSSAGE_ERROR, "malloc", getLastErrorString(), 
        "Unable to alocate memory!");
        /* exit critical error*/
    }

    /* clear out memory */
    memset(messFile_p, 0, sizeof(MessFile));
    
    /* set values */
    switch(openType) {
        case: FILE_READ:
        {
            messFile_p->fd = open(filename, O_RDONLY);
            if(messFile_p->fd == -1) {
                messMessage(MESSSAGE_ERROR, "open", getLastErrorString(), "");
            }
        }
        break;
        
        case FILE_WRITE: 
        {
            messFile_p->fd = open(filename, O_WRONLY);
            if(messFile_p->fd == -1) {
                messMessage(MESSSAGE_ERROR, "open", getLastErrorString(), "");
            }
        }
    }

}
