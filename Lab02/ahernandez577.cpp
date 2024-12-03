#include <iostream>


// Algorithm directly from the textbook as stated
void merge(int arr[], int l, int m, int h)  //Merge two sorted sub arrays
{

    //sizes of sub arrays
    int n1 = m - l + 1;
    int n2 = h - m;



    //created temp arrays 
    int left[n1 + 1], right[n2 + 1];


    //copy elements from arr[l..m] into left temp array[] & arr[m+1....h] into right temp array[]
    for (int i = 0; i < n1; i++){
        left[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++){
        right[j] = arr[m + 1 + j];
    }


    //setting sentinel valuues for left and right arrs
    right[n2] = INT_MAX;
    left[n1] = INT_MAX;

    int i = 0, j = 0;


    //Merging left[] and right[] back into original arr
    for (int k = l; k <= h; k++){

        //Comparing elements from left ad right and copy the smaller one into A first
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i = i + 1;
        }
        else {
            arr[k] = right[j];
            j = j + 1;
        }
    }
}

void mergeSort (int a[], int l, int h) {


    //if arr is one indice, we know not to do anything further
    if(l < h){
 

        //Split the array further and further until array in one index
        int mid = l + (h - l) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);

        merge(a, l, mid, h);
    }
}



int main () {

    int n;
    std::cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (int j = 0; j < n; j++){
        std::cout << arr[j] << ";";
    }


    return 0;
}
