#include <iostream>
#include <vector>
using namespace std;

/*
❓ Question:
Search for a given element in a vector and print its index if found.
*/

int main() {
    vector<int> v = {3, 8, 1, 7, 4};
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    bool found = false;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key) {
            cout << "Element found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Element not found." << endl;

    return 0;
}
