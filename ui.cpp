//
// Created by linkv12 on 27/04/18.
//

#include "ui.h"
#include  <stdlib.h>
#include <iostream>
using namespace std;

#define windows1
#include "multi.h"
#include "search.h"
#include "relation.h"
#include "debug.h"
#include "testValid.h"
/* * *
 * *
 * */
/// welcome page
void welcome (list &L, list &K, listR &R) {
    /* List L is parent
     * list K is child
     * */
    //if (first(L) == null) {
    //    cout << "stop" << endl;
    //}
        //A line
        line("*");
        line("=");
        cout << "           WELCOME             " << endl << endl;

        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter : ";
        string x ;
        cin >> x;
        clrscr();
    if (x == "1") {
        loginpage(L,K,R);
    } else  if (x == "2"){
        address P ;
        P = allocate(singup(L));
        assignID(P,L);
        insertFirst(L,K,P);
        //printInfo(first(L));
        cout << "wat ";
        welcome(L,K,R);
    } else if (x == "88"){
        showAll(L);
        showAll(K);
        line ("bla");
        welcome(L,K,R);
    } else  if (x == "3"){
        exit(9945);
    } else {
        welcome (L,K,R);
    }
    //A line
    line("*");
    line("=");
}

/// Generate a line with 30 char length
void line (string x) {
    //A line
    for (int i = 0 ; i <= 29; i++) {
        cout << x ;
        if (i == 29) {
            cout << endl;
        }
    }
}

/// login page
void loginpage (list &L, list &K, listR &R) {
    /* List L is parent
    * list K is child
    * */
    line("*");
    line("=");
    cout << "           LOGIN             " << endl << endl;
    cout << "Username : ";
    log login ;
    cin >> login.uname;
    cout << "Password : ";
    cin >> login.pass;
    cout << endl << endl;
    address P = first(L);
    while (P != null && info(P).uname != login.uname) {
        P = next(P);
    }
    if (P != null) {
        login.id = info(P).id;
    }
    line("*");
    P = first(L);
    while (P != null ) {
        if (info(P).uname == login.uname) {
            if (info(P).pass == login.pass) {
                break;
            }
        }
        P = next(P);
    }
    if (P == null) {
        cout << "Invaid username or password " << endl;
        pause ();
        clrscr();
        welcome(L,K,R);
    } else {
        clrscr();
        uac(login,L,K,R);
    }
    clrscr();
}
/// signup page
infotype singup(list L) {
    line("*");
    line("=");
    cout << "           Sing Up" << endl;
    cout << "Only 1 word is allowed" << endl;
    infotype poll;
    cout << endl;
    do {
        cout << "Username : ";
        cin >> poll.uname;
    } while (!(isValidUn(poll.uname, L)));
    cout << "Nick name : ";
    cin >> poll.name;
    do {
        cout << "Gender : ";
        cin >> poll.gender;
    } while (!(isValidGender(poll.gender)));
    do {
        cout << "Age : ";
        cin >> poll.age;
    } while (!(isValidAge(poll.age)));
    cout << "Town :";
    cin >> poll.town;
    cout << "Country : ";
    cin >> poll.country;
    cout << "Birth Day [dd/mm/yyyy] : ";
    cin >> poll.bday;
    cout << "Password : ";
    cin >> poll.pass;
    string temp;
    do {
        cout << "Re-enter panssword : ";
        cin >> temp;
    } while (poll.pass != temp);

    line("=");
    line("*");
    clrscr();
    return poll;
}

/// A clrscr procedure
void clrscr() {
    //system ("CLS");
   // for (int i = 0 ; i <= 45; i++) {
   //     cout << endl;
   // }
   system("cls");
}

/// user account control
void uac (log login, list &L , list &K, listR &R) {
    /* List L is parent
     * list K is child
     * */
    clrscr();
    convert(L,K);
    line ("=");
    line ("=");
    cout << "           Account Control" << endl;
    cout << "Username : " << login.uname << endl;
    line("="); cout << endl;
    cout << "1. Add friend " << endl;
    cout << "2. Search for friend " << endl;
    cout << "3. Show friend " << endl;
    //cout << "4. Search friend " << endl;
    cout << "4. Remove friend " << endl;
    //cout << "6. Show all friend " << endl;
    //cout << "7. Show friend " << endl;
    cout << "5. Edit profile " << endl;
    cout << "6. Log out " << endl;
    cout << "ENter : ";
    int x;
    cin >> x;
    clrscr();
    switch (x) {
        case 1: addFriend (login, L,K ,R);
                uac (login,L,K,R);
        case 2: searchPage (login,L,K,R);
            uac (login,L,K,R);
        case 3:
            showMenu(login, L, K, R);
            uac (login,L,K,R);
        case 6: cout << "Commencing LogOut. .. . . . " << endl;
                system("pause");
                clrscr();
                welcome(L,K,R);
        case 99 :
            cout << login.pass << endl;
            uac (login,L,K,R);
        case 666 :
            printId(L);
            uac(login,L,K,R);
        case 401 :
            printAll (L);
            pause();
            uac(login,L,K,R);
//        case 6 :
  //          showAllFriendPage (login,R);
    //        uac(login,L,K,R);
        case 5 :
            editProfile1 (login,L,K,R);
            uac(login,L,K,R);
        case 4 :
            removeFriendPage (login,L,K,R);
            uac(login,L,K,R);
        case 10 :
            showMenu(login, L, K, R);
        default : uac (login,L,K,R);
    }

}

