#include <iostream>
#include "multi.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    while (1) {
      int ran = rand() % 1;
      cout << ran;
    };
    return 0;
}
