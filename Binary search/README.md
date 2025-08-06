# Binary Search

Binary Search is a fundamental search algorithm used in computer science. It efficiently finds the position of a target element within a **sorted** array. Instead of searching each element one by one (like in linear search), binary search cuts the search space in half with each step, significantly reducing the number of comparisons.

---

## 📌 Prerequisites

* The array must be **sorted** (ascending or descending).

---

## 🔍 How Binary Search Works

1. Initialize two pointers:

   * `low` at the beginning of the array.
   * `high` at the end of the array.
2. Calculate the middle index:

   * `mid = (low + high) / 2`
3. Compare the middle element with the target:

   * If `arr[mid] == target`, return the index.
   * If `arr[mid] < target`, search in the **right** half (`low = mid + 1`).
   * If `arr[mid] > target`, search in the **left** half (`high = mid - 1`).
4. Repeat until the element is found or the search space becomes empty.

---

## 📦 Time and Space Complexity

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | O(1)            |
| Average Case | O(log n)        |
| Worst Case   | O(log n)        |

* **Space Complexity:** O(1) (iterative version) or O(log n) (recursive version due to call stack)

---

## 🧠 Intuition

> "Each time you look at the middle and eliminate half. That’s logarithmic thinking."

Binary search leverages the power of divide-and-conquer. It’s extremely efficient compared to linear search, especially for large data sets.

---

## ✅ When to Use

* When the array is sorted.
* When fast lookups are needed.
* Useful in solving search-related problems in logarithmic time.

---

## ❌ When NOT to Use

* On unsorted data (unless you sort it first, which takes O(n log n) time).
* When array size is very small and simplicity is preferred.

---

## 🧾 Example (Iterative Implementation in C++)

```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // to avoid overflow

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // not found
}
```

---

## 🔁 Recursive Implementation

```cpp
int binarySearchRecursive(vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) 
        return binarySearchRecursive(arr, mid + 1, high, target);
    else
        return binarySearchRecursive(arr, low, mid - 1, target);
}
```

---

## ⚙️ Variants of Binary Search

* Find the first or last occurrence of a number
* Find the floor/ceil of a number
* Lower bound / upper bound (like in STL)
* Binary Search on Answer (used in problems where answer lies in a range)

---

## 📚 Practice Problems

* [Binary Search on LeetCode](https://leetcode.com/problems/binary-search/)
* [Find First and Last Position of Element](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
* [Search Insert Position](https://leetcode.com/problems/search-insert-position/)
* [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

---

## 📖 Summary

Binary search is a powerful tool that works on sorted arrays to search efficiently in logarithmic time. Mastering it opens doors to many advanced algorithms.

> "Binary Search is not just an algorithm – it’s a way of thinking."

---

## 🧪 Dry Run Example

### Input:

```cpp
arr = [2, 4, 7, 10, 15], target = 10
```

### Steps:

1. low = 0, high = 4 → mid = 2 → arr\[2] = 7 → 7 < 10 → low = mid + 1 = 3
2. low = 3, high = 4 → mid = 3 → arr\[3] = 10 → Found ✅

---

## 🧠 Tips

* Always check edge cases (empty array, 1-element array)
* Watch out for infinite loops (update `low` and `high` correctly)
* Prefer `low + (high - low)/2` to avoid overflow
