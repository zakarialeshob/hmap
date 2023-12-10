#ifndef HMAP_H
#define HMAP_h
#include "node.h"
#include "abr.h"

typedef struct hmap{
    int size;
    ABR* pRoot;
}Hmap;

Hmap* creationHmap();
int addHmap(char* value, char* name, Hmap* H);
int getSize(Hmap* H);
int updateHmap(Hmap* H, char* name, char* nameupdt);
int freeNode(Node* node);
void freeABR(ABR* root);
void freeHmap(Hmap* h);

#endif