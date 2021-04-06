#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#define STUDENTS_WITH_LOWEST_RATING  5
//
//structure, that stores data
//
typedef struct student {

    char cSurname[13];
    char cName[10];
    char cBirthday[11];
    int nMarks[5];
    struct student* pNext;

} student;
//
//reading elements from txt file into a singly linked list
void dataRead(char* fileName, student** list, student** ratingList);
//
//printing list of students as a spreadsheet
//
void printList(student* ptr);
//
// adding a new element in the beginning of the list
//
void newElementBySurname(student* ptr, student** pHeadList);
//
//removes students, who have at least one "2" mark
//
void removeStudent(student** pHeadList);
//
//printing 5 students with lowest average mark
//
void printLowestRating(student* pHeadList);
//
//comparing student's surnames in ascending alphabetical order
//
int compareBySurname(student* one, student* two);
//
//finds which student is higher in rating
//
int compareByRating(student* one, student* two);
//
//adding a new element in the beginning of the list
//
void newElementByRating(student* ptr, student** pHeadList);

double rating(student* ptr);