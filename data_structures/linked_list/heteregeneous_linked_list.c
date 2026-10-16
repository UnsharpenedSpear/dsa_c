// hetergeneous linked list
#include <stdlib.h>

typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_CHAR , TYPE_STRING } DataType;
// a node that holds an integer value
typedef struct _hetero_node {
    DataType type;
    struct _hetero_node *next;

    union {
        int i_val;
        float f_val;
        char c_val;
        char* s_val;
    } data;

} hetero_node;

hetero_node *create_hetero(DataType Type) {


}
