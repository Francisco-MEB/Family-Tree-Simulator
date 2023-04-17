#ifndef HEADER_H
#define HEADER_H

struct person
{
    struct person *parents[2];
    char alleles[2];
};

namespace programConstants
{
constexpr inline int indentLength = 4;
}

int getUserInput();
person *createFamily(int generations);
void printFamily(person *p, int generation);
void freeFamily(person *p);
char randomAlleleGenerator();
int selectEitherAllele();

#endif
