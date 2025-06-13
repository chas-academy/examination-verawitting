//Write your code in this file
#include <stdio.h>

/*
This program handles five students and their test results from 13 tests.
It reads the result with scanf(), analyses the average of points for each student,
the student with the best score and the student whoose score are below the average of the group.
(I created an object to keep track of the students and their results, I hope that is ok even though it was not part of the course.)
*/

// defining constants for number of tests and students to aviod "magic numbers" 
#define NUM_TESTS 13
#define NUM_STUDENTS 5

// creating an object to save info each student
typedef struct {
    char name[11];
    int result[NUM_TESTS];
    float average;
} Student;

int main() {

    // creating an array of student objects
    Student students[NUM_STUDENTS];

    // printf("Please enter student name and 13 test results: \n");

    // looping a scan for student names and results
    for (int i = 0; i < NUM_STUDENTS; i++) {
        // changing the first letter to uppercase if it was lower case
        // and populating name to student object
        scanf("%s", students[i].name);
        if (students[i].name[0] >= 'a' && students[i].name[0] <= 'z') {
            students[i].name[0] = students[i].name[0] - ('a' - 'A');
        }
        // populating results to student object
        for (int j = 0; j < NUM_TESTS; j++) {
            scanf("%d", &students[i].result[j]);
        }
    }

    // looping through students, declaring sum variable
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int sum = 0;
        // looping through test results of each student, adding all test results
        for (int j = 0; j < NUM_TESTS; j++) {
            sum += students[i].result[j];
        }
        // calculating the average value of each stundents test results, and populating the objects.
        students[i].average = sum / (float)NUM_TESTS;
    }


    // declaring a max index to compare students test results
    int maxIndex = 0;
    // looping through students, comparing their average score
    for (int i = 1; i < NUM_STUDENTS; i++) {
        if (students[i].average > students[maxIndex].average) {
            // changeing maxIndex to compare to the next student
            maxIndex = i;
        }
    }

    // declaring variable for the average score of the students
    float totalAverage = 0;
    // adding all students averages to totalAverage
    for (int i = 0; i < NUM_STUDENTS; i++) {
        totalAverage += students[i].average;
    }
    // calculating the total average
    totalAverage /= NUM_STUDENTS;

    // and printing the name of the highest ranking student
    printf("%s\n", students[maxIndex].name);

    // looping through students to compare their average to the totalAverage
    // printing their name if if it were below average
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (students[i].average < totalAverage) {
            printf("%s\n", students[i].name);
        }
    }

    return 0;

}