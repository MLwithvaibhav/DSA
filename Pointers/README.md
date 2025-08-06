# 🎯 Pointers in C++

Pointers are variables that **store the address** of other variables. They are one of the most powerful features of C++ and essential for mastering DSA (Data Structures & Algorithms).

---

## 🧠 Basic Concepts

### 📌 What is a Pointer?

```cpp
int a = 10;
int* p = &a;

&a → Address of variable a

*p → Value at the address stored in p (dereferencing)



| Operator | Meaning                                 | Example             |
| -------- | --------------------------------------- | ------------------- |
| `&`      | Address-of operator                     | `&a` = address of a |
| `*`      | Dereference operator (value at address) | `*p` = value at p   |



| Feature  | Stack                            | Heap                             |
| -------- | -------------------------------- | -------------------------------- |
| Usage    | Normal variable storage          | Dynamic memory (`new`, `malloc`) |
| Lifetime | Auto-deleted after function ends | Must be freed manually           |
| Access   | Direct                           | Via pointers                     |




🛠️ Common Use Cases
✅ Pointer with Variables
cpp
Copy
Edit
int x = 5;
int* ptr = &x;
cout << *ptr << endl; // Outputs 5





✅ Pointer with Arrays
cpp
Copy
Edit
int arr[3] = {10, 20, 30};
int* p = arr;
cout << *(p + 1); // Outputs 20





✅ Pointer to Pointer
cpp
Copy
Edit
int x = 10;
int* p = &x;
int** pp = &p;
cout << **pp; // Outputs 10





✅ Pointer as Function Parameter
cpp
Copy
Edit
void update(int* p) {
    *p = *p + 1;
}





✅ Dynamic Memory Allocation (Heap)
cpp
Copy
Edit
int* p = new int;
*p = 10;
delete p;