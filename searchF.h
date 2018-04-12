/**Contain searches function
***One time use only
***All the list won't be permanent
***/
#ifndef SEARCHF_H_INCLUDED
#define SEARCHF_H_INCLUDED
#include <iostream>
#include "multi.h"
///S stands for search node
typedef struct node *address;
typedef struct nodeS *addressT;
struct nodeS {
    address info;
    addressT next; /// AddressT T is for temporary
};

///A single linked list which contains list of address found throughout the search
struct ListS {
    addressT first;
};
addressT allocate(address P);
void dealocate (addressT &P);
///Create ListS
void createListS(ListS &L);
void uncreateListS(ListS &L);
///Find an address in Parent's List based on a string ??ID ?
address searchP(string x,ListP L);
///Find an address in Child's List based on a string ??ID ?
address searchC(string x,ListC L);
///Return a list contain 101 address (Super Search)
void suSearchP(string x,ListP L,ListS &M);
void suSearchC(string x,ListC L,ListS &M);

#endif // SEARCHF_H_INCLUDED
