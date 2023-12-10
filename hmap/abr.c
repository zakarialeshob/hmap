#include "abr.h"

/**
 * @brief Creates a new ABR node with the given linked list node.
 *
 * @param n The linked list node to associate with the ABR node.
 * @return A pointer to the newly created ABR node.
 */
ABR* creationAbr(Node* n) {
    printf("Step 1\n");
    if (n == NULL) {
        printf("Invalid node\n");
        exit(2);
    }
    printf("Step 1 successful\n");

    ABR* a = malloc(sizeof(ABR));
    if (a == NULL) {
        printf("Error in malloc of ABR\n");
        exit(1); // returns 1 if ABR isn't created successfully
    }
    printf("Step 2\n");
    a->couple = n;
    printf("Step 2 successful\n");
    printf("Step 3\n");
    a->hash = Hash(n->key);
    a->fd = NULL;
    a->fg = NULL;
    printf("Step 3 successful\n");
    printf("ABR address %p\n", a);
    printf("Step 4 return\n");
    return a;
}

/**
 * @brief Adds a key-value pair to the ABR tree.
 *
 * @param name The key to add.
 * @param value The value associated with the key.
 * @param key The hash value of the key.
 * @param a The ABR tree to add the key-value pair to.
 * @param result Pointer to a variable indicating the result of the addition (1 if successful, 0 otherwise).
 * @return A pointer to the modified ABR tree.
 */
ABR* addABR(char* name, char* value, int key, ABR* a, int* result) {
    printf("%p\n", &result);
    printf("ABR address %p\n", a);
    if (a == NULL) {
        printf("ABR is null\n");
        printf("Testing ABR add\n");
        Node* n = creationNode(value, name);
        printf("Node address: %p\n", n);
        printf("Testing ABR add if it works\n");
        if (n == NULL) {
            printf("Error, I'm done");
            exit(2498);
        }
        a = creationAbr(n);
        if (a == NULL) {
            printf("It still doesn't work");
            exit(95);
        }
        *result = 1;
        return a;
    } else if (key > a->hash) {
        a->fd = addABR(name, value, Hash(name), a->fd, result);
    } else if (key < a->hash) {
        a->fg = addABR(name, value, Hash(name), a->fg, result);
    } else if (key == a->hash) {
        if (ifExistSame(a->couple, name) != NULL) {
            printf("Node already present in the list");
            *result = 0;
            return a;
        }
        a->couple = collision(name, value, a->couple);
    } // else the node is found, go to node->next
    return a;
}

/**
 * @brief Displays the content of the ABR tree.
 *
 * @param p The root of the ABR tree.
 */
void displayABR(ABR* p) {
    if (p != NULL) {
        printf("%s | %s \n", p->couple->key, p->couple->value);
        if (p->couple->next != NULL) {
            printf("%s | %s \n", p->couple->next->key, p->couple->next->value);
            p->couple = p->couple->next;
        }
        displayABR(p->fg);
        displayABR(p->fd);
    }
}

/**
 * @brief Searches for a key in the ABR tree and returns the corresponding linked list node.
 *
 * @param a The root of the ABR tree.
 * @param name The key to search for.
 * @return A pointer to the linked list node with the specified key, or NULL if not found.
 */
Node* rechercheHmap(ABR* a, char* name) {
    ABR* tmp = a;
    if (tmp == NULL) {
        printf("Non-existent ABR error\n");
        return NULL;
    }
    int hash = Hash(name);
    printf("ABR address: %p\n", &tmp);
    printf("Hash %d and hash name %d\n\n\n", hash, tmp->hash);
    if (tmp->hash == hash) {
        printf("It worked %s found!\n", name);
        printf("%s|%s\n", tmp->couple->key, tmp->couple->value);
        return ifExistSame(tmp->couple, name);
    } else if (tmp->hash > hash) {
        return rechercheHmap(tmp->fg, name);
    } else if (tmp->hash < hash) {
        return rechercheHmap(tmp->fd, name);
    }
}
