#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int>& arr) {
    int count0 = 0, count1 = 0, count2 = 0;

    // Count 0s, 1s, and 2s
    for (int x : arr) {
        if (x == 0) count0++;
        else if (x == 1) count1++;
        else count2++;
    }

    // Overwrite array
    int i = 0;
    while (count0--) arr[i++] = 0;
    while (count1--) arr[i++] = 1;
    while (count2--) arr[i++] = 2;
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2};

    sort012(arr);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
