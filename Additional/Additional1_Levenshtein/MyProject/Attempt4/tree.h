#include <stdlib.h>
#include <stdio.h>

#define MAX_CHILD_NUM 60

typedef struct _tree {
    struct _tree *child[MAX_CHILD_NUM];
    unsigned long childQuantity;
    char content;
} tree;

tree *makeNode(tree *_father, char _content);

int findNode(tree *_father, char _content);

void delTree(tree *_father);

void addWord(const char *filepath, tree *_root);

int SearchDict(tree *_root, const char *_cmp);
