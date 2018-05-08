//
// Created by link on 26/04/18.
//

#include "testValid.h"
#include <string>
#include <stdlib.h>
//#include <ctype.h>

/// Test a validity test on bday
bool isValidBd (string x) {
}
/// Test id validity
bool isValidid (string x, list L) {
    /* Using parent list
     * */
    address  P = first(L);
    bool valid = true;
    while (P != null && valid) {
        valid &= (x != info(P).id);
        P = next(P);
    }
    return valid;
}
/// Test uname validity
bool isValidUn (string x, list L) {
    /* Using parent list
    * */
    if (first(L) != null) {
        address P = first(L);
        bool valid = true;
        while (P != null && valid) {
            valid &= (x != info(P).uname);
            P = next(P);
        }
        return valid;
    } else {
        return true;
    }
}

/// Is Valid gender
bool isValidGender (string &gender) {
    if (gender.length() != 1) {
        return false;
    } else {
        if (gender == "m" || gender == "M" || gender == "f" || gender == "F") {
            if (gender == "m" || gender == "M") {
                gender = "M";
                return true;
            } else if (gender == "f" || gender == "F") {
                gender = "F";
                return true;
            }
        } else {
            return false;
        }
    }
}

/// is Valid age
bool isValidAge (int &age) {
    if (age < 0) {
        return false;
    } else {
        return true;
    }

}
