/*
 ==============================
 Name         : binary_trees.c
 Author       : Charles T.
 Version      : 1.0
 Copyright    : by default
 Description  : binary trees
 ==============================
*/

#include "binary_tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define CYAN "\033[1;36m"
#define NONE "\033[0m"

static int  addition(int *nb)
{
    return (*nb + 1);
}

static t_btree  *btree_create_node(void *item)
{
    t_btree *t = NULL;

    if ((t = (t_btree *)malloc(sizeof(t_btree))) == NULL) {
        fprintf(stderr, "Malloc failed, create_node.\n");
        exit(EXIT_FAILURE);
    }
    t->elem = item;
    t->left = NULL;
    t->right = NULL;
    return t;
}

static void btree_insert_data(t_btree **root, void *item)
{
    t_btree *node = NULL;

    if (*root == NULL) {
        printf(" ---> Insert value: %d\n", *(int *)(item));
        if ((node = (t_btree *)malloc(sizeof(t_btree))) == NULL) {
            fprintf(stderr, "Malloc failed, insert_data.\n");
            exit(EXIT_FAILURE);
        }
        node->elem = item;
        node->left = NULL;
        node->right = NULL;
        *root = node;
    }
    else {
        if (*(int *)(item) < *(int *)((*root)->elem)) {
            printf("\n%d --- %d ---> the smallest.", *(int *)(item), *(int *)((*root)->elem));
            btree_insert_data(&((*root)->left), item);
        }
        else {
            printf("\n%d --- %d --->the biggest.", *(int *)(item), *(int *)((*root)->elem));
            btree_insert_data(&(*root)->right, item);
        }
    }
}

static void btree_apply_prefix(t_btree *root, int (*f)(void *))
{
    t_btree *node = root;

    if (node != NULL) {
        printf("Node value: %d ---> ", *(int *)((node)->elem));
        printf("Node processing: %d\n", (*f)((int *)(node)->elem));
        btree_apply_prefix(node->left, f);
        btree_apply_prefix(node->right, f);
    }
}

static void btree_apply_infix(t_btree *root, int (*f)(void *))
{
    t_btree *node = root;

    if (node != NULL) {
        btree_apply_infix(node->left, f);
        printf("Node value: %d ---> ", *(int *)((node)->elem));
        printf("Processing node: %d\n", (*f)((int *)(node)->elem));
        btree_apply_infix(node->right, f);
    }
}

static void btree_apply_postfix(t_btree *root, int (*f)(void *))
{
    t_btree *node = root;

    if (node != NULL) {
        btree_apply_postfix(node->left, f);
        btree_apply_postfix(node->right, f);
        printf("Node value: %d ---> ", *(int *)((node)->elem));
        printf("Processing node: %d\n", (*f)((int *)(node)->elem));
    }
}

static void free_binary_tree(t_btree *root)
{
    if (root != NULL) {
        free_binary_tree(root->left);
        free_binary_tree(root->right);
        free(root);
    }
}

int     main(void)
{
    t_btree *tree = NULL;
    int     tab[] = {11, 3, 5, 7, 2, 23, 101, 53, 19, 29};
    int     root = 10;
    int     i = 0;

    printf("%sTest btree_create_node function.%s", CYAN, NONE);
    tree = btree_create_node(&root);
    printf("%s\n\nTest btree_insert_data function.%s", CYAN, NONE);
    for (i = 0; i < 10; i++) {
        btree_insert_data(&tree, &tab[i]);
    }
    putchar('\n');
    printf("%s\n\nTest btree_apply_prefix function.%s\n\n", CYAN, NONE);
    btree_apply_prefix(tree, (int (*)(void *))(addition));
    putchar('\n');
    printf("%s\n\nTest btree_apply_infix function.%s\n\n", CYAN, NONE);
    btree_apply_infix(tree, (int (*)(void *))(addition));
    putchar('\n');
    printf("%s\n\nTest btree_apply_postfix function.%s\n\n", CYAN, NONE);
    btree_apply_postfix(tree, (int (*)(void *))(addition));
    putchar('\n');
    free_binary_tree(tree);
    tree = NULL;
    return 0;
}
