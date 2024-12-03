#include <iostream>
#include <climits>
using namespace std;


//from textbook rod cutting pg 366-369


void extendedBottomUpCutRod(int* p, int n){
    int* s = new int[n + 1];
    int* r = new int[n + 1];
    int q;

    r[0] = 0;

    for (int j = 1; j < n; j++){
        q = INT_MIN;
        for (int i = 1; i <= j; i++){
            if(q < p[i] + r[j-i]){
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }

    n -= 1;
    cout << r[n] << '\n';

    while(n >0) {
        cout << s[n] << " ";
        n = n - s[n];
    }

    cout << "-1" << endl;

}

int main () {

    int n;
    cin >> n;

    int *p = new int[n + 1];
    p[0] = 0;

    for (int j = 1; j < n + 1; j++){
        cin >> p[j];
    }

    extendedBottomUpCutRod(p, n + 1);

    return 0;
}
