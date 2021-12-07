#include <iostream>
#include <cmath>
using namespace std;

void sortArray(int * array, int size) {

    int minimum;
    int temporary;

    for (int i = 0; i < (size - 1); i++) {

        minimum = i;

        for (int j = i + 1; j < size; j++) {

            if (array[j] < array[minimum]) {

                minimum = j;
                temporary = array[i];
                array[i] = array[minimum];
                array[minimum] = temporary;

            }

        }

    }
}

int * generateArray(int size) {

    int * arr = new int[size];

    return arr;

}

int algo1(int * arr1, int * arr2, int size1, int size2) {

    // Loop through arr2
    for (int i = 0; i < size2; i++) {

        // Loop through arr1
        for (int j = 0; j < size1; j++) {

            if (arr2[i] == arr1[j]) {

                // Match found
                break;

            }

            // Reached last index and no match found yet
            if (j == (size1 - 1)) {

                // No match found - arr2 is not subset of arr1
                return 0;

            }

        }

    }

    // arr2 is subset of arr1
    return 1;

}

bool binarySearch(const int * array, int firstIndex, int lastIndex, int valueToSearchFor) {

    // Find the midIndex of arr1
    int midIndex = (firstIndex + lastIndex) / 2;

    // Verify if the midIndex is the value
    if (array[midIndex] == valueToSearchFor) {
        return true;
    }

    // Verify if the value is less than midIndex
    if (array[midIndex] > valueToSearchFor) {
        return binarySearch(array, firstIndex, midIndex - 1, valueToSearchFor);
    }

    // Verify if the value is greater than midIndex
    else {
        return binarySearch(array, midIndex + 1, lastIndex, valueToSearchFor);
    }

}

int algo2(int * arr1, int * arr2, int size1, int size2) {

    for (int i = 0; i < size2; i++) {

        bool binarySearchResult = binarySearch(arr1, 0, size1 - 1, arr2[i]);

        if (!binarySearchResult) {
            return 0;
        }

    }

    return 1;

}

int * createFrequencyTable(int * array, int size) {

    // Maximum value in arr1
    int maximumValue = 0;

    // Loop through arr1 and find maximum value
    for (int i = 0; i < size; i++) {

        if (array[i] > maximumValue) {
            maximumValue = array[i];
        }

    }

    // Create frequency array with size of maximum value of arr1
    int * freqArray = new int[maximumValue];

    // Fill array with 0's
    for (int i = 0; i < (maximumValue); i++) {
        freqArray[i] = 0;
    }

    return freqArray;

}

int algo3(int * arr1, int * arr2, int size1, int size2) {

    // Generate frequency array using arr1
    int * freqArray = createFrequencyTable(arr1, size1);

    // Loop through arr1 and fill frequency array
    for (int i = 0; i < size1; i++) {
        freqArray[arr1[i]] += 1;
    }

    // Loop through arr2
    for (int i = 0; i < size2; i++) {

        // Element found, decrement frequency array's index by 1
        if (freqArray[arr2[i]] > 0) {
            freqArray[arr2[i]]--;
        }

        // Element not found
        else {
            return 0;
        }

    }

    delete [] freqArray;

    // All elements found
    return 1;

}

int main() {

    for (int iteration = 1; iteration <= 10; iteration++) {

        // Determine size of arr1 and arr2
        int size1 = 100000 * iteration;
        int size2 = 1000;

        // Create arr1
        int * arr1 = generateArray(size1);

        // Create arr2
        int * arr2 = generateArray(size2);

        srand(time(0));

        // Fill arr1 with random integers
        for (int i = 0; i < size1; i++) {

            arr1[i] = rand() % 10;

        }

        // Sort arr1
        sortArray(arr1, size1);

        // Fill arr2 with random integers
        for (int i = 0; i < size2; i++) {
            arr2[i] = rand() % 10;
        }

        // ALGORITHM 1

        // Create clock
        double duration;
        clock_t startTime = clock();

        algo1(arr1, arr2, size1, size2);

        // Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution for Algorithm 1 with n as " << iteration << " * 10^5 and m as " << size2 << " took " << duration << " milliseconds." << endl;

        // ALGORITHM 2
        startTime = clock();

        algo2(arr1, arr2, size1, size2);

        // Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution for Algorithm 2 with n as " << iteration << " * 10^5 and m as " << size2 << " took " << duration << " milliseconds." << endl;

        // ALGORITHM 3
        startTime = clock();

        algo3(arr1, arr2, size1, size2);

        // Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution for Algorithm 3 with n as " << iteration << " * 10^5 and m as " << size2 << " took " << duration << " milliseconds." << endl;

        cout << "---------------------------------------------------------------" << endl;

        delete [] arr1;
        delete [] arr2;

    }

    return 0;

}
