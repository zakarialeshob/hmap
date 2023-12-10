#ifndef ABR_H
#define ABR_H
#include "node.h"

typedef struct abr{
    Node* couple;
    int hash;
    struct abr *fd;
    struct abr *fg;
}ABR;

ABR* creationAbr(Node* n);
ABR* addABR(char* name, char* value, int key, ABR* a, int* result);
void displayABR(ABR* p);
Node* rechercheHmap(ABR* a, char* name);

#endif