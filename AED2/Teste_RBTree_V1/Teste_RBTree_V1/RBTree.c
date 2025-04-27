#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"

Node* newNode(Node* parent, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    node->parent = parent;
    node->color = RED;
    return node;
}

t_red* criaRED(TCompararARB compFunc, TImprimirARB printFunc) {
    t_red* tree = (t_red*)malloc(sizeof(t_red));
    tree->root = NULL;
    tree->compFunc = compFunc;
    tree->printFunc = printFunc;
    tree->stats.operationCount = 0;
    tree->stats.searchComparisons = 0;
    tree->stats.insertComparisons = 0;
    tree->stats.removeComparisons = 0;
    tree->stats.insertRotations = 0;
    tree->stats.removeRotations = 0;
    return tree;
}

// Função auxiliar para contar comparações
void countComparisons(t_red* tree, int operationType) {
    tree->stats.operationCount++;
    switch (operationType) {
        case 0: // Busca
            tree->stats.searchComparisons++;
            break;
        case 1: // Inserção
            tree->stats.insertComparisons++;
            break;
        case 2: // Remoção
            tree->stats.removeComparisons++;
            break;
    }
}

// Função auxiliar para contar rotações
void countRotations(t_red* tree, int operationType) {
    switch (operationType) {
        case 1: // Inserção
            tree->stats.insertRotations++;
            break;
        case 2: // Remoção
            tree->stats.removeRotations++;
            break;
    }
}

// Função auxiliar para realizar uma rotação à esquerda
void rotateLeft(t_red* tree, Node* node, t_stats* stats) {
    Node* rightChild = node->right;
    node->right = rightChild->left;

    if (rightChild->left != NULL) {
        rightChild->left->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == NULL) {
        tree->root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;

    countRotations(tree, 1);
}




void rotateRight(t_red* tree, Node* node, t_stats* stats) {
    Node* leftChild = node->left;
    node->left = leftChild->right;

    if (leftChild->right != NULL) {
        leftChild->right->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == NULL) {
        tree->root = leftChild;
    } else if (node == node->parent->right) {
        node->parent->right = leftChild;
    } else {
        node->parent->left = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;

    countRotations(tree, 1);
}

// Função auxiliar para corrigir a inserção
void fixInsertion(t_red* tree, Node* node, t_stats* stats) {
    while (node != tree->root && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;

            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    rotateLeft(tree, node, stats);
                }

                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateRight(tree, node->parent->parent, stats);
            }
        } else {
            Node* uncle = node->parent->parent->left;

            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotateRight(tree, node, stats);
                }

                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateLeft(tree, node->parent->parent, stats);
            }
        }
    }

    tree->root->color = BLACK;
}

void inserirRED(t_red* tree, void* data) {
    Node* novoNode = newNode(NULL, data); // Corrigido para newNode
    Node* current = tree->root;
    Node* parent = NULL;

    while (current != NULL) {
        int compResult = tree->compFunc(data, current->data);
        parent = current;

        if (compResult < 0) {
            current = current->left;
            countComparisons(tree, 1);
        } else if (compResult > 0) {
            current = current->right;
            countComparisons(tree, 1);
        } else {
            free(novoNode);
            return; // O nó já existe na árvore
        }
    }

    novoNode->parent = parent;

    if (parent == NULL) {
        tree->root = novoNode;
    } else if (tree->compFunc(novoNode->data, parent->data) < 0) {
        parent->left = novoNode;
    } else {
        parent->right = novoNode;
    }

    novoNode->color = RED;
    fixInsertion(tree, novoNode, &(tree->stats));
}


static Node* __inserirRED(Node* root, void* data, TCompararARB compFunc, t_stats* stats, t_red* tree) {
    if (root == NULL) {
        stats->insertComparisons++;
        Node* new_node = newNode(NULL, data);
        return new_node;
    }
    if (compFunc(root->data, data) > 0) {
        root->left = __inserirRED(root->left, data, compFunc, stats, tree);
        root->left->parent = root;
        stats->insertComparisons += 2;
    } else {
        root->right = __inserirRED(root->right, data, compFunc, stats, tree);
        root->right->parent = root;
        stats->insertComparisons += 3;
    }

    fixInsertion(tree, root, stats); // Chamada para reequilibrar a árvore

    return root;
}

