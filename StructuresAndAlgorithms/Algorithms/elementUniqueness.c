/*
 * Author: Reed Spratt
 *
 * Description: This program includes two functions for verifying if all of the passed elements in an array are unique using a brute force algorithm.
 *              The first function checks for uniqueness in a set of integers, and the second checks for uniqueness in a set of pointers to strings.
 *
 * Date: December 14th 2019
*/



#include <stdio.h>
#include <stdbool.h>
#include <string.h>



/* Name: checkUniquenessIntegers
 * Description: This function searches through the passed array of integers and verifies that 
 *              all of the elements within are unique. The array length must be passed to the function.
 * 
 * Parameter: numbers           The array of numbers to search through
 * Parameter: numElements       The number of elements in the passed array
 * Return: true or false
*/  
bool checkUniquenessIntegers(int numbers[], int numElements);



/* Name: checkUniquenessStrings
 * Description: This function searches through the passed array of strings and verifies that 
 *              all of the elements within are unique. The array length must be passed to the function.
 * 
 * Parameter: strings           The array of strings to search through (Of format char* strings[num])
 * Parameter: numElements       The number of elements in the passed array
 * Return: true or false
*/  
bool checkUniquenessStrings(char** strings, int numElements);



//FUNCTION checkUniqunessIntegers
bool checkUniquenessIntegers(int numbers[], int numElements) {

    //Loop counters
    int i = 0;
    int j = 0;

    //Make sure the passed array has elements
    if (numElements == 0) {
        printf("The passed array can't be empty.\n");
        return false;
    }

    //Iterate through the elements, making every pairwise comparison
    for (i = 0; i < numElements - 1; i++) {
        for (j = i + 1; j < numElements; j++) {

            //If two elements match, we have a duplicate
            if (numbers[i] == numbers[j]) {
                return false;
            }
        }
    }

    //If no duplicates were found, return true
    return true;
}



//FUNCTION checkUniquenessStrings
bool checkUniquenessStrings(char** strings, int numElements) {

    //Loop counters
    int i = 0;
    int j = 0;

    //Make sure the passed array has elements
    if (numElements == 0) {
        printf("The passed array can't be empty.\n");
        return false;
    }

    //Iterate through the elements, making every pairwise comparison
    for (i = 0; i < numElements - 1; i++) {
        for (j = i + 1; j < numElements; j++) {

            //If two elements match, we have a duplicate
            if (strcmp(strings[i], strings[j]) == 0) {
                return false;
            }
        }
    }

    //If no duplicates were found, return true
    return true;
}