/// Add friend menu
void addFriend (log login, list &L,list &K, listR &R) {
    line ("+");
    bool temp;
    line("=");
    string uname;
    cout << "           Add a friend " << endl << endl;

    /*
    do {
        cout << "       Username : ";
        cin >> uname;
        temp = isFriend(login.id,uname,L,R);
    } while ((uname == login.uname || temp));
     2*/
        do {
            cout << "       Username : ";
            cin >> uname;
            if (searchUn(uname,L) == null) {
                cout << "No user with that user name" << endl;
                pause();
                break;
            }
        } while (uname == login.uname && next(first(L)) != null);




    address P = searchUn(uname,L);


    // All still good
    if (P == null) {

        cout << "404 not found ";
        uac(login,L,K,R);

    } else {

        if (uname != login.uname) {
        // All good
        printInfo(P);
        //cout << isFriend(login.id,uname,L,R) << endl;
        if (! isFriend(login.id,uname,L,R)) {
            cout << endl << "1 . add " << endl;
            cout << "2. no " << endl;
            cout << "3. Back" << endl;
            int x;
            cin >> x;
            clrscr();
            if (x == 1) {
                connect(login.id, info(P).id, L, K, R);
            } else if (x == 2) {
                addFriend(login, L, K, R);
            } else if (x == 3) {
                uac(login, L, K, R);
            } else {
                uac(login, L, K, R);
            }
        } else {
            cout << "Already a friend " << endl;
            int x;
            cout << "1 . Back";
            cin >> x;
            if (x == 1) {
                uac(login, L, K, R);
            } else {
                uac(login, L, K, R);
            }
        }
    } else if (uname == login.uname) {
            cout << "You cant be friend with urself" << endl;
            pause();
            clrscr();
            uac(login,L,K,R);
        }
    }
}

/// Search friend in parent list & child
void searchFriend (log login, list &L,list &K, listR &R) {
    //not implemented yet
    //Look for a new friend in list L [Parent]
}

/// Show all friend
void showAllFriendPage (log login,listR R) {
   showAllFriend(login.id,R);
}

/// Edit Profile
void editProfile (log &login, list &L , list &K, listR &R) {
    clrscr();
    line("=");
    line("=");
    cout << "           Edit Profile"  << endl;
    printInfo(searchParentId(login.id,L));
    cout << endl;
    line ("=");
    if (first(L) != null) {
        address P = searchParentId(login.id, L);
        if (P != null) {
            string nun = "-";
            infotype inf;
            cout << "Put (-) for empty " << endl;
           do {
            cout << "1. Username : ";
            cin >> inf.uname;
            } while (!(isValidUn(inf.uname, L)));
            cout << "2. Name : ";
            cin >> inf.name;
            cout << "3. Town :";
            cin >> inf.town;
            cout << "4. Country : ";
            cin >> inf.country;
            cout << "5. Birth Day [dd/mm/yyyy] : ";
            cin >> inf.bday;
            cout << "6. Password : ";
            cin >> inf.pass;

            if (inf.uname != nun) {
                info(P).uname = inf.uname;
                login.uname = inf.uname;
            }
            if (inf.name != nun) {
                info(P).name = inf.name;
            }
            if (inf.town != nun) {
                info(P).town = inf.town;
            }
            if (inf.country != nun) {
                info(P).country = inf.country;
            }
            if (inf.bday != nun) {
                info(P).bday = inf.bday;
            }
            if (inf.pass != nun) {
                info(P).pass = inf.pass;
                login.pass = inf.pass;
            }
            convert(L,K);
            updateRelation(L,K,R);
        }

    }
}

/// Remove friend
void removeFriendPage (log login, list L , list K, listR &R) {
    line("=");
    line ("=");
    showAllFriend(login.id,R);
    cout << "Remove a friend : ";
    string uname;
    cin >> uname ;
    address P = searchUn(uname,L);
    if (P != null && uname != login.uname) {
        cout << "Done 3"<< endl;
        disconnect(login.id, info(P).id, R);
        cout << "Done "<< endl;
        pause();
        showAllFriend(login.id,R);
        pause();
        uac(login, L, K, R);
    } else if (P == null && uname != login.uname ){
        cout << uname << " is not your friend" << endl;
        pause();
        uac(login, L, K, R);
    } else {
        cout << "you cant unfriend yourself" << endl;
        pause();
        uac(login, L, K, R);
    }
}

