#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#define STUDENTS_WITH_LOWEST_RATING  5
typedef struct Sstudent {

    char cSurname[13];
    char cName[10];
    char cBirthday[11];
    int nMarks[5];
    struct student* pNext;

} student;


int main(void) {

    student* listBySurname = NULL;
    student* listByRating = NULL;

    dataRead("input.txt", &listBySurname, &listByRating);

    printf("List before:\n");
    printList(listBySurname);
    printf("\n");

    deleteNode(&listBySurname);

    printf("List after:\n");
    printList(listBySurname);
    printf("\n");


    printf("5 students with lowest rating:\n");
    printLowestRating(listByRating);
    printf("\n");

}