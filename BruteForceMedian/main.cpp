#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;


int BruteForceMedian(int* A, int n);
void printArray(int* A, int n);
void populateArray(int* A, int ArraySize);

const int ArraySizeIncrement = 10000;
const int maxValue = 100;
const int trials = 10;

int basic_operations;


int main()
{
    int ArraySize = 10000;
    int A[ArraySize];
    double results;

    cout << "Assessment 1: BruteForceMedian | Sai Whiley n9454829" << endl;

    for(int i = 0; i < trials; i ++){
        populateArray(A,ArraySize);

        cout << "Testing a random array of size " << ArraySize;
        cout << i << ": ";

        clock_t start_time = clock();
        results = BruteForceMedian(A, ArraySize);
        clock_t end_time = clock();

        double time_elapsed = (end_time - start_time) / double(CLOCKS_PER_SEC);
        cout << "median = " << results;
        cout << " time_elapsed = " << time_elapsed << "ms" << endl;

        ofstream resultsFile;
        resultsFile.open("results.csv");
        resultsFile << "Results of " << trials << " trials of increments " << ArraySizeIncrement << ".\n";
        resultsFile << ArraySize << "," << basic_operations << "," << time_elapsed << ",\n";
        resultsFile.close();

        cout << "Average time taken to process one array:" << time_elapsed << endl;
        cout << "array size: " << ArraySize << endl;
        cout << "basic operations: " << basic_operations;
        ArraySize += ArraySizeIncrement;

    }
//    int arrayOne[] = {1,2,3,3,4,4,4,4,5};
//    int arrayOneLength = sizeof(arrayOne)/sizeof(arrayOne[0]);
//    cout << "First array: ";
//    printArray(arrayOne, arrayOneLength);
//    cout << "median = " << BruteForceMedian(arrayOne, arrayOneLength) << endl;
//
//    int singleArray[] = {1};
//    int singleArrayLength = sizeof(singleArray)/sizeof(singleArray[0]);
//    cout << "Array containing one value";
//    printArray(singleArray, singleArrayLength);
//    cout << "median = " << BruteForceMedian(singleArray, singleArrayLength) << endl;
    return 0;
}

int BruteForceMedian(int* A, int n){
    //k is the position of the median if the array were to be sorted
    int k = n/2;
    int numsmaller;
    int numequal;

    //compare each entry to each other, tracking how many are the same
    //and how many are less than
    for(int i=0; i < n ; i++){
        numsmaller = 0;
        numequal = 0;

        for(int j=0; j < n; j++){
            if(A[j] < A[i]){
                numsmaller++;
                basic_operations++;
            }
            else if(A[j] == A[i]){
                numequal++;
                basic_operations++;
            }
        }
        //if there are less smaller values than k
        //and there are more combined smaller and equal values than k
        //we have found the median
        if(numsmaller < k && k <= (numsmaller + numequal)){
            return(A[i]);
        }

    }
}

void populateArray(int* A, int arraySize){
    for(int j = 0; j < arraySize; j ++){
        A[j] = rand() % maxValue;
    }
}

void printArray( int **A, int n){
    cout << "[";
    cout << A[0];
    for(int i = 1; i < n; i++){
        cout << ", ";
        cout << A[i];
    }
    cout << "]" << endl;
}
