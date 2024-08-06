typedef struct node{
    int value;
    struct node *right;
    struct node *left;
} node_t;

enum {SUCCESS = 1, NODE_CREATE_ERR};

