#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED


#define null        NULL
//#define first(L)    L.first
#define next(P)     P->next
#define info(P)     P->info

#include <stdlib.h>
#include "searchF.h"
///Define type address is pointer to node
typedef struct node     *address;
//typedef address         soup[101]; ///Codename *scraped idea*
struct infotype {
    string name;
    string ID;
};
///node in Parent's and child's list
struct node {
    address     next;
    infotype    info;
};
///SLL + no Last pointer
struct ListP {
    address first;
};

///CSLL + no Last pointer
struct ListC {
    address first;
};

address allocateM();
void dealocate(address &P);
void createListP(ListP &L);
void deleteListP(ListP &L);
void deleteListC(ListC &L);
void createListC(ListC &C);
void insertFirstP(address P,ListP &L);
void insertFirstC(address P,ListC &L);
void insertAfterP(address P,address prec,ListP &L);
void insertAfterC(address P,address prec,ListC &L);
void insertLastP(address P,ListP &L);
void insertLastC(address P,ListC &L);
void deleteFirstP(address &P,ListP &L);
void deleteFirstC(address &P,ListC &L);
void deleteAfterP(address &P,address prec,ListP &L);
void deleteAfterC(address &P,address prec,ListC &L);
void deleteLastP(address &P,ListP &L);
void deleteLastC(address &P,ListC &L);

#endif // MULTI_H_INCLUDED
