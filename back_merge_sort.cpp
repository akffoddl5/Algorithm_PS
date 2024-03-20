#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10]{ 5,4,3,2,1,6,7,8,9,0 };
int tmp[10];
void merge(int st, int ed) {

    int mid = (st + ed) / 2;


    int idx1 = st;
    int idx2 = mid;

    for (int i = st; i < ed; i++) {
        if (idx1 == mid)  tmp[i] = arr[idx2], idx2++;
        else if (idx2 == ed)  tmp[i] = arr[idx1], idx1++;
        else if (arr[idx1] < arr[idx2]) tmp[i] = arr[idx1], idx1++;
        else tmp[i] = arr[idx2], idx2++;
    }

    for (int i = st; i < ed; i++) {
        arr[i] = tmp[i];
    }

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

}

void merge_sort(int st, int ed) {
    if (st + 1 == ed) return;

    int mid = (st + ed) / 2;
    merge_sort(st, mid);
    merge_sort(mid, ed);
    merge(st, ed);
}

int main() {

    merge_sort(0, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}