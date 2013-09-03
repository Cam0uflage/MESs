SOURCE    | HEADER								WHO

Message.c | Message.h								(N0per)
messMessage() - Sends a message to stderr/stdout depending on message type 	
messLogMessage() - Saves all the messages to the log file

Common.c | Common.h
messLogSession(bool b) - logs everything(output from the program,input,errors,warnings)
messGetTime(char* format) - Provides the time in the given format 
messGetTime() - Provides the time in the default format(YYYY-MM-dd-HH-mm-ss)

FileSystem.c | FileSystem.h
messLs(char* path) - lists files into the directory(Returns array of files)
messLs(char* path,char* store[]) - saves the result of "messLs" into the specified array(store)
messReadFile(FILE* file) - Reads a whole file
messCheckPermissions(FILE* file) - Checks the permissions for the specified file (Returns the permission)
messRm(FILE* file) - Deletes the file
messMkDir(char* dir) - creates the directory
messCp(char* target,char* dest,bool recursive) - Copies the target to the destination
messMv(char* target,char* dest) - Moves the target to dest
messDisk() - gives information about the default HDD
messDisk(char* disk) - gives information about the specified disk

