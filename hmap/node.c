#include "node.h"

/**
 * @brief Creates a new linked list node with the given key and value.
 *
 * @param val The value to be associated with the node.
 * @param k The key to be associated with the node.
 * @return A pointer to the newly created linked list node.
 */
Node* creationNode(char* val, char* k) {
    printf("Step 1\n");
    Node* n;
    n = malloc(sizeof(Node));
    printf("Step 1 successful\n");
    printf("Step 2\n");
    if (n == NULL) {
        printf("Error in malloc of node");
        exit(-1); // returns -1 if node isn't created successfully
    }
    printf("Step 2 successful\n");
    n->value = val;
    n->key = k;
    printf("Step 3\n");
    return n;
}

/**
 * @brief Generates a hash value for a given string.
 *
 * @param c The string to calculate the hash value for.
 * @return The hash value for the given string.
 */
int Hash(char* c) {
    int h = 0;
    while (*c) {
        h += *c;
        c++;
    }
    return h;
}

/**
 * @brief Adds a key-value pair to the linked list.
 *
 * @param name The key to add.
 * @param value The value associated with the key.
 * @param n The head of the linked list.
 * @param result Pointer to a variable indicating the result of the addition (1 if successful, 0 otherwise).
 * @return A pointer to the modified linked list.
 */
Node* addNode(char* name, char* value, Node* n, int* result) {
    printf("Node address %p", result);
    // exit(99);
    if (n == NULL) {
        n = creationNode(value, name);
        if (n == NULL) {
            printf("Error while adding node");
            exit(8);
        }
        return n;
    }
    if (n != NULL) {
        if (strcmp(n->key, name) == 0) {
            printf("The element already exists in the list");
            *result = 0;
            return n;
        } else {
            n->next = addNode(value, name, n->next, result);
            if (n->next == NULL) {
                printf("Error during node addition");
                exit(24);
            }
            *result = 1;
            return n;
        }
    }
}

/**
 * @brief Checks if a node with the specified key exists in the linked list.
 *
 * @param n The head of the linked list.
 * @param name The key to search for.
 * @return A pointer to the node with the specified key, or NULL if not found.
 */
Node* ifExistSame(Node* n, char* name) {
    Node* temp = n;
    printf("%s|%s", n->key, n->value);
    if (temp == NULL) return NULL;
    if (strcmp(temp->key, name) == 0) return n;
    else return ifExistSame(temp->next, name);
}

/**
 * @brief Adds a new node to the end of the linked list.
 *
 * @param name The key of the new node.
 * @param value The value of the new node.
 * @param n The head of the linked list.
 * @return A pointer to the modified linked list.
 */
Node* collision(char* name, char* value, Node* n) {
    if (n == NULL) {
        printf("Missing link error");
        exit(22);
    }
    Node* nv = creationNode(value, name);
    Node* temp = n;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nv;
    return n;
}
