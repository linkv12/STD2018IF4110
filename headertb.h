#ifndef HEADERTB_H_INCLUDED
#define HEADERTB_H_INCLUDED

#include<iostream>

#define first(P) P->first
#define next(P) P->next
#define info(P) P->info
#define null NULL
///tipe data baru
struct date {
    int day, month, year;
};
struct infotype {
    string nama, sma, asal, id, bio[10];
    date ttl;
};
typedef struct node *address;
struct node {
    infotype info;
    address next;
};
struct listParent {
    address first;
};
struct listChild {
    address first;
};

void creatlistParent(listParent&L);
void creatlistChild(listChild&L);
address alokasi(infotype X);
void insertFirstParents(listParent&L, address &P);
void insertFirstChild(listChild&L, address &P);
void insertLastParents(listParent&L, address &P);
void insertLastChild(listChild &L, address &P);
void deleteFirstParents(listParent &L, address &P);
void deleteFirstChild(listChild &L, address &P );
void deleteLastParents(listParent &L, address &P);
void deleteLastChild(listChild &L, address &P);
#endif // HEADERTB_H_INCLUDED
