//
// Created by linkv12 on 26/04/18.
//A header about relation a linked list

#ifndef TUBES_MULTI_H
#define TUBES_MULTI_H



#include <iostream>
using namespace std;
/// pointer to node
typedef struct node *address;
/// infotype a datatype
struct infotype {
    string name;
    string id;
    string town;
    string country;
    string bday;
    string gender;
    int age;
    string pass;
    string uname;   //Username
};
/// Date
struct date {
    int day,month,year;
};
/// node in a linked list
struct node {
    infotype info;
    address  next;
};

/// a single linked list [parent] & a Circular single linked list [child]
/* New idea
 * have a same type for parent and child list
 *
 * let's see how it work
 * pretty well
 * */
struct list {
    address first;
};
///Allocate new address manual input
address allocate ();
///Allocate new address based on x
address allocate (infotype x);
///Create a new list
void createlist (list &L);
///Insert a node in the first element on both list
void insertFirst (list &L, list &K, address P);
///Insert a node after a spesific node
void insertAfter (list &L, list &K, string x, address P);
///Insert node in the last element
void insertLast(list &L, list &K, address P);
///Delete first node
void deleteFirst (list &L, list &K);
///Delete a node after a spesific node
void deleteAfter (address Prec,list &L, list &K);
///Delete last node
void deleteLast (list &L, list &K);
/// De-alokasi node
void deallocate (address &P);
/// Will turn a SLL to CSLL (L to K) or something like that
void convert (list &L, list &K);
/// A normal insert first
void insertFirst (list &L, address P);
/// Show all node in a list
void showAll (list L);
/// Print info(P)
void printInfo(address P);
/// Assign ID
void assignID (address &P,list &L);
/// Print all gender
void printAllGender (list L, string arg);
/// Print all from a specific town
 void printAllTown(string town,list L);
/// Print all from a specific country
 void printAllCountry(string country,list L);

#define null NULL
#define first(P) P.first
#define info(P) P->info
#define next(P) P->next

#endif //TUBES_MULTI_H
