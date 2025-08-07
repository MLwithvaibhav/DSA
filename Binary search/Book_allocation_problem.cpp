#include <iostream>
#include <vector>
using namespace std;

/*
    ✅ Approach:
    - Ye problem Book Allocation Problem hai.
    - Hume n books ko m students ke beech allocate karna hai such that maximum pages jo ek student padhe, wo minimum ho.
    - Hum binary search lagate hain 0 to sum of all pages ke beech.
    - Har mid value pe check karte hain ki kya hum books is maxAllowedPages (mid) ke andar students me distribute kar sakte hain.
    - Agar haan -> left side me jao (answer ko minimize karna hai)
    - Agar nahi -> right side me jao

    ✅ Dry Run:
    arr = {10, 20, 30, 40}, n = 4, m = 2

    Total sum = 100 -> range of search = 0 to 100
    mid = 50
    Check if books can be allocated with max 50 pages:
        - Student 1: 10 + 20 = 30 (ok), +30 = 60 > 50 -> new student
        - Student 2: 30 (ok), +40 = 70 > 50 -> new student
        - Total students = 3 > 2 => Not possible

    So go right

    mid = 75
    Try again:
        - Student 1: 10+20+30 = 60 (ok), +40 = 100 > 75 -> new student
        - Student 2: 40 (ok)
        - Total students = 2 <= 2 => possible

    Update ans = 75, move left to find better
*/

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int students = 1, pages = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxAllowedPages) {
            return false;
        }

        if(pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }

    return students <= m;
}

int allocateBooks(vector<int> &arr, int n, int m) {
    if(m > n) return -1;

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int ans = -1;
    int st = 0, end = sum;

    while(st <= end) {
        int mid = st + (end - st) / 2;

        if(isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return ans;
}
