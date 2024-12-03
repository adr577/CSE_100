#include <iostream>
#include <climits>

using namespace std;


int maxCrossingSum(int a[], int left, int mid, int right){


    int sum = 0;
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;



    //starts from the middle, adds the sum up continiously if mid - i is > sum 
    for (int i = mid; i >= left; i--){
        sum = sum + a[i];
        if(sum > left_sum){
            left_sum = sum;
        }
    }

    sum = 0;

    for (int j = mid + 1 ; j <= right; j++){
        sum = sum + a[j];

        if(sum > right_sum){
            right_sum = sum;
        }
    }


    //Guarentees no overflow 
    if (left_sum == INT_MIN)
        left_sum = 0;
    if (right_sum == INT_MIN)
        right_sum = 0;

    return left_sum + right_sum;
}

int maxSubArray (int arr[], int l, int h){


    //Base case, once it reaches the leafs
    if(l == h){
        return arr[l];
    }

    int mid = l + (h - l) / 2;





    int leftSum = maxSubArray(arr, l, mid);
    int rightSum = maxSubArray(arr, mid + 1, h);
    int crossSum = maxCrossingSum(arr, l, mid, h);

    int maxSum = crossSum;


    // compares left, right, and cross sum to find the max.
    if(leftSum > maxSum ){
        maxSum = leftSum;
    }

    if(rightSum > maxSum){
        maxSum = rightSum;
    }

    return maxSum;
}

int main () {

    int n;
    cin >> n;

    int* arr = new int[n];
 


    //fill up the array with n inputs
    for (int i = 0; i < n; i++){

        cin >> arr[i];
    }


    int maxSum = maxSubArray(arr, 0, n - 1);

    cout << maxSum;

    delete[] arr;

    return 0;
}
