#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;


void heapify(int arr[], int size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        heapify(arr, size, largest);
    }
}


void heapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 1; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {

     ofstream file(/*file name*/);

   
    file << "Run,Time (nanoseconds)" << endl;

    for (int i = 1; i <= 10; i++){
        int arr[] = {/*array*/};
        
        int size = sizeof(arr) / sizeof(arr[0]);


        // Start timer
        auto start = high_resolution_clock::now();

        // Sort array
        heapSort(arr, size);

        // Stop timer
        auto stop = high_resolution_clock::now();

        // Calculate execution time
        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << "Heap Sort Execution Time: " << duration.count() << " nanoseconds" << endl;

        file << i << "," << duration.count() << endl;

    }

    file.close();

    return 0;
}