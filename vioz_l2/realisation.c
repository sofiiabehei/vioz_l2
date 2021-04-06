#include "func.h"

void dataRead(char* fileName, student** list, student** ratingList) {
    FILE* f = fopen_s(fileName, "r");
    do {
        student* ptrFirst = (student*)malloc(sizeof(student));
        student* ptrSecond = (student*)malloc(sizeof(student));
        fscanf_s(f, "%s %s %s", ptrFirst->cSurname, ptrFirst->cName, ptrFirst->cBirthday);
        for (int i = 0; i < STUDENTS_WITH_LOWEST_RATING; ++i)
            fscanf_s(f, "%i", &(ptrFirst->nMarks[i]));

        strcpy_s(ptrSecond->cSurname, ptrFirst->cSurname);
        strcpy_s(ptrSecond->cName, ptrFirst->cName);
        strcpy_s(ptrSecond->cBirthday, ptrFirst->cBirthday);
        for (int i = 0; i < STUDENTS_WITH_LOWEST_RATING; ++i)
            ptrSecond->nMarks[i] = ptrFirst->nMarks[i];

        newNodeBySurname(ptrFirst, list);
        newNodeByRating(ptrSecond, ratingList);
    } while (fgetc(f) != EOF);
    fclose(f);
}
//-------------------------------------------------------------------
void printList(student* ptr) {
    printf("+---+-------------+----------+----------+--------------+\n");
    printf("| # |   Surname   |   Name   |   Date   |Marks:        |\n");
    printf("+---+-------------+----------+----------+--------------+\n");
    int i = 0;
    while (ptr != NULL) {
        printf("|#%2i|%13s|%10s|%10s|", ++i, ptr->cSurname, ptr->cName, ptr->cBirthday);
        for (int j = 0; j < STUDENTS_WITH_LOWEST_RATING; ++j)
            printf("%2i|", ptr->nMarks[j]);
        printf("\n+---+-------------+----------+----------+--------------+\n");
        ptr = ptr->pNext;
    }
}
//-------------------------------------------------------------------
void newElementBySurname(student* ptr, student** pHeadList) {
    if ((*pHeadList) == NULL) {
        (*pHeadList) = ptr;

        (*pHeadList)->pNext = NULL;
        return;
    }
    if (compareBySurname(*pHeadList, ptr) < 0)
    {
        ptr->pNext = *pHeadList;
        *pHeadList = ptr;
        return;
    }
    student* pCurrent = *pHeadList;
    while ((pCurrent->pNext) != NULL) {
        if (compareBySurname(pCurrent, ptr) > 0 && compareBySurname(pCurrent->pNext, ptr) <= 0)
        {
            ptr->pNext = pCurrent->pNext;
            pCurrent->pNext = ptr;
            return;
        }
        else pCurrent = pCurrent->pNext;
    }
    pCurrent->pNext = ptr;
    ptr->pNext = NULL;
}
//-------------------------------------------------------------------
void newElementByRating(student* ptr, student** pHeadList) {
    if ((*pHeadList) == NULL) {
        (*pHeadList) = ptr;

        (*pHeadList)->pNext = NULL;
        return;
    }
    if (compareByRating(*pHeadList, ptr) < 0)
    {
        ptr->pNext = *pHeadList;
        *pHeadList = ptr;
        return;
    }
    student* pCurrent = *pHeadList;
    while ((pCurrent->pNext) != NULL) {
        if (compareByRating(pCurrent, ptr) > 0 && compareByRating(pCurrent->pNext, ptr) <= 0)
        {
            ptr->pNext = pCurrent->pNext;
            pCurrent->pNext = ptr;
            return;
        }
        else pCurrent = pCurrent->pNext;
    }
    pCurrent->pNext = ptr;
    ptr->pNext = NULL;
}
//---------------------------------------------------------------------------
void removeStudent(student** pHeadList) {
    student* prev = NULL, * pCurrent = *pHeadList;
    while (pCurrent != NULL) {
        if ((!prev) &&
            (pCurrent->nMarks[0] == 2 || pCurrent->nMarks[1] == 2 || pCurrent->nMarks[2] == 2 || pCurrent->nMarks[3] == 2 ||
                pCurrent->nMarks[4] == 2))
        {
            *pHeadList = *pHeadList = pCurrent->pNext;
            free(pCurrent);
            pCurrent = *pHeadList;
            continue;
        }
        if (pCurrent->nMarks[0] == 2 || pCurrent->nMarks[1] == 2 || pCurrent->nMarks[2] == 2 || pCurrent->nMarks[3] == 2 ||
            pCurrent->nMarks[4] == 2)
        {
            prev->pNext = pCurrent->pNext;
            free(pCurrent);
            pCurrent = prev->pNext;
            continue;
        }

        prev = pCurrent;
        pCurrent = prev->pNext;
    }
}
//-----------------------------------------------------------------------------------
double rating(student* ptr) {
    double sum = 0;
    for (int i = 0; i < STUDENTS_WITH_LOWEST_RATING; i++) sum += ptr->nMarks[i];
    return sum;
}
//----------------------------------------------------------------------------------
void printLowestRating(student* pHeadList) {
    student* ptr = pHeadList;

    printf("+---+-------------+----------+----------+--------------+\n");
    printf("|List of students with lowest rating                   |\n");
    printf("+---+-------------+----------+----------+--------------+\n");
    printf("| # |   Surname   |   Name   |   Date   |Marks:        |\n");
    printf("+---+-------------+----------+----------+--------------+\n");
    for (int i = 0; i < STUDENTS_WITH_LOWEST_RATING && ptr->pNext; i++) {
        printf("|#%2i|%13s|%10s|%10s|", i + 1, ptr->cSurname, ptr->cName, ptr->cBirthday);
        for (int j = 0; j < STUDENTS_WITH_LOWEST_RATING; ++j)
            printf("%2i|", ptr->nMarks[j]);
        printf("\n+---+-------------+----------+----------+--------------+\n");
        ptr = ptr->pNext;
    }

    printf("\n\n");
}
