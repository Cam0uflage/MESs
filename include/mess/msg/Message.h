#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <stdio.h>
#include <Stdlib.h>
#include <errno.h>


enum MessageType {
	MESSAGE_ERROR;
	MESSAGE_WARNING;
};

/***
 *  void messMessage()
 *
 *  Prints a message to the user either on stderr
    or stdout given the type of message.
 *
 *
 *  Paramaters:
 *    message type, source, cause, message
 *
 *
 *  Returns:
 *    none
 *
 **/
void messMessage(MessageType messageType,
     const char* source,
     const char* cause,
     const char* message);


#endif