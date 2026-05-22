#ifndef TREE_LAB7_CHERNETSOV_H
#define TREE_LAB7_CHERNETSOV_H

#include <string>

namespace Lab7 {
    // Структура узла бинарного дерева поиска
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    class BinarySearchTree {
    private:
        Node* root;

        // Рекурсивный метод вставки
        Node* insert(Node* node, int value);

        // Рекурсивный метод удаления всех узлов
        void destroy(Node* node);

        // Рекурсивный прямой обход: сначала корень, потом лево, потом право
        void preOrder(Node* node, std::string& result, std::string delimiter) const;

        // Рекурсивный центрированный обход: лево, корень, право
        void inOrder(Node* node, std::string& result, std::string delimiter) const;

        // Рекурсивный обратный обход: лево, право, корень
        void postOrder(Node* node, std::string& result, std::string delimiter) const;

    public:
        // Создание пустого дерева
        BinarySearchTree();
        
        // Деструктор (удаление дерева)
        ~BinarySearchTree();

        // Проверка пустоты
        bool isEmpty() const;

        // Добавление нового узла в дерево
        void add(int value);

        // Создание дерева (интервал значений и количество элементов)
        void create(int n, int minVal, int maxVal);

        // Удаление дерева (с помощью обхода снизу вверх)
        void clear();

        // Интерфейсы для получения строк с результатами обходов
        std::string getPreOrder(std::string delimiter = " ") const;
        std::string getInOrder(std::string delimiter = " ") const;
        std::string getPostOrder(std::string delimiter = " ") const;
    };
}

#endif