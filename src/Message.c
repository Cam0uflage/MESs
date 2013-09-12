#include <include/msg/Message.h>


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
     const char* message)
{
    switch(messageType) {

        case MESSAGE_ERROR:
            fprintf(stderr, "[ERROR] (%s %s): %s\n", source, cause, message);
        break;
        
        case MESSAGE_WARNING:
             fprintf(stdout, "[WARNING] (%s %s): %s\n", source, cause, message);
        break;

        default:
             fprintf(stderr, "[ERROR] (uknown source - unknown cause): nothing to say\n");
 
    }
}




