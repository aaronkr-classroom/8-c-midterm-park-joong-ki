#include <stdio.h>
#include "grade_funcs.h"

#define NUM_STUDENTS 10


double calculate_average(int s[], int a) {
    int sum = 0;
    for (int i = 0; i < a; i++) {
        sum += s[i];
    }
    return (double)sum / a;
}


void find_min_max(int s[], int a, int* minScore, int* maxScore) {
    *minScore = s[0];
    *maxScore = s[0];

    for (int i = 1; i < a; i++) {
        if (s[i] < *minScore) {
            *minScore = s[i];
        }
        if (s[i] > *maxScore) {
            *maxScore = s[i];
        }
    }
}


void count_pass_fail(int s[], int a, int* passCount, int* failCount) {
    *passCount = 0;
    *failCount = 0;

    for (int i = 0; i < a; i++) {
        if (s[i] >= 60) {
            (*passCount)++;
        }
        else {
            (*failCount)++;
        }
    }
}



int main() {
    
    int s[NUM_STUDENTS] = { 85, 70, 55, 90, 45, 60, 78, 88, 92, 49 };
    

   
    double average ;
    
    average = calculate_average(s, NUM_STUDENTS);
    printf("Average grade: %.1f\n", average);

    int minScore , maxScore ;
    
    find_min_max(s, NUM_STUDENTS, &minScore, &maxScore);
    printf("Highest grade: %d\n", maxScore);
    printf("Lowest grade: %d\n", minScore);
    printf("\n");

    printf("Grades above average: ");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (s[i] > average) {
            printf("%d ", s[i]);
        }
    }
    printf("\n");

    printf("Grades below average: ");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (s[i] < average) {
            printf("%d ", s[i]);
        }
    }
    printf("\n");
    printf("\n");

    int passCount, failCount ;
    count_pass_fail(s, NUM_STUDENTS, &passCount, &failCount);
    printf("Number of students passing: %d\n", passCount);
    printf("Number of students failing: %d\n", failCount);

   

    return 0;
}