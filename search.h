//  Search function and all
// Created by linkv12 on 26/04/18.
//

#ifndef TUBES_SEARCH_H
#define TUBES_SEARCH_H

#include <iostream>
using namespace std;

#include "multi.h"
#include "relation.h"

/// Search id
address searchId (string id, list &L);
/// search username
address searchUn (string uname, list  &L);
/// Search parent
address searchParentId (string id, list &L);
/// Search exact parent and child //{parent,child} combo
addr searchPC (string parent,string child, listR &L);
/// Search child
address searchChildId (string id, list &L);
/// Search a name
address searchParentName (string name, list L);

#endif //TUBES_SEARCH_H