/// Just an added interface
void editProfile1 (log login, list &L , list &K, listR &R) {
    line("==");
    line("+");
    cout << "Edit Profile " << endl << endl;
    cout << "1. Edit Profile " << endl;
    cout << "2. Delete Account " << endl;
    cout << "3. Back" << endl << endl;
    int x;
    do {
        cout << "enter : ";
        cin >> x;
    } while (x == 1 && x == 2 && x == 3);
    switch (x) {
    case 1 :
        editProfile(login,L,K,R);
        uac(login, L, K, R);
    case 2 :
        disconnectVertex(login.id ,L,K,R);
        cout << "Commencing LogOut. .. . . . " << endl;
        system("pause");
        clrscr();
        welcome(L,K,R);
    case 3 :
        uac(login, L, K, R);
    }
}

/// Show Menu
void showMenu (log login, list &L , list &K, listR &R) {
/*
** just a menu to show something
**
**/
    clrscr();
    line("=");
    line("*");
    cout << "       Show menu" << endl;
    cout << "1. Show all friend" << endl;
    cout << "2. Show male friend" << endl;
    cout << "3. Show female friend" << endl;
    cout << "4. Show friend from [Town] " << endl;
    cout << "5. Show friend from [country]" << endl;
    cout << "6. Back" << endl;
    cout << "Enter : ";
    int x;
    cin >> x;
    switch (x) {
    case 1 :
        clrscr();
        cout << "cout " << endl;
        showAllFriend(login.id, R);
        line ("=");
        pause();
        showMenu(login,L,K,R);
        //cout << "Enter to exit" << endl;
    case 2 :
        clrscr();
        printAllFriendGender (login.id, "M", R);
        line ("=");
        pause();
        showMenu(login,L,K,R);
        //cout << "Enter to exit" << endl;
    case 3 :
        clrscr();
        printAllFriendGender (login.id, "F", R);
        line ("=");
        pause();
        showMenu(login,L,K,R);
        //cout << "Enter to exit" << endl;
    case 4 :{
        clrscr();
        line ("=");
        line ("=");
        cout << "       Town : ";
        string town;
        cin >> town;
        printAllFriendTown(login.id,town,R);
        line ("=");
        line ("=");
        showMenu(login,L,K,R);
    }
    case 5 :{
        clrscr();
        line ("=");
        line ("=");
        cout << "       Country : ";
        string arg;
        cin >> arg;
        printAllFriendTown(login.id,arg,R);
        line ("=");
        line ("=");
        showMenu(login,L,K,R);
    }
    case 6 :
        uac(login, L, K, R);
    default :
        clrscr();
        showMenu(login,L,K,R);
    }
}

/// A system pause
void pause () {
    system("pause");
}

/// Search friend menu
void searchPage (log login, list &L , list &K, listR &R) {
    clrscr();
    line ("-");
    line ("*");
    cout << "           Search " << endl;
    cout << "1. Search Username" << endl;
    cout << "2. Search Name" << endl;
    cout << "3. Search Town" << endl;
    cout << "4. Search Country" << endl;
    cout << "5. Search M/F" << endl;
    cout << "6. Back" << endl;
    int x;
    cout << "Enter : ";
    cin >> x;
    clrscr();
    switch (x) {
    case 1 : {
        cout << "Username : ";
        string uname;
        cin >> uname;
        address P = searchUn(uname,L);
        if (P == null && uname != login.uname) {
            cout << "Not found" << endl;
            pause();
        } else if (P != null && uname != login.uname) {
            printInfo(P);
            pause();
        } else {
            cout << "No cant do" << endl;
            pause();
        }
        searchPage (login,L,K,R);
    }
    case 2 : {
        cout << "Name : " ;
        string temp;
        cin >> temp;
        if (temp != login.uname) {
            address P = searchParentName (temp,L);
            if (P == null) {
                cout << "not found" << endl;
                pause();
            } else {
                printInfo(P);
                pause();
            }
        } else {
            cout << "Noooooo" << endl;
            pause();
        }
        searchPage (login,L,K,R);
    }
    case 3 :{
        cout << "       Town : ";
        string town;
        cin >> town;
        printAllTown(town,L);
        pause();
         searchPage (login,L,K,R);
    }
    case 4 : {
        cout << "       Country : ";
        string country;
        cin >> country;
        printAllCountry(country,L);
        pause();
         searchPage (login,L,K,R);
    }
    case 5 : {
        cout << "Search for [M/F] : ";
        string temp ;
        cin >> temp;
        if (temp == "M" || temp == "m") {
            clrscr();
            temp = "M";
            printAllGender(L,temp);
            pause();
        } else if (temp == "F" || temp == "f") {
            clrscr();
            temp = "F";
            printAllGender(L,temp);
            pause();
        } else {

        }
        searchPage (login,L,K,R);
    }
    case 6 :
        uac (login,L,K,R);
    default :
        searchPage (login,L,K,R);
    }
}
