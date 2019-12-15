/*
 * Author: Reed Spratt
 *
 * Description: This program performs the divide-and-conquer quicksort algorithm on a passed array of integers recursively.
 *              Elements in the array are ordered in ascending order, but instructions are included for descending order.
 *
 * Date: December 15th 2019
*/

#include <stdio.h>



/* Name: findPivot
 * Description: This function chooses the pivot element in the passed subarray and returns it to be used for splitting
 *              into two smaller subarrays.
 * 
 * Parameter: numbers               The array of numbers to sort
 * Parameter: low                   The lowest index in the passed subarray
 * Parameter: high                  The highest index in the passed subarray
 * Return: j                        The index of the new pivot value in the subarray
*/ 
int findPivot(int numbers[], int low, int high);



/* Name: quickSortRecursive
 * Description: This function performs quicksort on a passed array by recursively dividing it into subarrays
 *              and sorting the subarrays in ascending order.
 * 
 * Parameter: numbers               The array of numbers to sort
 * Parameter: low                   The lowest index in the passed subarray
 * Parameter: high                  The highest index in the passed subarray
 * Return: void
*/ 
void quickSortRecursive(int numbers[], int low, int high);



//FUNCTION quickSortRecursive
void quickSortRecursive(int numbers[], int low, int high) {

    //While there are still more elements to sort, recurse
    if (low < high) {

        //Get the pivot value to partition the array
        int pivot = findPivot(numbers, low, high);

        //Recur over the first and second halves of the array
        quickSortRecursive(numbers, low, pivot - 1);
        quickSortRecursive(numbers, pivot+1, high);
    }
}



//FUNCTION findPivot
int findPivot(int numbers[], int low, int high) {

    //Set the pivot value as the first element of the subarray
    int pivot = numbers[low];

    //Set i to be the next index value after the pivot in the subarray
    int i = low + 1;

    //Set j to be the highest index value in the subarray
    int j = high;

    //Temporary variable for swapping values
    int swap;

    //Loop until i and j have passed each other
    while(1) {

        /* Move i forward until its value is less than or equal to the pivot value
           For descending order, set to >=
        */
        while (numbers[i] <= pivot) {
            i++;
        }

        /* Move j forward until its value is greater than the pivot value
           For descending order, set to <
        */
        while (numbers[j] > pivot) {
            j--;
        } 

        /* If i is less than j, swap the values at indices i and j.
           Check if i < j here to avoid swapping i and j when i >= j.
        */
        if (i < j) {
            swap = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = swap;
        }  

        //Else, break from the loop
        else {
            break;
        }     
    }     

    //Swap the array values at j and the pivot
    swap = numbers[j];
    numbers[j] = numbers[low];
    numbers[low] = swap;

    //Return j as the new pivot index
    return j;
}
