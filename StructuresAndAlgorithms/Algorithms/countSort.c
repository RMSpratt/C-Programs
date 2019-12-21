#include <stdio.h>
#include <stdlib.h>



/* Name: comparisonCountSort
 * Description: This function sorts an array of integers in ascending order and inserts the sorted elements
 *              into a new array to be returned.
 * 
 * Parameter: arr                   The array of integers to sort
 * Parameter: numElements           The number of elements in the passed array
 * No return value
*/ 
int* comparisonCountSort(int arr[], int numElements) {

    //Variable to hold the sorted array of elements
    int* sorted = malloc(sizeof(int) * numElements);

    //Variable to hold each element's count value as its index in the sorted array
    int count[numElements];

    //Loop counters
    int i, j;

    //Initialize the array of each element's count to 0
    for (i = 0; i < numElements; i++) {
        count[i] = 0;
    }

    //For all of the elements i in the array
    for (i = 0; i < numElements - 1; i++) {

        //Compare i to every subsequent element j
        for (j = i + 1; j < numElements; j++) {

            //If the element i is less than j, increment j's count
            if (arr[i] < arr[j]) {
                count[j]++;
            }

            //Else, increment i's count
            else {
                count[i]++;
            }
        }
    }

    //Form the new sorted array, by inserting elements based on their count
    for (i = 0; i < numElements; i++) {
        sorted[count[i]] = arr[i];
    }

    //Return the sorted array
    return sorted;
}



/* Name: distributedCountSort
 * Description: This function sorts an array of integers in ascending order for a specified range of sequential values.
 * 
 * Parameter: arr                   The array of integers to sort
 * Parameter: numElements           The number of elements in the passed array
 * Parameter: lower                 The lower bound of integer values in the array
 * Parameter: upper                 The upper bound of integer values in the array
 * No return value
*/ 
int* distributedCountSort(int arr[], int numElements, int lower, int upper) {

    //Variable to hold the sorted array of elements
    int* sorted = malloc(sizeof(int) * numElements);

    //Compute the range of values in the passed array
    int range = upper - lower;

    //Variable to hold each element value's frequency in the passed array
    int freq[range];

    //Loop counters
    int i, j;

    //Initialize each element value's frequency to 0
    for (i = 0; i <= range; i++) {
        freq[i] = 0;
    }

    //Compute the frequency of each element's value
    for (j = 0; j < numElements; j++) {
        freq[arr[j] - lower] = freq[arr[j] - lower] + 1;
    }

    //Compute the last position of each element's value
    for (i = 1; i <= range; i++) {
        freq[i] = freq[i - 1] + freq[i];
    }

    //Insert the elements into the sorted array based on their frequency and value
    for (j = numElements; j >= 0; j--) {
        i = arr[j] - lower;
        sorted[freq[i] - 1] = arr[j];

        //Decrement the frequency of the element left to insert into the array
        freq[i] = freq[i] - 1;
    }

    //Return the sorted array
    return sorted;
}
