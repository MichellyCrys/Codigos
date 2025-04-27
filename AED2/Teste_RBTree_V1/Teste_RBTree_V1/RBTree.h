typedef int(*TCompararARB)(void* d1, void* d2);
typedef void(*TImprimirARB)(void* info);

typedef enum { RED, BLACK } nodeColor;

typedef struct Node {
    void *data;
    struct Node *left, *right, *parent;
    nodeColor color;
} Node;

typedef struct stat{
  int operationCount;
  int searchComparisons;
  int insertComparisons;
  int removeComparisons;
  int insertRotations;
  int removeRotations;
} t_stats;

typedef struct t_red {
    Node *root;
    TCompararARB compFunc;
    TImprimirARB printFunc;
    t_stats stats;
} t_red;



Node* newNode(Node* parent, void *data);
t_red* criaRED(TCompararARB compFunc, TImprimirARB printFunc);
void inserirRED(t_red *tree, void* data);
void removerRED(t_red *tree, void* data);
void* buscarRED(t_red *tree, void* data);
void estatisticaRED(t_red *tree);
void imprimirRED(t_red* tree);

void fixInsertion(t_red* tree, Node* node, t_stats* stats);
void countRotations(t_red* tree, int operationType);
void countComparisons(t_red* tree, int operationType);
void rotateLeft(t_red* tree, Node* node, t_stats* stats);
void rotateRight(t_red* tree, Node* node, t_stats* stats);
void rotateLeftRemove(t_red* tree, Node* node, t_stats* stats);
void rotateRightRemove(t_red* tree, Node* node, t_stats* stats);

void fixRemoval(t_red* tree, Node* node, Node* parent, t_stats* stats);
Node* findMinimum(Node* node);

