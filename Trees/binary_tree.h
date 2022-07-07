/*
 ==============================
 Name         : binary_trees.h
 Author       : Charles T.
 Version      : 1.0
 Copyright    : by default
 Description  : binary trees
 ==============================
*/

#ifndef _TREE_H_
#define _TREE_H_

typedef struct      s_btree
{
    struct s_btree  *left;
    struct s_btree  *right;
    void            *elem;
}                   t_btree;

#endif