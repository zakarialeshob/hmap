#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char* value;
    char* key;
    struct node *next;
}Node;

Node* creationNode(char* val, char* k);
int Hash(char* c);
Node* addNode(char* name, char* value, Node* n, int* result);
Node* ifExistSame(Node* n,char* name);
Node* collision(char* name,char* value, Node* n);

#endif