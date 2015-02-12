/*************************************************************************
	> File Name: tree.h
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Feb 2015 12:05:53 PM PST
 ************************************************************************/

#ifndef _TREE_H
#define _TREE_H


typedef enum {
    red,
    black
}color;

struct n{
    int value;
    color c;
    struct n* lc;
    struct n* rc;
    struct n* parent;
};
typedef struct n node;

typedef struct{
    node* root;
    int nodeNum;
}tree;

int insert( tree* t , int value );
int delete( tree* t , int value );
tree* create();

node* sibling(node* n);
node* parent (node* n);
node* grandpa(node* n);
node* precursor(node* n);
node* succeed(node* n);
node* locate(node* n);
int   color(node* n);
int   insertFix(tree* t , node* n);

node* rRotate(tree* t , node* n);
node* lRotate(tree* t , node* n);
void replace_node(rbtree t, node oldn, node newn);


#endif
