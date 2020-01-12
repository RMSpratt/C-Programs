/*
 * Author: Reed Spratt
 *
 * Description: This program performs recursive branch and bound to search for a desired sum using a list of positive integers. 
 *              All solutions are displayed from within the function, along with any dead-ends reached, with the reason behind the dead-end. 
 *
 * Date: January 12th 2020
*/



/* Name: searchForSubsets
 * Description: This function does a recursive branch and bound search for a desired sum in a list of positive integers, using a subset of the list.
 *              Any solutions are outputted along with the subset of elements that made up the sum, along with any dead-ends reached with reasoning.
 * 
 * Parameter: list                                  The list of numbers to search for a solution to
 * Parameter: numElements                           The number of elements in the list
 * Parameter: desiredSum                            The sum to find a subset of integers for
 * Parameter: currentSum                            The current sum for each branching path
 * Parameter: remainingSum                          The remaining sum of the elements left in the list
 * Parameter: currentElement                        The current element index being considered
 * Parameter: solution                              The subset of elements making up the possible sum
 * Return: None
*/ 
void searchForSubsets(int list[], int numElements, int desiredSum, int currentSum, int remainingSum, int currentElement, int solution[]);



//FUNCTION searchForSubsets
void searchForSubsets(int list[], int numElements, int desiredSum, int currentSum, int remainingSum, int currentElement, int solution[]) {

    //If the current sum is equal to the desired sum, we found a solution
    if (currentSum == desiredSum) {
        printf("Found a solution. Subset Sum: %d\n", currentSum);

        //Print the solution subset
        printf("Solution subset: ");

        //Iterate through the solution subset
        for (int i = 0; i < currentElement; i++) {

            //Ignore any -1 elements, as these indicate the element at those indices were not added to the subset
            if (solution[i] != -1) {
                printf("%d ", solution[i]);
            }
        }

        printf("\n");
    }

    //Else if we've reached an end of the tree without reaching the sum, it's a dead-end
    else if (currentElement >= numElements) {
        printf("Reached a dead-end. Subset Sum: %d (End of tree)\n", currentSum);
    }

    //Else if the current sum is greater than the desired sum, we don't explore further
    else if (currentSum > desiredSum) {
        printf("Reached a dead-end. Subset Sum: %d (Overflow)\n", currentSum);
    }

    //Else if the current sum + the remaining sum is less than the desired sum, we don't explore further
    else if (currentSum + remainingSum < desiredSum) {
        printf("Reached a dead-end. Subset Sum: %d (Underflow)\n", currentSum);
    }

    //Else, recur further
    else {

        //Calculate the new remainder sum for the remaining elements to check
        remainingSum = remainingSum - list[currentElement];

        //Recur with the same subset that ignores the current element. Don't add the element to the solution subset
        solution[currentElement] = -1;
        searchForSubsets(list, numElements, desiredSum, currentSum, remainingSum, currentElement + 1, solution);

        //Recur with a new subset that adds the current element. Add the element to the solution subset
        solution[currentElement] = list[currentElement];
        searchForSubsets(list, numElements, desiredSum, currentSum + list[currentElement], remainingSum, currentElement + 1, solution);
    }
}
