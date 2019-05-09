#include <stdio.h>



//HEADERS



/* Name: merge
 * Description: This function merges two subarrays into one array
 * 
 * Parameters: The array to merge to, the two subarrays, and the number of elements in each subarray
 * Return: None
*/
void merge(int array[], int firstHalf[], int secondHalf[], int firstHalfNum, int secondHalfNum);



/* Name: mergeSort
 * Description: This function recursively sorts an array in ascending numerical order by splitting it into subarrays and then merging them back
 * 
 * Parameters: The array to sort
 * Return: None
 */ 
void mergeSort(int array[], int numElements);



//IMPLEMENTATIONS



//Function stringMerge
void merge(int array[], int firstHalf[], int secondHalf[], int firstHalfNum, int secondHalfNum) {

    //Loop counters
    int i = 0;
    int j = 0;
    int k = 0;

    //While the first and second subarrays aren't empty, insert the subarray elements sorted into the main array
    while (i < firstHalfNum && j < secondHalfNum) {

        //If the first subarray's number is smaller, add it to the main array
        if (firstHalf[i] < secondHalf[j]) {
            array[k] = firstHalf[i];
            i++;
        }

        //Otherwise, add the second subarray's number
        else {
            array[k] = secondHalf[j];
            j++;
        }

        k++;
    }

    //If the first subarray is empty, copy the remaining elements in the second subarray
    if (i == firstHalfNum) {

        while (j < secondHalfNum) {
            array[k] = secondHalf[j];
            j++;
            k++;
        }
    }

    //Else, if the second subarray is empty, copy the remaining elements in the first subarray
    else {

        while (i < firstHalfNum) {
            array[k] = firstHalf[i];
            i++;
            k++;
        }
    }
}



//Function mergeSort
void mergeSort(int array[], int numElements) {

    //Divide the number of elements into two halves
    int firstHalfNum = numElements / 2;
    int secondHalfNum = numElements - firstHalfNum;

    //The two subarrays each holding half the list
    int firstHalf[firstHalfNum];
    int secondHalf[secondHalfNum];

    //If there is more than one element in the array, recurse
    if (numElements > 1) {

        //Copy the first subarray's elements from the main array
        for (int i = 0; i < firstHalfNum; i++) {
            firstHalf[i] = array[i];
        }

        //Loop counter
        int k = 0;

        //Copy the second subarray's elements from the main array
        for (int j = firstHalfNum; j < numElements; j++) {
            secondHalf[k] = array[j];
            k++;
        }

        //Recursively divide the list, and then merge all the sorted subarrays
        mergeSort(firstHalf, firstHalfNum);
        mergeSort(secondHalf, secondHalfNum);
        merge(array, firstHalf, secondHalf, firstHalfNum, secondHalfNum);
    }
}
