#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print(int i , int j, vector<vector<int> > &s, char& matrixName){
    if (i == j){
        cout << "A" << matrixName++;
        return;
    }

    cout << "(";
    print(i, s[i][j], s, matrixName);
    print(s[i][j] + 1, j, s, matrixName);
    cout << ")";
}

void matrixChainOrder(vector<int> &dimensions){
    int n = dimensions.size() - 1;

    vector<vector<int> > m;
    vector<vector<int> > s;

    m.resize(n, vector<int>(n, 0));
    s.resize(n, vector<int>(n, 0));

    for (int l = 2; l <= n; l++){
        for (int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++){
                int q = m[i][k] + m[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << m[0][n - 1] << endl;
    char matName = '0';
    print(0, n - 1, s, matName);
    cout << endl;
}

int main(){

    int n;
    cin >> n;
    vector<int> dimensions(n + 1);

    for(int i = 0; i <= n; i++){
        cin >> dimensions[i];
    }

    matrixChainOrder(dimensions);

    return 0;
}
