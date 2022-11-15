#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findCoFactor(vector<vector<int>> matrix, int n, int row) {
    vector<vector<int>> coFactor(n-1, vector<int>(n-1));
    int ind = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 1;j < n;j++) {
            if(i != row) {
                coFactor[ind/(n-1)][ind%(n-1)] = matrix[i][j];
                ind++;
            }
        }
    }
    return coFactor;
}

int findDeterminant(vector<vector<int>> matrix, int n) {
    
    if(n == 1)  return matrix[0][0];

    int ans = 0, sign = 1;
    for(int i = 0;i < n;i++) {
        ans = ans + sign*findDeterminant(findCoFactor(matrix, n, i), n-1)*matrix[i][0];
        sign *= -1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> matrix[i][j];
        }
    }

    int ans = findDeterminant(matrix, n);
    cout << ans << endl;
}