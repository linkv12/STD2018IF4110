// UI
// Created by linkv12 on 27/04/18.
//

#ifndef TUBES_UI_H
#define TUBES_UI_H

#define windows1
#include <iostream>
using namespace std;

#include "search.h"
#include "multi.h"
#include "relation.h"
/// A login
struct log {
    string uname;
    string pass;
    string id;
};


/// welcome page
void welcome (list &L, list &K, listR &R) ;
/// login page
void loginpage (list &L, list &K, listR &R);
/// signup page
infotype singup(list L);
/// Generate a line with 30 char length
void line(string x);
/// A clrscr procedure
void clrscr() ;
/// A system pause
void pause ();
/// user account control
void uac (log login, list &L , list &K, listR &R);
/// Add friend menu
void addFriend (log login, list &L,list &K, listR &R);
/// Search friend in parent list & child
void searchFriend (log login, list &L,list &K, listR &R);
/// Show all friend
void showAllFriendPage (log login,listR R);
/// Edit Profile
void editProfile (log &login, list &L , list &K, listR &R);
/// Remove friend
void removeFriendPage (log login, list L , list K, listR &R);
/// Just an added interface
void editProfile1 (log login, list &L , list &K, listR &R);
/// Show Menu
void showMenu (log login, list &L , list &K, listR &R);
/// Search friend menu
void searchPage (log login, list &L , list &K, listR &R);

#endif //TUBES_UI_H
