/*
 * Author: Reed Spratt
 *
 * Description: This program includes two functions for performing the brute-force selection sorting method on a passed array.
 *              One function performs sorts integers, and the other alphabetically sorts an array of pointers to strings.
 *
 * Date: December 12th 2019
*/



#include <stdio.h>
#include <string.h>



/* Name: selectionSortIntegers
 * Description: This function performs the brute-force selection sorting method on a passed array of integers.
 *              The size of the array must be passed to the function.
 * 
 * Parameter: numbers               The array of integers to sort
 * Parameter: numElements           The number of elements in the passed array
 * Return: void
*/ 
void selectionSortIntegers(int numbers[], int numElements);



/* Name: selectionSortStrings
 * Description: This function performs the brute-force selection sorting method on a passed array of strings (alphabetical).
 *              The size of the array must be passed to the function.
 * 
 * Parameter: strings               The array of strings to sort (Of type char* strings[num])
 * Parameter: numElements           The number of elements in the passed array
 * Return: void
*/ 
void selectionSortStrings(char** strings, int numElements);



//FUNCTION selectionSortIntegers
void selectionSortIntegers(int numbers[], int numElements) {

    //Loop counters
    int i = 0;
    int j = 0;

    //Variable to hold the current minimum value in the array
    int min;

    //Temporary container for swapping array elements
    int temp;

    //Make sure the passed array has elements
    if (numElements <= 0) {
        printf("The passed array must have one or more elements.\n");
        return;
    }

    //Iterate through the array
    for (i = 0; i < numElements - 1; i++) {

        //Set the minimum value to i by default
        min = i;

        //Iterate through the remaining elements
        for (j = i + 1; j < numElements; j++) {

            //If the element at j is less than the element at min, set the new min index
            if (numbers[j] < numbers[min]) {
                min = j;
            }
        }

        //Swap numbers[i] and numbers[min]
        temp = numbers[i];
        numbers[i] = numbers[min];
        numbers[min] = temp;
    }
}



//FUNCTION selectionSortStrings
void selectionSortStrings(char** strings, int numElements) {

    //Loop counters
    int i = 0;
    int j = 0;

    //Variable to hold the current minimum value in the array
    int min;

    //Temporary container for swapping array elements
    char* temp;

    //Make sure the passed array has elements
    if (numElements <= 0) {
        printf("The passed array must have one or more elements.\n");
        return;
    }

    //Iterate through the array
    for (i = 0; i < numElements - 1; i++) {

        //Set the minimum value to i by default
        min = i;

        //Iterate through the remaining elements
        for (j = i + 1; j < numElements; j++) {

            //If the element at j is less than the element at min, set the new min index
            if (strcmp(strings[j], strings[min]) < 0) {
                min = j;
            }
        }

        //Swap strings[i] and stringsmin]
        temp = strings[i];
        strings[i] = strings[min];
        strings[min] = temp;
    }
}
