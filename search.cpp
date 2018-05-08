//
// Created by link on 26/04/18.
//

#include "search.h"
#include "multi.h"
/// search username
address searchUn (string uname, list  &L) {
    address P = first(L);
    while (P != null) {
        if (info(P).uname == uname) {
            break;
        }
        P = next(P);
    }
    return P;
}

/// Search id
address searchId (string id, list &L) {

}
/// Search parent
address searchParentId (string id, list &L) {
    address P = first(L);
    while (P != null && id != info(P).id) {
        P = next(P);
    }
    return P;
}
/// Search exact parent and child //{parent,child} combo
addr searchPC (string parent,string child, listR &L);
/// Search child
address searchChildId (string id, list &L) {
    address P = first(L);
    do {
        P = next(P);
    } while (P != first(L) && id != info(P).id);
    return P;
}

/// Search a name
address searchParentName (string name, list L) {
    address P = first(L);
    while (P != null && name != info(P).name) {
        P = next(P);
    }
    return P;
}

