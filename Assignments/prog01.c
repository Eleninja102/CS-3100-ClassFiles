
/*
Author: Meher Shaikh + Coleton Watt
Date: Jan 16, 2022
It took me maybe an hour
*/

/*
You are expected to do some research on 
1. fgets(), scanf, sscanf, and printf formating
2. addressof operator (gives the address of a variable) 
3. how arrays are passed to functions in a C program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STUDS 1
#define DATA_LEN 80

typedef struct student
{
    char name[DATA_LEN];
    int id;
    double GPA;
} student;

void enterstudinfo(student *slist)
{
    // use a for loop to populate the data in the incoming array
    // --read the value for name (you may use fgets())
    // --read the value for id (you may use combination of fgets() and sscanf)
    // --read the value for GPA (you may use combination of fgets() and sscanf)
    // end of for loop

    // NOTE: you may declare your requisite variables
    // Do not add undesired/unwanted code

    for(int studentNumber = 1; studentNumber <= NUM_STUDS; studentNumber++){
        printf("Student %i\n", studentNumber);
        
        printf("Student %i's Name: ", studentNumber);
        fgets(slist[studentNumber-1].name, DATA_LEN, stdin);
        slist[studentNumber-1].name[strcspn(slist[studentNumber-1].name, "\n")] = '\0'; //Get rid of leading '\n' 
        
        char idAsChar[5];
        printf("Student %i's ID: ", studentNumber);
        fgets(idAsChar, 5, stdin);
        sscanf(idAsChar, "%i", &slist[studentNumber-1].id);
    
    
        char gpaAsChar[10];
        printf("Student %i's GPA: ", studentNumber);
        fgets(gpaAsChar, 10, stdin);
        sscanf(gpaAsChar, "%lf", &slist[studentNumber-1].GPA);
        
        printf("\n");
    }
    
    return;
}

void displstudinfo(student *slist)
{
    printf("\n*************Students Report:--------- ");
    printf("\n--------------------------------------");
    printf("\n%-25s| %-5s | %s |", "NAME",
           "ID",
           "GPA ");
    
    for(int student = 0; student < NUM_STUDS; student++){
        printf("\n%-25s| %-5i | %.2lf |", slist[student].name,
            slist[student].id,
            slist[student].GPA);
    }
}

int main()
{

    // Array of students:
    student studArr[NUM_STUDS];

    enterstudinfo(studArr);
    displstudinfo(studArr);

    printf("\n");

    return 0;
}
