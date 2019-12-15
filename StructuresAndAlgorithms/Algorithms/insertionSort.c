/*
 * Author: Reed Spratt
 *
 * Description: This program includes a function for performing the decrease and conquer sorting method Insertion Sort.
 *
 * Date: December 15th 2019
*/



#include <stdio.h>



/* Name: insertionSort
 * Description: This function performs the decrease and conquer sorting method Insertion Sort on an array of integers.
 *              The size of the array must be passed to the function.
 * 
 * Parameter: numbers                   The array of integers to sort
 * Parameter: numElements               The number of elements in the passed array
 * Return: void
*/ 
void insertionSort(int numbers[], int numElements);



//FUNCTION insertionSort
void insertionSort(int numbers[], int numElements) {

    //Loop counters
    int i;
    int j;

    //Variable to hold the current unsorted element to be inserted into the sorted array
    int current;

    //Make sure the passed array has elements
    if (numElements <= 0) {
        printf("The passed array must have one or more elements.\n");
        return;
    }

    //Iterate through the entire array
    for (i = 1; i < numElements; i++) {
        
        //Get the current element to insert into the sorted array portion
        current = numbers[i];
        
        //Set j as the element before i
        j = i - 1;

        //Until reaching the beginning of the array or finding an element greater than current,
        //Swap elements in the sorted array portion to get the smaller elements to the beginning of the array
        while (j >= 0 && numbers[j] > current) {
            numbers[j+1] = numbers[j];
            j--;
        }

        //Insert the element currently selected into the sorted subarray
        numbers[j+1] = current;
    }
}
