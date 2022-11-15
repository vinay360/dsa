#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int element) {
    for(int i = 0;i < arr.size();i++) {
        if(arr[i] == element)
            return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i: arr)
        cin >> i;
    int element;
    cin >> element;
    cout << search(arr, element);
}