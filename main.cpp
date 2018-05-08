#include <iostream>
using namespace std;
#include "ui.h"
#include "relation.h"

int main() {
    list L,K;
        createlist(L);
        createlist(K);
    listR R;
        createlist(R);
    welcome(L,K,R);
    return 0;
}