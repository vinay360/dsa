#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int key) {
    int s = 0, e = arr.size()-1;
    while(s <= e) {
        int mid = (s+e)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            e = mid-1;
        else
            s = mid+1; 
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i: arr)
        cin >> i;
    int key;
    cin >> key;
    cout << binarySearch(arr, key) << endl;
}