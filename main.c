#include "node.h"
#include "hmap.h"
#include "abr.h"



int main(){
    int result;
    Hmap* H=creationHmap();
    H->size=0;
    printf("Hmap créée\n");
    result=addHmap("blabla","travis",H);
    result=addHmap("blablabla","maria",H);
    result=addHmap("blaa","marius",H);
    result=addHmap("blablab","bowser",H); 
    displayABR(H->pRoot);
    printf("taille de la hashmap : %d\n", getSize(H));
    printf("\naddHmap succès\n");
    displayABR(H->pRoot);
    printf("taille de la hashmap : %d\n", getSize(H));
    updateHmap(H, "maria","mariam");
    displayABR(H->pRoot);
    return 0;
}