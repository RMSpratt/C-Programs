/*
 * Author: Reed Spratt
 *
 * Description: This program includes two functions for performing binary search non-recursively on a passed array.
 *              The first function searches through an array of integers for the desired value.
 *              The second function searches through an array of pointers to strings for the desired string.
 *
 * Date: December 14th 2019
*/



#include <stdbool.h>
#include <stdio.h>
#include <string.h>



/* Name: binarySearchIntegers
 * Description: This function performs binary search on an array of integers non-recursively.
 *              If the desired element is found, true is returned, else false.
 *              The array length must be passed to the function.
 *  
 * Parameter: numbers                The array of integers to search through
 * Parameter: length                The length of the passed array
 * Parameter: searchVal             The integer being searched for in the array
 * Return: true or false
*/ 
bool binarySearchIntegers(int numbers[], int length, int searchVal);



/* Name: binarySearchStrings
 * Description: This function performs binary search on an array of strings non-recursively.
 *              If the desired element is found, true is returned, else false. 
 *              The array length must be passed to the function.
 *  
 * Parameter: array                 The array of strings to search through (Of format char* strings[num])
 * Parameter: length                The length of the passed array
 * Parameter: searchString          The string being searched for in the array
 * Return: true or false
*/ 
bool binarySearchStrings(char** strings, int length, char* searchString);



//Function binarySearchIntegers
bool binarySearchIntegers(int numbers[], int length, int searchVal) {

    //Variables to hold the left and right indices when searching 
    int leftIndex;
    int rightIndex;

    //Make sure the passed array has elements
    if (length <= 0) {
        printf("The passed array must have one or more elements.");
        return false;
    }

    //Set the left and right starting indices to the bounds of the array
    leftIndex = 0;
    rightIndex = length - 1;

    //While the left index is less than the right index, keep searching
    while (leftIndex <= rightIndex) {

        //Grab the middle index of the array
        int middleIndex = (leftIndex + rightIndex) / 2;

        //If the search number is less than the middle index, search the first half of the array
        if (searchVal < numbers[middleIndex]) {
            rightIndex = middleIndex - 1;
        }

        //If the search number is greater than the middle index, search the second half of the array
        else if (searchVal > numbers[middleIndex]) {
            leftIndex = middleIndex + 1;
        }

        //If the search number matches the middle index, return
        else {
            return true;
        }
    }

    return false;
}



//Function binarySearchStrings
bool binarySearchStrings(char** strings, int length, char* searchString) {

    //Variables to hold the left and right indices when searching 
    int leftIndex;
    int rightIndex;

    //Make sure the passed array has elements
    if (length <= 0) {
        printf("The passed array must have one or more elements.");
        return false;
    }

    //Set the left and right starting indices to the bounds of the array
    leftIndex = 0;
    rightIndex = length - 1;

    //While the left index is less than the right index, keep searching
    while (leftIndex <= rightIndex) {

        //Grab the middle index of the array
        int middleIndex = (leftIndex + rightIndex) / 2;

        //If the search string is less than the middle index, search the first half of the array
        if (strcmp(searchString, strings[middleIndex]) < 0) {
            rightIndex = middleIndex - 1;
        }

        //If the search string is greater than the middle index, search the second half of the array
        else if (strcmp(searchString, strings[middleIndex]) > 0) {
            leftIndex = middleIndex + 1;
        }

        //If the search string matches the middle index, return
        else {
            return true;
        }
    }

    return false;
}
