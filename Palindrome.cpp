#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.length()-1;
    while(i < j) {
        if(s[i] != s[j])
            return false;
        i++;j--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    if(isPalindrome(s))
        cout << "String is Palindrome" << endl;
    else
        cout << "String is not a Palindrome" << endl;
}