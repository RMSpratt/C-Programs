#include <stdio.h>



/* Name: binarySearchIntegers
 * Description: This function performs binary search on an array of integers non-recursively.
 *              An integer will be returned to indicate if the desired search number exists in
 *              the array. (0 for false and 1 for true).
 *  
 * Parameters: The array of integers, the length of the array, and the number to search for
 * Return: 0 or 1
*/ 
int binarySearchIntegers(int array[], int length, int searchNum);



int main() {

    int numbers[10] = {1, 2, 3, 5, 7, 9, 11, 12, 13, 15};

    int result = binarySearchIntegers(numbers, 10, 3);

    if (result == 1) {
        printf("The element was found!\n");
    }

    else {
        printf("The element was not found.\n");
    }

    return 0;
}



//Function binarySearchIntegers
int binarySearchIntegers(int array[], int length, int searchNum) {

    //Set the left and right indicies to the bounds of the array
    int leftIndex = 0;
    int rightIndex = length - 1;

    //While the left index is less than the right index, keep searching
    while (leftIndex <= rightIndex) {

        //Grab the middle index of the array
        int middleIndex = (leftIndex + rightIndex) / 2;

        //If the search number is less than the middle index, search the first half of the array
        if (searchNum < array[middleIndex]) {
            rightIndex = middleIndex - 1;
        }

        //If the search number is greater than the middle index, search the second half of the array
        else if (searchNum > array[middleIndex]) {
            leftIndex = middleIndex + 1;
        }

        //If the search number matches the middle index, return
        else {
            return 1;
        }
    }

    return 0;
}
