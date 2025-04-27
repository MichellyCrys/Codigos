typedef enum { RED, BLACK } Color;

typedef struct Node {
    void* data;
    Color color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
    int operationCount;
    int searchComparisons;
    int insertComparisons;
    int removeComparisons;
    int insertRotations;
    int removeRotations;
} t_red;

t_red* createARB();
Node* createNode(void* data, Color color, Node* parent);
void countComparisons(t_red* tree, int operationType);
void countRotations(t_red* tree, int operationType);
void rotateLeft(t_red* tree, Node* node);
void rotateRight(t_red* tree, Node* node);
void fixInsertion(t_red* tree, Node* node);
void insertNode(t_red* tree, void* data, int (*compare)(void*, void*));
Node* findMinimum(Node* node);
void transplant(t_red* tree, Node* node1, Node* node2);
void fixRemoval(t_red* tree, Node* node, Node* parent);
void removeNode(t_red* tree, void* data, int (*compare)(void*, void*));
Node* searchNode(Node* node, void* data, int (*compare)(void*, void*), int* comparisons);
Node* searchValue(t_red* tree, void* data, int (*compare)(void*, void*), int* comparisons);
void printStatistics(t_red* tree);
void __printTree(Node* node, void (*print)(void*));
void printTree(t_red* tree, void (*print)(void*));


