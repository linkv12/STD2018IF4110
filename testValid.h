// A test validity header
// Created by linkv12 on 26/04/18.
//

#ifndef TUBES_TESTVALID_H
#define TUBES_TESTVALID_H

#include <iostream>
using namespace std;

#include "multi.h"
/// Test a validity test on bday
//bool isValidBd (string x);
/// Test id validity
bool isValidid (string x, list L);
/// Test uname validity
bool isValidUn (string x, list L);
/// Is Valid gender
bool isValidGender (string &gender);
/// is Valid age
bool isValidAge (int &age);

#endif //TUBES_TESTVALID_H
