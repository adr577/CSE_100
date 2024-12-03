#include <iostream>
#include <cmath>

void maxHeapify(int a[], int i, int n);

using namespace std;

//helper functions
int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

void buildMaxHeap(int a[], int s){

    for (int i = floor(s / 2); i >= 0; i--){
        maxHeapify(a, s, i);
    }
}




void maxHeapify(int a[], int n, int i){

    int l = left(i);  //left child of root
    int r = right(i); //right child of root
    int greatest = i; //initialize greatest as the root

    // Check if the left child exists and is larger than the current greatest
    if(l < n && a[l] > a[greatest]){
        greatest = l;
    }

    // Check if the right child exists and is larger than the current greatest
    if(r < n && a[r] > a[greatest]){
        greatest = r;
    }

    // If largest is not the root, swap a[i] with a[greatest]
    if(greatest != i){
        int temp = a[i];
        a[i] = a[greatest];
        a[greatest] = temp;

        maxHeapify(a, n, greatest); // Recursively heapify the affected sub-tree
    }

}

void heapSort(int a[], int n)
{

    // Build a max heap
    buildMaxHeap(a, n);

    // Once sorted, swap the root(largest element) with the last element and heapify the reduced heap
    for (int j = n - 1; j >= 1; j--)
    {

        int root = a[0];
        a[0] = a[j]; // root is now the last element
        a[j] = root; // last element is now the root

        maxHeapify(a, j, 0); // Heapify the reduced heap (excluding the sorted part)
    }
}

int main (){

    int n;  //size of the array from user
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){  // filling up the array
        cin >> arr[i];
    }

    heapSort(arr, n);

    for (int j = 0; j < n; j++){
        cout << arr[j] << ";";
    }


    return 0;
}
