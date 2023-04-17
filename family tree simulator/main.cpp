#include "Header.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

int main()
{
    int numberOfGenerations = getUserInput();
    
    person *p = createFamily(numberOfGenerations);
    
    printFamily(p, 0);
    
    freeFamily(p);
    
    
    return 0;
}
