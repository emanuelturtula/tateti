#ifndef __TYPES_H__
#define __TYPES_H__

typedef enum status {
    OK,
    ERROR_INSUFFICIENT_MEMORY,
    ERROR_NULL_POINTER,
    ERROR_SOCKET_CREATION,
    ERROR_SOCKET_CONNECTION
} status_t;


#endif