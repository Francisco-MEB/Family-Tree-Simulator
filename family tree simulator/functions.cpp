#include "Header.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

int getUserInput()
{
    int n{};
    do
    {
        if (std::cin.fail())
        {
            std::cout << "ERROR: Invalid Input\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Number of generations: ";
        std::cin >> n;
    } while (std::cin.fail());
    
    return n;
}

person *createFamily(int generations)
{
    person *ptr{new person};
    if (ptr == NULL)
    {
        return NULL;
    }
    
    if (generations > 1)
    {
        person *parent0{createFamily(generations - 1)};
        person *parent1{createFamily(generations - 1)};
        
        ptr->parents[0] = parent0;
        ptr->parents[1] = parent1;
        
        ptr->alleles[0] = parent0->alleles[selectEitherAllele()];
        ptr->alleles[1] = parent1->alleles[selectEitherAllele()];
    }
    else
    {
        ptr->parents[0] = NULL;
        ptr->parents[1] = NULL;
        
        ptr->alleles[0] = randomAlleleGenerator();
        ptr->alleles[1] = randomAlleleGenerator();
    }
    
    return ptr;
}

void freeFamily(person *p)
{
    if (p == NULL)
    {
        return;
    }
    
    freeFamily(p->parents[0]);
    freeFamily(p->parents[1]);
    
    delete p;
}

void printFamily(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }
    
    for (int i = 0; i < generation * programConstants::indentLength; i++)
    {
        std::cout << " ";
    }
    
    switch(generation)
    {
        case 0:
            std::cout << "Child (Generation " << generation << "): blood type " << p->alleles[0] << p->alleles[1] << '\n';
            break;
        case 1:
            std::cout << "Parent (Generation " << generation << "): blood type " << p->alleles[0] << p->alleles[1] << '\n';
            break;
        default:
        {
            for (int i = 0; i < generation - 2; i++)
            {
                std::cout << "Great-";
            }
            std::cout << "Grandparent (Generation " << generation << "): blood type " << p->alleles[0] << p->alleles[1] << '\n';
            break;
        }
    }
    
    printFamily(p->parents[0], generation + 1);
    printFamily(p->parents[1], generation + 1);
}

char randomAlleleGenerator()
{
    int allele = rand() % 3;
    switch (allele)
    {
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'O';
        default:
            return NULL;
    }
}

int selectEitherAllele()
{
    int number = rand() % 2;
    
    return number;
}
