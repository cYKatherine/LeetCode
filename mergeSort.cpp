#include <bits/stdc++.h>

using namespace std;

void merge (vector<int> &a, int start, int mid, int end) {
    vector<int> b(a.size());
    int i = start, j = mid+1, count = start;
    while (i <= mid || j <= end) {
        if (i <= mid && j <= end) {
            if (a[i] <= a[j]) {
                b[count] = a[i];
                i++;
            }
            else {
                b[count] = a[j];
                j++;
            }
        }
        else if (i <= mid) {
            b[count] = a[i];
            i++;
        }
        else {
            b[count] = a[j];
            j++;
        }
        count++;
    }

    for (int i = start; i <= end; i++) {
        a[i] = b[i];
    }
}

void mergeSort(vector<int> &a, int start, int end) {
    if (start < end) {
        int mid = start + (end-start) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid+1, end);
        merge(a, start, mid, end);
    }
}

int main() {
    vector<int> a = {9, 10, 3, 2, 8, 7, 100, 25, 3, 1};
    mergeSort(a, 0, a.size()-1);
    for (auto& x : a) cout << x << " ";
    cout << endl;
}

