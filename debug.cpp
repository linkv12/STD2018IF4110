//
// Created by linkv12 on 29/04/18.
//

#include "debug.h"
#include "multi.h"
#include "ui.h"
#include "relation.h"
#include "search.h"

/// Print Id in parent list
void printId (list &L) {
    address P = first(L);
    while (P != null) {
        cout << " Id : " << info(P).id << endl;
        P = next(P);
    }
}

/// Print all database
void printAll (list L) {
    address P = first(L);
    while (P != null) {
        printInfo(P);
        P = next(P);
    }
}