/*
void inserirRED2(t_red *tree, void* data) {
    t_stats* stats = &(tree->stats);
    stats->operationCount++;
    tree->root = __inserirRED(tree->root, data, tree->compFunc, stats, tree);
}

*/

// Função auxiliar para encontrar o nó com valor mínimo na subárvore
Node* findMinimum(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Função auxiliar para substituir um nó por outro na árvore
void transplant(t_red* tree, Node* node1, Node* node2) {
    if (node1->parent == NULL) {
        tree->root = node2;
    } else if (node1 == node1->parent->left) {
        node1->parent->left = node2;
    } else {
        node1->parent->right = node2;
    }

    if (node2 != NULL) {
        node2->parent = node1->parent;
    }
}


// Função auxiliar para realizar uma rotação à esquerda
void rotateLeftRemove(t_red* tree, Node* node, t_stats* stats) {
    Node* rightChild = node->right;
    node->right = rightChild->left;

    if (rightChild->left != NULL) {
        rightChild->left->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == NULL) {
        tree->root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;

    stats->insertRotations++;
}




void rotateRightRemove(t_red* tree, Node* node, t_stats* stats) {
    Node* leftChild = node->left;
    node->left = leftChild->right;

    if (leftChild->right != NULL) {
        leftChild->right->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == NULL) {
        tree->root = leftChild;
    } else if (node == node->parent->right) {
        node->parent->right = leftChild;
    } else {
        node->parent->left = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;

    stats->insertRotations++;
}

void fixRemoval(t_red* tree, Node* node, Node* parent, t_stats* stats) {
    Node* sibling;
    while ((node == NULL || node->color == BLACK) && node != tree->root) {
        if (node == parent->left) {
            sibling = parent->right;
            if (sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                rotateLeftRemove(tree, parent, stats);
                //stats->removeRotations++;
                tree->stats.removeRotations++;

                sibling = parent->right;
            }
            if ((sibling->left == NULL || sibling->left->color == BLACK) &&
                (sibling->right == NULL || sibling->right->color == BLACK)) {
                sibling->color = RED;
                node = parent;
                parent = node->parent;
            } else {
                if (sibling->right == NULL || sibling->right->color == BLACK) {
                    if (sibling->left != NULL) {
                        sibling->left->color = BLACK;
                    }
                    sibling->color = RED;
                    rotateRightRemove(tree, parent, stats);
                    tree->stats.removeRotations++;

                    sibling = parent->right;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->right != NULL) {
                    sibling->right->color = BLACK;
                }
                rotateLeftRemove(tree, parent, stats);
                tree->stats.removeRotations++;
                node = tree->root;
                break;
            }
        } else {
            sibling = parent->left;
            if (sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                rotateRightRemove(tree, parent, stats);
                tree->stats.removeRotations++;

                sibling = parent->left;
            }
            if ((sibling->right == NULL || sibling->right->color == BLACK) &&
                (sibling->left == NULL || sibling->left->color == BLACK)) {
                sibling->color = RED;
                node = parent;
                parent = node->parent;
            } else {
                if (sibling->left == NULL || sibling->left->color == BLACK) {
                    if (sibling->right != NULL) {
                        sibling->right->color = BLACK;
                    }
                    sibling->color = RED;
                    rotateLeftRemove(tree, parent, stats);
                    tree->stats.removeRotations++;

                    sibling = parent->left;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->left != NULL) {
                    sibling->left->color = BLACK;
                }
                rotateRightRemove(tree, parent, stats);
                tree->stats.removeRotations++;
                node = tree->root;
                break;
            }
        }
    }
    if (node != NULL) {
        node->color = BLACK;
    }
}



Node* __removerRED(Node* root, void* data, TCompararARB compFunc, t_stats* stats, t_red* tree) {
    if (root == NULL) {
        return NULL;
    } else if (compFunc(root->data, data) > 0) {
        stats->removeComparisons++;
        root->left = __removerRED(root->left, data, compFunc, stats, tree);
        return root;
    } else if (compFunc(root->data, data) < 0) {
        stats->removeComparisons += 2;
        root->right = __removerRED(root->right, data, compFunc, stats, tree);
        return root;
    } else {
        stats->removeComparisons += 3;
        if ((root->left == NULL) && (root->right == NULL)) {
            free(root->data);
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            root->right->parent = root->parent;
            Node* right = root->right;
            free(root->data);
            free(root);
            countRotations(tree, 2); // Adicionado aqui para contar a rotação
            return right;
        } else if (root->right == NULL) {
            root->left->parent = root->parent;
            Node* left = root->left;
            free(root->data);
            free(root);
            countRotations(tree, 2); // Adicionado aqui para contar a rotação
            return left;
        } else {
            Node* largest = root->left;
            while (largest->right != NULL) {
                largest = largest->right;
            }
            void* temp = root->data;
            root->data = largest->data;
            largest->data = temp;
            root->left = __removerRED(root->left, largest->data, compFunc, stats, tree); // Corrigido aqui para usar largest->data
            fixRemoval(tree, root, root->parent, stats);
            return root;
        }
    }
}

void removerRED(t_red* tree, void* data) {
    t_stats* stats = &(tree->stats);
    tree->stats.operationCount++;
    tree->root = __removerRED(tree->root, data, tree->compFunc, stats, tree);
}





Node* __buscarRED(Node* root, void* data, TCompararARB compFunc, t_stats* stats) {
    if (root == NULL) {
        return NULL;
    }
    int status = compFunc(root->data, data);
    if (status == 0) {
        stats->searchComparisons += 1;
        return root;
    } else if (status < 0) {
        stats->searchComparisons += 2;
        return __buscarRED(root->right, data, compFunc, stats);
    } else {
        stats->searchComparisons += 3;
        return __buscarRED(root->left, data, compFunc, stats);
    }
}

void* buscarRED(t_red *tree, void* data) {
    t_stats* stats = &(tree->stats);
    tree->stats.operationCount++;
    Node* node = __buscarRED(tree->root, data, tree->compFunc, stats);
    return (node != NULL ? node->data : NULL);
}

void estatisticaRED(t_red *tree) {
    t_stats* stats = &(tree->stats);
    printf("Estatisticas:\n\n");
    printf("Numero de operacoes: %d\n\n", tree->stats.operationCount);
    printf("Numero de comparacoes de busca: %d\n", tree->stats.searchComparisons);
    printf("Media de comparacoes de busca por operacao: %.2lf\n\n", (double)tree->stats.searchComparisons / tree->stats.operationCount);
    printf("Numero de comparacoes de insercao: %d\n", tree->stats.insertComparisons);
    printf("Media de comparacoes de insercao por operacao: %.2lf\n\n", (double)tree->stats.insertComparisons / tree->stats.operationCount);
    printf("Numero de comparacoes de remocao: %d\n", stats->removeComparisons);
    printf("Media de comparacoes de remocao por operacao: %.2lf\n\n", (double)tree->stats.removeComparisons / tree->stats.operationCount);
    printf("Numero de rotacoes na insercao: %d\n", stats->insertRotations);
    printf("Media de rotacoes na insercao por operacao: %.2lf\n\n", (double)tree->stats.insertRotations / tree->stats.operationCount);
    printf("Numero de rotacoes na remocao: %d\n", tree->stats.removeRotations);
    printf("Media de rotacooes na remocao por operacao: %.2lf\n\n", (double)tree->stats.removeRotations / tree->stats.operationCount);
}

static void __imprimirRED(Node* root, TImprimirARB printFunc) {
    if (root == NULL)
        return;
    __imprimirRED(root->left, printFunc);
    printFunc(root->data);
    __imprimirRED(root->right, printFunc);
}

void imprimirRED(t_red* tree) {
    __imprimirRED(tree->root, tree->printFunc);
}