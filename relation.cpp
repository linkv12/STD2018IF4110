//
// Created by link on 26/04/18.
//

#include "relation.h"
#include "search.h"
#include "multi.h"
/// Allocate a new elm
addr allocate (string idP, string idC, address parent, address child) {
    /* info(P) contains id
     * */
    addr P = new elm;
    info(P).parent = idP;
    info(P).child = idC;
    parent(P) = parent;
    child(P) = child;
    next(P) = null;
    prev(P) = null;
    return P;
}
/// Allocate a new elm using parent & child list
addr allocate (string idP, string idC, list &L, list &K) {
    /* L is parent
     * K is Child
     * */
    addr P = new elm;
    info(P).parent = idP;
    info(P).child = idC;
    parent(P) = searchParentId(idP,L);
    child(P) = searchChildId(idC,K);
    next(P) = null;
    prev(P) = null;
    return P;
}
/// Create new listR
void createlist (listR &L) {
    first(L) = null;
    last(L) = null;
}
/// De-Allocate an elm
void deallocate (addr &P) {
    delete P;
}
/// Disconnect node
void disconnect (string a, string b, listR &R) {
    addr P = first(R);
    if (first(R) != null) {
        while (P != null) {
            if (info(P).parent == a && info(P).child == b) {
                if (P == first(R)) {
                    deleteFirst(R);
                    } else if (next(P) == null) {
                    deleteLast(R);
                } else {
                    deleteAfter(prev(P),R);
                }
            }
            if (info(P).parent == b && info(P).child == a) {
                if (P == first(R)) {
                    deleteFirst(R);
                } else if (next(P) == null) {
                    deleteLast(R);
                } else {
                    deleteAfter(prev(P),R);
                }

            }
            P = next(P);
        }
    }
}
/// Connect node
void connect (string a, string b, list parent, list child, listR &L) {
    /* A is id A to B
     * B is id B to A
     * */
    addr P = allocate(a,b,parent,child);
    addr Q = allocate(b,a,parent,child);
    insertFirst(P,L);
    insertFirst(Q,L);
}
/// Disconnect elm that point to a certain id
void disconnectVertex (string id,list &L,list &K ,listR &R) {
    if (first(L) != null) {
        address P = searchParentId(id,L);
        if (next(P) != null) {
            cout << " at last" << endl;
        }
        if (P != null) {
            cout << "yei1" << endl;
            if (P == first(L)) {
                cout << "yei2" << endl;
                deleteFirst(L,K);
                cout << "yei3" << endl;
            } else if (next(P) == null) {
                cout << "yei4" << endl;
                deleteLast(L,K);
                cout << "yei5" << endl;
            } else {
                cout << "watlll99" << endl;
                address Q = first(L);
                while (next(Q) != P && Q != null) {
                    Q = next(Q);
                }
                if (Q != null) {
                    cout << "yei6" << endl;
                    deleteAfter(Q,L,K);
                    cout << "yei7" << endl;
                }
            }
        }
        addr S = first(R);
        while (S != null) {
            if (info(S).parent == id || info(S).child == id) {
                disconnect(id,info(S).child, R);
                disconnect(info(S).child,id, R);
            }
            S = next(S);
        }
        updateRelation(L,K,R);
    }
}
/// Delete first
void deleteFirst (listR &R) {
    if (first(R) != null && first(R) != last(R)) {
        addr P = first(R);
        first(R) = next(P);
        prev(first(R)) = null;
        deallocate(P);
    } else if (first(R) == last(R)) {
        deallocate(first(R));
        first(R) = null;
        last(R) = null;
    }
}
/// Delete last
void deleteLast (listR &R) {
    if (first(R) == last(R)) {
        deallocate(first(R));
        first(R) = null;
        last(R) = null;
    } else {
        addr P = prev(last(R));
        next(P) = null;
        deallocate(last(R));
        last(R) = P;
    }
}
/// Delete an elm
void deleteElm (string a, string b, listR &L) {

}

/// Insert first
void insertFirst (addr P, listR &L) {
    if (first(L) == null && last(L) == null) {
        first(L) = P;
        last(L) = P;
    } else if (first(L) != null){
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

/// Show all relation
void showRelation (listR &R) {
    addr P = first(R);
    while (P != null) {
        printInfo(P);
    }
    cout << endl;
}
/// Print info in addr
void printInfo (addr P) {
    cout << "ID parent :"<< info(P).parent << endl;
    cout << "ID child : "<< info(P).child << endl;
    cout << "From : "<< info(parent(P)).uname << endl;
    cout << "To : " << info(child(P)).uname << endl;
}

/// isAlready a friend ?
bool isFriend (string id, string uname, list L, listR R) {
    //L is parent
    if (first(R) == null) {
        return false;
    } else if (first(R) != null) {
        addr P = first(R);
        string idU;
        address Q = searchUn(uname,L);
        if (Q == null) {
            return false;
        } if (Q != null) {
            idU = info(Q).id;
        }
        while (P != null) {
            if (info(P).parent == id) {
                if (info(P).child == idU) {
                    return true;
                }
            }
            P = next(P);
        }
        if (P == null) {
            return false;
        }
    }
}
/// update relation list
void updateRelation (list L,list K, listR &R) {
    if (first(R) != null) {
        addr P = first(R);
        while (P != null) {
            parent(P) = searchParentId(info(P).parent,L);
            child(P) = searchChildId(info(P).child,K);
            P = next(P);
        }
    }
}

/// delete after
void deleteAfter(addr Prec, listR &R) {
    if (first(R) != null && next(Prec) != last(R)) {
        addr Q = next(next(Prec));
        prev(Q) = Prec;
        addr P = prev(Q);
        deallocate(P);
        next(Prec) = Q;
    } else if (next(Prec) == last(R)) {
        deleteLast(R);
    }
}

/// Show All friend
void showAllFriend(string id,listR R) {
    addr P = first(R);
    int i = 1;
    if (first(R) != null) {
        while (P != null) {
            if (info(P).parent == id) {
                cout << i << ". " << endl;
                printInfo(child(P));
                cout << endl;
                i ++;
                if (next(P) == null) {
                    cout << "akhir" << endl;
                }
            }
            P = next(P);
        }
    }
}

/// Show all friend with specified gender
void printAllFriendGender (string id, string arg,listR R) {
    // gender in info will allways uppercase
    addr P = first(R);
    int i = 1;
    if (P != null) {
        while (P != null) {
            if (info(P).parent == id) {
                if (info(child(P)).gender == arg) {
                    cout << i << ". " << endl;
                    printInfo(child(P));
                    i++;
                }
            }
            P = next(P);
        }
    }
}

/// Show all friend with specific town
void printAllFriendTown (string id, string town,listR R) {
    // gender in info will allways uppercase
    addr P = first(R);
    int i = 1;
    if (P != null) {
        while (P != null) {
            if (info(P).parent == id) {
                if (info(child(P)).town == town) {
                    cout << i << ". " << endl;
                    printInfo(child(P));
                    i++;
                }
            }
            P = next(P);
        }
    }
}



/// Show all friend with specific country
void printAllFriendCountry (string id, string country,listR R) {
    // gender in info will allways uppercase
    addr P = first(R);
    int i = 1;
    if (P != null) {
        while (P != null) {
            if (info(P).parent == id) {
                if (info(child(P)).country == country) {
                    cout << i << ". " << endl;
                    printInfo(child(P));
                    i++;
                }
            }
            P = next(P);
        }
    }
}
