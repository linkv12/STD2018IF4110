#include "multi.h"

address allocate(){
    cout << "Name : ";
    string name;
    cin >> name;
    string ID = "";
    for (int i = 0; i <= 255; i++) {
        int ran = rand() % 2;
        if (ran == 1) {
            ID = ID + "1";
        } else {
            ID = ID + "0";
        }
    }
};
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
