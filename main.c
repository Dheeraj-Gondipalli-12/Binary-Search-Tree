#include <stdio.h>
#include <stdlib.h>
#include "tree_node.h"


node_t *createNode(int value)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int addNode(node_t **root, int value)
{
    if(*root == NULL)
    {
        *root = createNode(value);
        return SUCCESS;
    }
    if((*root)->value > value)
    {
        addNode(&((*root)->left), value);
    }
    if((*root)->value < value)
    {
        addNode(&((*root)->right), value);
    }

    return NODE_CREATE_ERR;
}

node_t *searchNode(node_t *root, int value)
{
    if(root->value == value)
    {
        return root;
    }
    else if(root->value > value && root->left != NULL)
    {
        searchNode(root->left, value);
    }
    else if(root->value < value && root->right)
    {
        searchNode(root->right, value);
    }

    return NULL;
}

void freeTree(node_t *root)
{
    if(root != NULL)
    {
        freeTree(root->left);
        free(root->left);
        freeTree(root->right);
        free(root->right);
        free(root);
    }
}

void preOrderTraversal(node_t *root)
{
    if(root != NULL)
    {
        printf("%d ", root->value);
        preOrderTraversal(root->right);
        preOrderTraversal(root->left);
    }
}

void postOrderTraversal(node_t *root)
{
    if(root != NULL)
    {
        postOrderTraversal(root->right);
        postOrderTraversal(root->left);
        printf("%d ", root->value);
    }
}

void inOrderTraversal(node_t *root)
{
    if(root != NULL)
    {
        inOrderTraversal(root->right);
        printf("%d ", root->value);
        inOrderTraversal(root->left);
    }
}

int main()
{
    node_t *root = createNode(7);
    int i, value;
    for(i = 0; i < 8; i++)
    {
        printf("Enter the value: ");
        scanf("%d", &value);
        addNode(&root, value);
    }

    printf("Pre order traversal: ");
    preOrderTraversal(root);
    printf("\n");
    printf("Post order traversal: ");
    postOrderTraversal(root);
    printf("\n");
    printf("In order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}