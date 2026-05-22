# Binary Search Tree Implementation (Lab 7) – C++ Console Application

This project implements a **Binary Search Tree (BST)** class in C++. The tree stores integer values and provides standard BST operations: insertion, emptiness check, tree creation with random unique values within a given range, three types of traversals (pre‑order, in‑order, post‑order), and complete tree deletion using a post‑order traversal.

The main program tests all implemented methods, demonstrating the tree’s behaviour step by step.

## 📚 Assignment Requirements

Develop a **“Binary Search Tree”** class with the following methods:

- Create an empty tree (constructor)
- Check if the tree is empty (`isEmpty`)
- Insert a new node into the tree (`add`)
- Create a tree with a specified number of elements and a value range (`create`)
- Traverse the tree **top‑down** (pre‑order) – returns a string
- Traverse the tree **left‑to‑right** (in‑order) – returns a string
- Traverse the tree **bottom‑up** (post‑order) – returns a string
- Delete the entire tree using a bottom‑up traversal (`clear`)

The main program must test all of the above methods.

## ✨ Features

- **Binary Search Tree** implemented from scratch (no use of STL containers for the tree itself)
- Recursive insertion preserving BST property (left < root ≤ right)
- Generation of a tree with random **unique** integers within a given range
- Three recursive traversal algorithms:
  - `getPreOrder()` – root, left subtree, right subtree
  - `getInOrder()` – left subtree, root, right subtree (returns sorted order)
  - `getPostOrder()` – left subtree, right subtree, root
- Tree destruction using post‑order traversal (deletes children before the node)
- Clean memory management (no leaks)
- Russian console output (UTF‑8) for clear step‑by‑step demonstration

## 🗂️ File Structure

```
dsd_lab7.slnx                          # Visual Studio solution file
README.md                              # This file
dsd_lab7/                              # Project folder
├── dsd_lab7.vcxproj                   # Visual Studio project file
├── dsd_lab7.vcxproj.filters           # Project filters
├── Lab7_Chernetsov.cpp                # Main program – tests all methods
├── Tree_Lab7_Chernetsov.h             # BST class declaration (Node + BinarySearchTree)
└── Tree_Lab7_Chernetsov.cpp           # BST class implementation
```

## 🛠️ Requirements

- C++ compiler with **C++11 support** (or later)
- Standard C++ Library (STL) – only used for `std::string` and `rand()`/`srand()`
- For proper Russian text on Windows, the console codepage is set to UTF‑8 (`setlocale(LC_ALL, "ru_RU.UTF-8")`).  
  On non‑Windows systems you may need to remove or adjust this line.

## 🚀 Building and Running

### Using g++ (MinGW, Linux, macOS)

```bash
g++ -o lab7 Lab7_Chernetsov.cpp Tree_Lab7_Chernetsov.cpp -std=c++11
./lab7
```

### Using Visual Studio

1. Open the solution file `dsd_lab7.slnx`
2. Build the solution (`Ctrl+Shift+B`)
3. Run (`F5`)

> ⚠️ On non‑Windows systems, comment out or remove the `setlocale(LC_ALL, "ru_RU.UTF-8")` line in `Lab7_Chernetsov.cpp` to avoid compilation errors or console output issues.

## 🧪 Example Output

When you run the program, it will:

1. Check emptiness (initially empty).
2. Create a tree with **10 random unique integers** between 10 and 99.
3. Display the three traversals.
4. Insert an additional value (50) and show the in‑order traversal after insertion.
5. Clear the tree and verify that it becomes empty.

A typical output (values will differ due to `rand()`) is shown below:

```
Лабораторная работа № 7: Бинарное дерево поиска
1. Проверка на пустоту: Дерево пустое
2. Создание дерева (n=10, диапазон [10, 99])...
   Порядок добавления: 45 23 78 12 34 67 90 56 89 10 

3. Тестирование обходов дерева:
   Сверху вниз (Pre-order):  45 23 12 10 34 78 67 56 90 89 
   Слева направо (In-order): 10 12 23 34 45 56 67 78 89 90 
   Снизу вверх (Post-order): 10 12 34 23 56 67 89 90 78 45 

4. Добавление узла со значением 50...
   In-order после добавления: 10 12 23 34 45 50 56 67 78 89 90 

5. Удаление дерева...
   Проверка после удаления: Дерево успешно очищено

Тестирование завершено.
```

## 🔍 Implementation Details

- **Node structure** – holds an integer `data`, pointers to left and right children.
- **`insert`** – private recursive helper that returns the new subtree root. It inserts the value in the correct place (no duplicates allowed – if the value already exists, it is ignored).
- **`create(int n, int minVal, int maxVal)`** – clears the current tree, then repeatedly generates random numbers within the given range until `n` unique values have been inserted. A safety limit prevents infinite loops if the range is too small.
- **Traversal methods** – each returns a `std::string` with values separated by a customizable delimiter (space by default). They are implemented recursively.
- **`clear()`** – uses `destroy(Node*)`, which performs a post‑order deletion (delete left subtree, then right subtree, then the node itself).
- **Destructor** – automatically calls `clear()` to free all memory.

## 📝 Notes

- The tree **does not allow duplicate values**. If you try to insert an existing number, the insertion is silently ignored.
- The `create` method uses `std::rand()` – make sure to call `srand(time(0))` once in `main` to get different sequences each run.
- The main program demonstrates the required operations in exactly the order specified by the assignment.

## 👤 Author

**Aleksandr Chernetsov**  
Group: 24VP1  
Laboratory work for the course *Programming of Dynamic Data Structures*

## 📄 License

This project is created for educational purposes. Free use, modification, and distribution are permitted with attribution.
