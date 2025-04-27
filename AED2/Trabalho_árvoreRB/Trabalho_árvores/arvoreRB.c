#include <stdio.h>
#include <stdlib.h>
#include "arvoreRB.h"
t_red* createARB() {
    t_red* tree = (t_red*)malloc(sizeof(t_red));
    tree->root = NULL;
    tree->operationCount = 0;
    tree->searchComparisons = 0;
    tree->insertComparisons = 0;
    tree->removeComparisons = 0;
    tree->insertRotations = 0;
    tree->removeRotations = 0;
    return tree;
}
// Função auxiliar para criar um novo nó
Node* createNode(void* data, Color color, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->color = color;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função auxiliar para contar comparações
void countComparisons(t_red* tree, int operationType) {
    tree->operationCount++;
    switch (operationType) {
        case 0: // Busca
            tree->searchComparisons++;
            break;
        case 1: // Inserção
            tree->insertComparisons++;
            break;
        case 2: // Remoção
            tree->removeComparisons++;
            break;
    }
}
// Função auxiliar para contar rotações
void countRotations(t_red* tree, int operationType) {
    switch (operationType) {
        case 1: // Inserção
            tree->insertRotations++;
            break;
        case 2: // Remoção
            tree->removeRotations++;
            break;
    }
}
// Função auxiliar para realizar uma rotação à esquerda
void rotateLeft(t_red* tree, Node* node) {
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

// Função auxiliar para realizar uma rotação à direita
void rotateRight(t_red* tree, Node* node) {
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
// Função auxiliar para reequilibrar a árvore após uma inserção
void fixInsertion(t_red* tree, Node* node) {
    while (node->parent != NULL && node->parent->color == RED) {
        Node* grandparent = node->parent->parent;
        if (node->parent == grandparent->left) {
            Node* uncle = grandparent->right;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    rotateLeft(tree, node);
                }
                node->parent->color = BLACK;
                grandparent->color = RED;
                rotateRight(tree, grandparent);
            }
        } else {
            Node* uncle = grandparent->left;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotateRight(tree, node);
                }
                node->parent->color = BLACK;
                grandparent->color = RED;
                rotateLeft(tree, grandparent);
            }
        }
    }
    tree->root->color = BLACK;
}

// Função para inserir um nó na árvore
void insertNode(t_red* tree, void* data, int (*compare)(void*, void*)) {
    Node* newNode = createNode(data, RED, NULL);
    Node* current = tree->root;
    Node* parent = NULL;

    countComparisons(tree, 1);

    while (current != NULL) {
        parent = current;

        countComparisons(tree, 1);

        if (compare(data, current->data) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (parent == NULL) {
        tree->root = newNode;
    } else if (compare(data, parent->data) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    newNode->parent = parent;
    fixInsertion(tree, newNode);
}

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

// Função auxiliar para reequilibrar a árvore após uma remoção
void fixRemoval(t_red* tree, Node* node, Node* parent) {
    Node* sibling;
    while ((node == NULL || node->color == BLACK) && node != tree->root) {
        if (node == parent->left) {
            sibling = parent->right;
            if (sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                rotateLeft(tree, parent);
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
                    rotateRight(tree, sibling);
                    sibling = parent->right;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->right != NULL) {
                    sibling->right->color = BLACK;
                }
                rotateLeft(tree, parent);
                node = tree->root;
                break;
            }
        } else {
            sibling = parent->left;
            if (sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                rotateRight(tree, parent);
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
                    rotateLeft(tree, sibling);
                    sibling = parent->left;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->left != NULL) {
                    sibling->left->color = BLACK;
                }
                rotateRight(tree, parent);
                node = tree->root;
                break;
            }
        }
    }
    if (node != NULL) {
        node->color = BLACK;
    }
}

// Função para remover um nó da árvore
void removeNode(t_red* tree, void* data, int (*compare)(void*, void*)) {
    Node* current = tree->root;
    Node* node = NULL;
    Node* parent = NULL;
    Node* child = NULL;

    countComparisons(tree, 2);

    while (current != NULL) {
        if (compare(data, current->data) == 0) {
            node = current;
            break;
        }

        parent = current;

        countComparisons(tree, 2);

        if (compare(data, current->data) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (node == NULL) {
        return; // O nó não existe na árvore
    }

    countComparisons(tree, 2);

    if (node->left == NULL || node->right == NULL) {
        child = node;
    } else {
        child = findMinimum(node->right);
    }

    if (child->left != NULL) {
        parent = child->left;
    } else {
        parent = child->right;
    }

    if (parent != NULL) {
        parent->parent = child->parent;
    }

    if (child->parent == NULL) {
        tree->root = parent;
    } else if (child == child->parent->left) {
        child->parent->left = parent;
    } else {
        child->parent->right = parent;
    }

    if (child != node) {
        node->data = child->data;
    }

    if (child->color == BLACK) {
        fixRemoval(tree, parent, child);
    }

    free(child);
}

// Função auxiliar para realizar uma busca na árvore
Node* searchNode(Node* node, void* data, int (*compare)(void*, void*), int* comparisons) {
    if (node == NULL || compare(data, node->data) == 0) {
        (*comparisons)++;
        return node;
    }

    (*comparisons)++;

    if (compare(data, node->data) < 0) {
        return searchNode(node->left, data, compare, comparisons);
    } else {
        return searchNode(node->right, data, compare, comparisons);
    }
}

// Função para buscar um valor na árvore
Node* searchValue(t_red* tree, void* data, int (*compare)(void*, void*), int* comparisons) {
    return searchNode(tree->root, data, compare, comparisons);
}

void printStatistics(t_red* tree) {
    printf("Estatisticas da arvore:\n");
    printf("  Numero de operacoes: %d\n", tree->operationCount);
    printf("  Numero de comparacoes de busca: %d\n", tree->searchComparisons);
    printf("  Numero de comparacoes de insercao: %d\n", tree->insertComparisons);
    printf("  Numero de comparacoes de remocao: %d\n", tree->removeComparisons);
    printf("  Numero de rotacoes na insercao: %d\n", tree->insertRotations);
    printf("  Numero de rotacoes na remocao: %d\n", tree->removeRotations);
}

void __printTree(Node* node, void (*print)(void*)) {
    if (node == NULL)
        return;
    __printTree(node->left, print);
    print(node->data);
    __printTree(node->right, print);
}

void printTree(t_red* tree, void (*print)(void*)) {
    __printTree(tree->root, print);
}