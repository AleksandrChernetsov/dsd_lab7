#include <iostream>
#include <clocale>
#include <ctime>
#include "Tree_Lab7_Chernetsov.h"

using namespace std;
using namespace Lab7;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(static_cast<unsigned>(time(0)));

    BinarySearchTree tree;

    cout << "Лабораторная работа № 7: Бинарное дерево поиска" << endl;

    // 1. Проверка пустоты
    cout << "1. Проверка на пустоту: " << (tree.isEmpty() ? "Дерево пустое" : "Дерево содержит узлы") << endl;

    // 2. Создание дерева
    int n = 10;
    int minV = 10, maxV = 99;
    cout << "2. Создание дерева (n=" << n << ", диапазон [" << minV << ", " << maxV << "])..." << endl;
    int* values = new int[n];
    for (int i = 0; i < n; ++i) {
        int val;
        bool unique;
        do {
            val = minV + rand() % (maxV - minV + 1);
            unique = true;
            for (int j = 0; j < i; ++j)
                if (values[j] == val) { unique = false; break; }
        } while (!unique);
        values[i] = val;
    }
    cout << "   Порядок добавления: ";
    for (int i = 0; i < n; ++i) {
        cout << values[i] << " ";
        tree.add(values[i]);
    }
    cout << endl;
    delete[] values;

    // 3. Обходы
    cout << "\n3. Тестирование обходов дерева:" << endl;
    cout << "   Сверху вниз (Pre-order):  " << tree.getPreOrder() << endl;
    cout << "   Слева направо (In-order): " << tree.getInOrder() << endl;
    cout << "   Снизу вверх (Post-order): " << tree.getPostOrder() << endl;

    // 4. Добавление узла
    int newVal = 50;
    cout << "\n4. Добавление узла со значением " << newVal << "..." << endl;
    tree.add(newVal);
    cout << "   In-order после добавления: " << tree.getInOrder() << endl;

    // 5. Удаление дерева
    cout << "\n5. Удаление дерева..." << endl;
    tree.clear();
    cout << "   Проверка после удаления: " << (tree.isEmpty() ? "Дерево успешно очищено" : "Ошибка очистки") << endl;

    cout << "\nТестирование завершено." << endl;

    return 0;
}