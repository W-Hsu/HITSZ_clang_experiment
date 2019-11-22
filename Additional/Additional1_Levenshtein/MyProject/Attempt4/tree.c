#include "tree.h"

tree *makeNode(tree *_father, char _content) {
    tree *p = malloc(sizeof(tree));
    p->content = _content;
    p->childQuantity = 0;
    return _father->child[(_father->childQuantity)++] = p;
}

int findNode(tree *_father, char _content) {
    int i=0;
    for (i=0 ; i<(_father->childQuantity) ; i++) if ((_father->child[i]->content)==_content) return i;
    return -1;
}

void delTree(tree *_father) {
    if ((_father->childQuantity)==0) {
        free(_father);
        return;
    }
    else {
        unsigned long i=0;
        for (i=0 ; i<(_father->childQuantity) ; i++) delTree(_father->child[i]);
        _father->childQuantity = 0;
        free(_father);
        return;
    }
}

void addWord(const char *filepath, tree *_root) {
    FILE *fp = fopen(filepath, "r");
    while (!feof(fp)) {
        int i=0;
        char word[30] = {0};

        fgets(word, 30, fp);
        word[strlen(word)-1] = '\0';

        tree *present = _root;
        for (i=0 ; word[i]!='\0' ; i++) {
            int pos = findNode(present, word[i]);
            if (pos==-1) present = makeNode(present, word[i]);
            else present = present->child[pos];
        }
        int pos = findNode(present, '\0');
        if (pos==-1) present = makeNode(present, '\0');
    }
}

int SearchDict(tree *_root, const char *_cmp) {
    int i=0;
    tree *present = _root;
    for (i=0 ; 1 ; i++) {
        int pos = findNode(present, _cmp[i]);
        if (pos==-1) return -1;
        else present = present->child[pos];

        if (present->content=='\0') return 1;
    }
}
