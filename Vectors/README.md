# Vectors in C++

Vectors are dynamic arrays provided by the C++ Standard Template Library (STL). Unlike arrays, vectors can grow or shrink in size automatically during runtime.

## 🧠 Key Features:
- Dynamic resizing
- Random access (like arrays)
- In-built functions like `push_back()`, `pop_back()`, `size()`, etc.
- Easy to pass and return from functions

---

## 📚 Basic Operations

### 1. Declaration
```cpp
vector<int> v;




## INITIALISATION

vector<int> v = {1, 2, 3};





# Input from user
cpp
Copy
Edit
int n; cin >> n;
vector<int> v(n);
for (int i = 0; i < n; ++i) cin >> v[i];




4. Traversal
cpp
Copy
Edit
for (int x : v) cout << x << " ";





🔧 Useful Functions
Function	Description
push_back(x)	Add element x at the end
pop_back()	Remove last element
size()	Get number of elements
empty()	Check if vector is empty
clear()	Remove all elements
insert()	Insert elements at specific position
erase()	Erase elements from position
begin(), end()	Iterators





# 📘 Vectors in C++

Vectors are dynamic arrays provided by the C++ Standard Template Library (STL).  
They are powerful, flexible, and preferred over arrays in most modern C++ programming tasks.

---

## 🚀 What Makes Vectors Special?

- ✅ Dynamic size (grow/shrink during runtime)
- ✅ Uses **heap memory** for flexible storage
- ✅ Rich in-built functions like `push_back()`, `pop_back()`, `clear()`, etc.
- ✅ Easy to traverse, return from functions, and STL-compatible

---

## 🧠 Stack vs Heap Memory

| Feature       | Array                         | Vector                         |
|---------------|-------------------------------|--------------------------------|
| Memory        | Stack                         | Heap (internally)              |
| Size          | Fixed at compile-time         | Dynamic at runtime             |
| Flexibility   | Low                           | High                           |

➡️ Vectors internally store their data on **heap**, allowing automatic resizing.

---

## 🛠️ Vector vs Array

| Feature            | Array                         | Vector                          |
|--------------------|-------------------------------|----------------------------------|
| Size               | Fixed                         | Dynamic                          |
| Memory             | Stack                         | Heap                             |
| STL Functions      | Not available                 | Rich support (e.g., `sort`)      |
| Safe Access        | No bounds check               | Optional bounds check            |
| Function Return    | Difficult                     | Easy                             |
| Ease of Use        | Lower                         | Higher                           |

---

## ✍️ Basic Operations

### 1. Declaration & Initialization

```cpp
vector<int> v1;
vector<int> v2 = {1, 2, 3};




💡 push_back() Applications
➤ Add values dynamically when size is unknown:
cpp
Copy
Edit
vector<int> v;
int x;
while (cin >> x && x != -1)
    v.push_back(x);







💡 pop_back() Applications
➤ Implementing Undo operation:
cpp
Copy
Edit
vector<string> actions = {"Open", "Edit", "Save"};
actions.pop_back(); // Undo 'Save'