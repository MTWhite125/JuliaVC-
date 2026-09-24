#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

void bubbleSort(int arr[], int size) {

    for (int i = 1; i <= size - 1; i++) {

        for (int j = 0; j < size - i; j++) {

            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }

        }

    }

}
int main() {

     ofstream file(/*file name*/);

   
    file << "Run,Time (nanoseconds)" << endl;

    for (int i = 1; i <= 10; i++){
        int arr[] = {/*Array*/  };

        int size = sizeof(arr) / sizeof(arr[0]);

        // Start timer
        auto start = high_resolution_clock::now();

        // Sort array
        bubbleSort(arr, size);

        // Stop timer
        auto stop = high_resolution_clock::now();

        // Calculate execution time
        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << "Bubble Sort Execution Time: " << duration.count() << " nanoseconds" << endl;

        file << i << "," << duration.count() << endl;
    
    }

    file.close();

    return 0;
}