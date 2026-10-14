//hetergeneous linked list
#include <stdlib.h>

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_

} DataType;
//a node that holds an integer value
typedef struct _llnode{
    DataType type;
} llnode;
