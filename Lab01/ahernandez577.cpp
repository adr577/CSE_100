#include <iostream>


void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++) {

        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;

        for (int k = 0; k <= i; k++){
           
            std::cout << arr[k] << ";";
            
        }

        std::cout << std::endl;
    }
} 


int main () {

    int n;
    std::cin >> n;

    int arr[n];


    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    insertionSort(arr, n);


    return 0;
}
