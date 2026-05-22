#include "Tree_Lab7_Chernetsov.h"
#include <cstdlib>
#include <ctime>

namespace Lab7 {

    // Создание пустого дерева
    BinarySearchTree::BinarySearchTree() : root(nullptr) {}

    // Деструктор (удаление дерева)
    BinarySearchTree::~BinarySearchTree() {
        clear();
    }

    // Проверка пустоты
    bool BinarySearchTree::isEmpty() const {
        return root == nullptr;
    }

    // Рекурсивный метод вставки
    Node* BinarySearchTree::insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Добавление нового узла в дерево
    void BinarySearchTree::add(int value) {
        root = insert(root, value);
    }

    // Создание дерева (интервал значений и количество элементов)
    void BinarySearchTree::create(int n, int minVal, int maxVal) {
        clear();
        if (n <= 0 || minVal > maxVal) return;

        int attempts = 0;
        int count = 0;
        while (count < n && attempts < n * 10) {
            int val = minVal + std::rand() % (maxVal - minVal + 1);

            std::string before = getInOrder();
            add(val);
            if (getInOrder() != before) {
                count++;
            }
            attempts++;
        }
    }

    // Рекурсивный метод удаления всех узлов
    void BinarySearchTree::destroy(Node* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    // Удаление дерева (с помощью обхода снизу вверх)
    void BinarySearchTree::clear() {
        destroy(root);
        root = nullptr;
    }

    // Рекурсивный прямой обход: сначала корень, потом лево, потом право
    void BinarySearchTree::preOrder(Node* node, std::string& result, std::string delimiter) const {
        if (node != nullptr) {
            result += std::to_string(node->data) + delimiter;
            preOrder(node->left, result, delimiter);
            preOrder(node->right, result, delimiter);
        }
    }

    // Рекурсивный центрированный обход: лево, корень, право
    void BinarySearchTree::inOrder(Node* node, std::string& result, std::string delimiter) const {
        if (node != nullptr) {
            inOrder(node->left, result, delimiter);
            result += std::to_string(node->data) + delimiter;
            inOrder(node->right, result, delimiter);
        }
    }

    // Рекурсивный обратный обход: лево, право, корень
    void BinarySearchTree::postOrder(Node* node, std::string& result, std::string delimiter) const {
        if (node != nullptr) {
            postOrder(node->left, result, delimiter);
            postOrder(node->right, result, delimiter);
            result += std::to_string(node->data) + delimiter;
        }
    }

    // Интерфейсы для получения строк с результатами обходов
    std::string BinarySearchTree::getPreOrder(std::string delimiter) const {
        std::string result = "";
        preOrder(root, result, delimiter);
        return result;
    }

    std::string BinarySearchTree::getInOrder(std::string delimiter) const {
        std::string result = "";
        inOrder(root, result, delimiter);
        return result;
    }

    std::string BinarySearchTree::getPostOrder(std::string delimiter) const {
        std::string result = "";
        postOrder(root, result, delimiter);
        return result;
    }
}