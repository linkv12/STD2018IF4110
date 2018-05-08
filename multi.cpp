// Implementation of multi.h
// Created by link on 26/04/18.
//

#include "multi.h"
#include "testValid.h"
#include "debug.h"
#include <stdlib.h>
///Allocate new address manual input
address allocate () {
    /* IF. none
     * FS. a address to node
     * */
    address  P = new node;
        cout << "Name : ";
        cin >> info(P).name;
        cout << "Birth day [dd/mm/yyyy] : ";
        cin >> info(P).bday;
        cout << "Town : ";
        cin >> info(P).town;
        cout << "Country : ";
        cin >> info(P).country;
    return  P;
}
///Allocate new address based on x
address allocate (infotype x) {
    address P = new node;
    info(P) = x;
    next(P) = null;
    return P;
}
///Create a new list
void createlist (list &L) {
    first(L) = null;
}
///Insert a node in the first element on both list
void insertFirst (list &L, list &K, address P) {
    /*  L is parent
     *  K is child
     * */
    if (first(L) == null) {
        first(L) = P;
        next(first(L)) = null;
        convert(L,K);
    } else {
        next(P) = first(L);
        first(L) = P;
        convert(L,K);
    }
}
///Insert a node after a spesific node
void insertAfter (list &L, list &K, string x, address P) {
    /*  L is parent
     *  K is child
     * */
    // wont be utilized
}
///Insert node in the last element
void insertLast(list &L, list &K, address P) {
    /*  L is parent
     *  K is child
     * */
    if (first(L) == null) {
        insertFirst(L,K,P);
    } else {
        address Q = first(L);
        while (next(Q) != null) {
            Q = next(Q);
        }
        next(Q) = P;
        convert(L,K);
    }
}
///Delete first node
void deleteFirst (list &L, list &K) {
    cout << "xaxa1" << endl;
    if (next(first(L)) == null) {
        cout << "xaxa2" << endl;
        first(L) = null;
        cout << "xaxa3" << endl;
        convert(L,K);
    } else {
        cout << "xaxa4" << endl;
        address Q = next(first(L));
        next(first(L)) = null;
        first(L) = Q;
        cout << "xaxa5" << endl;
        convert(L,K);
    }
}
///Delete a node after a spesific node
void deleteAfter (address Prec,list &L, list &K) {
    if (first(L) != null && Prec != null) {
        address P = next(Prec);
        next(Prec) = next(P);
        deallocate(P);
        convert(L,K);
    }
}
///Delete last node
void deleteLast (list &L, list &K) {
    if (next(first(L)) == null) {
        deleteFirst(L,K);
    } else {
        address P = first(L);
        while (next(P) != null) {
            P = next(P);
        }
        deallocate(next(P));
        next(P) = null;
        convert(L,K);
    }
}
/// De-alokasi node
void deallocate (address &P) {
    delete P;
}
/// Will turn a SLL to CSLL (L to K) or something like that
void convert (list &L, list &K) {

    address P = first(L);
    createlist(K);
    while (P != null) {
        address Q = allocate(info(P));
        insertFirst(K, Q);
        //debug
        P = next(P);
    }
}

/// A normal insert first for circullar
void insertFirst (list &L, address P) {
    if (first(L) == null) {
        first(L) = P;
        next(P) = P;
    } else {
        address Q = first(L);
        while (next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        first(L) = P;
        next(Q) = P;
    }
}

/// Show all node in a list
void showAll (list L) {
    address P = first(L);
    do {
        printInfo(P);
        P = next(P);
    } while (P != null && P != first(L));
}

/// Print info(P)
void printInfo(address P) {
    cout << "Username : " <<info(P).uname << endl;
    cout << "Name : " <<info(P).name << endl;
    cout << "Town : "<<info(P).town << endl;
    cout << "Country :"<<info(P).country << endl;
    cout << "Birth Day : "<<info(P).bday << endl;
    cout << "ID : "<<info(P).id << endl;
    cout << "Gender : " << info(P).gender << endl;
    cout << "Age : " << info(P).age << endl;
   // cout << "***debug***" << endl;
}

/// Assign ID
void assignID (address &P,list &L) {
    /// string to create ID
    char data[37] = "0123456789abcdefghijklmnopqrstuvwxyz";
    info(P).id = "";
    address Q = first(L);
    if (first(L) != null) {
        while (Q != null) {
            if (info(P).uname != info(Q).uname) {
                if (info(P).id == "" || info(P).id == info(Q).id) {
                    for (int i = 0; i <= 9; i++) {
                        int x = rand() % 36;
                        info(P).id += data[x];
                    }
                }
                Q = next(Q);
            }
        }
    } else if (first(L) == null) {
        for (int i = 0; i <= 9; i++) {
            int x = rand() % 36;
            info(P).id += data[x];
        }
    }
}

/// Print all gender
void printAllGender (list L, string arg) {
    address P = first(L);
    if (first(L) != null) {
        while (P != null) {
            if (info(P).gender == arg) {
                printInfo(P);
                cout << endl;
                line ("-");
            }
            P = next(P);
        }
    }
}

/// Print all from a specific town
 void printAllTown(string town,list L) {
    address P = first(L);
    if (first(L) != null) {
        while (P != null) {
            if (info(P).town == town) {
                printInfo(P);
                cout << endl;
            }
            P = next(P);
        }
    }
 }
/// Print all from a specific country
 void printAllCountry(string country,list L) {
   address P = first(L);
    if (first(L) != null) {
        while (P != null) {
            if (info(P).country == country) {
                printInfo(P);
                cout << endl;
            }
            P = next(P);
        }
    }
 }
