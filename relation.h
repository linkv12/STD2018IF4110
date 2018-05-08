// mhhm
// Created by linkv12 on 26/04/18.
//

#ifndef TUBES_RELATION_H
#define TUBES_RELATION_H

#include "multi.h"


///  A pointer to elm
typedef struct elm *addr;

/// An info
struct typeinfo {
    string parent, child;
};

/// Elm datatype
struct elm {
    address parent,child;
    typeinfo  info;
    addr next,prev;
};

/// a double linked list
struct listR  {
    addr first,last;
};

/// Allocate a new elm
addr allocate (string idP, string idC, address parent, address child);
/// Allocate a new elm using parent & child list
addr allocate (string idP, string idC, list &L, list &K);
/// Create new listR
void createlist (listR &L);
/// De-Allocate an elm
void deallocate (addr &P);
/// Disconnect node
void disconnect (string a, string b, listR &R);
/// Connect node
void connect (string a, string b, list parent, list child, listR &L);
/// Discoonet elm that point to a certain id
void disconnectVertex (string id,list &L,list &K ,listR &R);
/// Delete first
void deleteFirst (listR &R);
/// Delete last
void deleteLast (listR &R);
/// Delete an elm
void deleteElm (string a, string b, listR &L);
/// delete after
void deleteAfter(addr Prec, listR &R);
/// Insert first
void insertFirst (addr P, listR &L);
/// Show all relation
void showRelation (listR &R);
/// Print info in addr
void printInfo (addr P);
/// isAlready a friend ?
bool isFriend (string id, string uname, list L, listR R);
/// update relation list
void updateRelation (list L,list K, listR &R);
/// Show All friend
void showAllFriend(string id,listR R);
/// Show all friend with specified gender
void printAllFriendGender (string id, string arg,listR R);
/// Show all friend with specific town
void printAllFriendTown (string id, string town,listR R);
/// Show all friend with specific country
void printAllFriendCountry (string id, string country,listR R);

#define null NULL
#define first(P) P.first
#define last(P) P.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define parent(P) P->parent
#define child(P) P->child


#endif //TUBES_RELATION_H
