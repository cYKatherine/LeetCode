#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &a) {
    for (int i = 1; i < a.size(); i++) {
        int j = i-1, cur = a[i];
        while (a[j] > cur && j >= 0) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = cur;
    }
}

int main() {
    vector<int> a = {9, 10, 3, 2, 8, 7, 100, 25, 3, 1};
    insertionSort(a);
    for (auto& x : a) cout << x << " ";
    cout << endl;
}
