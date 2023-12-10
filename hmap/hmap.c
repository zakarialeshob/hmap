#include "hmap.h"

/**
 * @brief Creates a new hash map.
 *
 * @return A pointer to the newly created hash map.
 */

Hmap* creationHmap(){
    Hmap* m = malloc(sizeof(Hmap));
    if(m==NULL){
        printf("Error in malloc of hash map");
        exit(3);
    }
    m->size=0;
    m->pRoot=NULL;
}

/**
 * @brief Adds a key-value pair to the hash map.
 *
 * @param value The value to add.
 * @param name The key associated with the value.
 * @param H The hash map to add the key-value pair to.
 * @return 1 if the key is added successfully, 0 otherwise.
 */
int addHmap(char* value, char* name, Hmap* H){
    int result;
    if(H==NULL || value == NULL || name == NULL ){
        printf("error while creating Hmap\n");
        exit(9);
    }
    H->pRoot=addABR(name, value, Hash(name), H->pRoot,&result);
    if(result==1) H->size++;
    return result;
}
/**
 * @brief Gets the size of the hash map.
 *
 * @param H The hash map.
 * @return The size of the hash map.
 */
int getSize(Hmap* H){
    return H->size;
}
/**
 * @brief Updates the value associated with a key in the hash map.
 *
 * @param H The hash map.
 * @param name The key to update.
 * @param nameudpt The new value associated with the key.
 * @return 1 if the update is successful, 0 otherwise.
 */

int updateHmap(Hmap* H, char* name,char* nameudpt){
  ABR* a=H->pRoot;
  if(a==NULL){
    printf("erreur\n");
    return 0;
  }
  Node* temp = a->couple;
  if(temp==NULL){
    printf("couple inexistant");
    return 0;
  }
  temp=rechercheHmap(a, name);
  printf("valeur originale: %s|%s\n", temp->key, temp->value);
  temp->value = nameudpt;
  printf("valeur mise a jour: %s|%s\n", temp->key, temp->value);
  return 1;
}
/** 
* @brief Removes a node with the specified key from the linked list.
*
* @param n The head of the linked list.
* @param name The key to remove.
* @return The head of the modified linked list.
*/

// Fonction récursive pour supprimer un nœud de l'ABR

/**
 * @brief Recursively frees the memory occupied by a linked list.
 *
 * @param node The head of the linked list.
 * @return 1 if successful, 0 otherwise.
 */
int freeNode(Node* node) {
    printf("on est la\n");
    if (node==NULL){
        return 0;
    }
    if (node != NULL){ 
        while(node->next!=NULL){
        Node* temp = node;
            free(node);
            freeNode(temp->next);
        }
        free(node);
        return 1;
    }
}
/**
 * @brief Recursively frees the memory occupied by an ABR tree.
 *
 * @param root The root of the ABR tree.
 */
void freeABR(ABR* root) {
    printf("ici\n");
    if (root != NULL) {
        freeNode(root->couple);
        freeABR(root->fd);
        freeABR(root->fg);
        free(root);
    }
}
/**
 * @brief Frees the memory occupied by a hash map.
 *
 * @param h The hash map to free.
 */
void freeHmap(Hmap* h) {
    printf("par la\n");
    if (h != NULL) {
        freeABR(h->pRoot);
        free(h);
    }
}
/**
 * @brief Checks if a key exists in the hash map.
 *
 * @param H The hash map.
 * @param name The key to check.
 * @return 1 if the key is found, 0 otherwise.
 */

int getHM(Hmap* H, char* name){
    if (rechercheHmap(H->pRoot,name)==NULL){
        printf("%s pas trouvé :(",name);
        return 0;
    }
    else{
        printf("%s trouvé !\n", name); 
        return 1;
    }
}
/**
 * @brief Displays the content of the hash map.
 *
 * @param H The hash map to display.
 */
void displayHmap(Hmap* H){
    displayABR(H->pRoot);
}