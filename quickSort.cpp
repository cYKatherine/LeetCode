#include <bits/stdc++.h>

using namespace std;

int partition (vector<int> &a, int start, int end) {
    int mid = start + (end-start)/2;
    int tmp = a[mid];
    a[mid] = a[start];
    a[start] = tmp;
    int index = start;
    for (int i = start+1; i <= end; i++) {
        if (a[i] < a[start]) {
            index += 1;
            tmp = a[index];
            a[index] = a[i];
            a[i] = tmp;
        }
    }
    tmp = a[index];
    a[index] = a[start];
    a[start] = tmp;

    return index;
}

void quickSort(vector<int> &a, int start, int end) {
    if (start < end) {
        int index = partition(a, start, end);
        quickSort(a, start, index-1);
        quickSort(a, index+1, end);
    }
}

int main() {
    vector<int> a = {9, 10, 3, 2, 8, 7, 100, 25, 3, 1};
    quickSort(a, 0, a.size()-1);
    for (auto& x : a) cout << x << " ";
    cout << endl;
}

