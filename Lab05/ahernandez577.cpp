#include <iostream>
#include <vector>

// RADIX-SORT.A; d /

//use a stable sort to sort array A on digit i

using namespace std;

void countingSort(vector<int> A[], vector<int> B[], int k, int s){

    int C[10]; // Create an array C to store the count of each digit (0-9).

    // Initialize the count array to 0 for each possible digit
    for (int i = 0; i < 10; i++){  
        C[i] = 0;
    }

    // Count the occurrences of each digit in the current digit position (k)
    for (int j = 0; j < s; j++){
            C[A[j][k]]++;
    }

    //cumulative count
    for (int i = 1; i < 10; i++){
        C[i] = C[i] + C[i - 1];
    }

    // building the sorted output of array B using the cumulative counts.

    for (int j = s - 1; j >= 0; j--){
        B[C[A[j][k]] - 1] = A[j];
        C[A[j][k]]--;
    }
}

void radixSort(vector<int> A[], vector<int> B[], int s){

    for (int digit = 9; digit >= 0; digit--) {
        countingSort(A, B, digit, s);
        for (int i = 0; i < s; i++){
            A[i] = B[i]; //Copy elements from B into original array
        }
    }
}

int main () {

    int total;
    cin >> total;


    vector<int> A[total]; 
    vector<int> B[total];

    for(int i = 0; i < total; i++){   //For total amount, fill up vector total with 10 elements (0,1, 2, 3)

        for(int j = 0; j < 10; j++){ 
            int value;
            cin >> value;
            A[i].push_back(value);

        }
    }

    radixSort(A, B, total);


    for (int i = 0; i < total; i++){
        for (int j = 0; j < 10; j++){
            cout << A[i][j] << ";";
        }

        cout << '\n';
    }

        return 0;
    
}
