#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(int A[], int p, int r){

    int x = A[r]; //pivot element
    int i = p - 1; // i keeps track of the smaller elements' boundary

    for (int j = p; j <= r - 1; j++){
        // If current element is less than or equal to pivot, swap with element at i+1
        if(A[j] <= x){
            i += 1;

            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
 

    //placing the pivot in its correct position
    int temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    return (i + 1);
}

int randomizedPivot(int A[], int p, int r)
{
    // Select a random index between p and r
    int i = p + rand() % (r - p);

    // Swapping the randomly chosen pivot with the last element (A[r])
    int temp = A[r];
    A[r] = A[i];
    A[i] = temp;

    return partition(A, p, r);
}

void quickSort(int a[], int p, int r){

   
    if (p < r){

        // Partition the array and get the pivot position
        int q = randomizedPivot(a, p, r);

        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);

    }
}

int main() {

    int n;
    cin >> n;
    int arr[n];

    srand(time(0));

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int j = 0; j < n; j++){
        cout << arr[j] << ";";
    }

        return 0;
}
