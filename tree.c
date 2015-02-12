/*************************************************************************
	> File Name: tree.c
	> Author: 
	> Mail: 
	> Created Time: Tue 03 Feb 2015 01:41:57 PM PST
 ************************************************************************/

#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

#define LOG(str,...) fprintf(stdout,str,##__VA_ARGS__)
#define LOGE(str) perror(str)
#define NEW(t) (t*)malloc(sizeof(t))

int insert( tree* t , int value ){
    node* new = NEW(node);

    new->value = value;
    new->c = red;
    new->lc = NULL;
    new->rc = NULL;

    if(t->root == NULL)
        t->root = new;
    else{
        node* t = t->root ;
        while( t != NULL ){
            if( t->value > new->value )
            {
                if( t->lc == NULL )
                {
                    t->lc = new;
                    new->parent = t;
                    break;
                }

                t = t->lc;
            }else{
                if( t->rc == NULL )
                {
                    t->rc = new;
                    new->parent = t;
                    break;
                }
                t = t->rc;
            }
        }     
    }
    insertFix(new);
}
int delete( tree* t , int value );
tree* create(){
    tree* t = NEW(tree);

    tree->root = NULL;
    tree->nodeNum = 0;
    return t;
}
node* sibling(node* n){
    assert(n);
    return n == parent(n)->lc ? parent(n)->rc : parent(n)->lc;
}
node* parent (node* n){
    assert(n);
    return n->parent;
}
node* grandpa(node* n){
    assert(n);
    return parent(parent(n));
}
node* precursor(node* n);
node* uncle(node* n){
    assert(n);
    return parent(n) == grandpa(n)->lc ? grandpa(n)->rc : grandpa(n)->lc;
}
node* succeed(node* n){}
node* locate(node* n){}
int   color(node* n){
    return n == NULL ? black : n->c ;
}
int   insertFix(tree* t , node* n){
    if( n->parent == NULL )
    {
        n->c = black;
        return 0;
    }
    if( color(n->parent) == black )
        return 0;
    else
    {
        if( color( uncle(n) ) == red )
        {//父亲和叔父节点均为红色
            uncle(n)->c = black;
            parent(n)->c = black;
            grandpa(n)->c = red;
            n = grandpa(n);
        }else if( color(uncle(n)) == black  )
        {
            if(  n == parent(n)->lc &&  parent(n) == grandpa(n)->rc ){
                //n为左子节点，n的父亲为右子节点
                rRotato(t,Parent(n));
                n = n->rc;
            }
            else if (  n == parent(n)->rc &&  parent(n) == grandpa(n)->lc ){
                //n为右子节点，n的父亲为左子节点
                lRotato(t,Parent(n));
                n = n->lc;
            }

            if(   n == parent(n)->lc &&  parent(n) == grandpa(n)->lc ){
                //n和n的父亲都为左子节点
                parent(n)->c = black;
                grandpa(n)->c = red;
                rRotato(t,grandpa(n));

            }
            else if(   n == parent(n)->rc &&  parent(n) == grandpa(n)->rc ){
                //n和n的父亲都为右子节点
                parent(n)->c = black;
                grandpa(n)->c = red;
                lRotato(t,grandpa(n));
            }

        
        }
             
    }
    
}

node* rRotate(tree* t , node* n){
    node* lchild = n->lc;
    assert(n);

    replace_node(t,n,lchild);
    if( lchild->rc != NULL ){
        lchild->rc->parent = n;
        n->lc = lchild->rc;
    }
    
    lchild->rc = n;
    n->parent = lchild;

}
node* lRotate(tree* t , node* n){
    node* rchild = n->rc;
    assert(n);

    replace_node(t,n,rchild);
    if( rchild->lc != NULL ){
        lchild->lc->parent = n;
        n->rc = lchild->lc;
    }
    
    rchild->lc = n;
    n->parent = rchild;

}
void replace_node(tree* t, node oldn, node newn) {
    if (oldn->parent == NULL) {
                t->root = newn;
            
    } else {
                if (oldn == oldn->parent->left)
                    oldn->parent->left = newn;
                else
                    oldn->parent->right = newn;
            
    }
    if (newn != NULL) {
                newn->parent = oldn->parent;
            
    }

}
