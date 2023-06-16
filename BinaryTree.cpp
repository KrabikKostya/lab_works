#include "BinaryTree.h"
#include <vector>

Node::Node(int value){
    this->value = value;
    left = nullptr;
    right = nullptr;
}

Node::~Node() {
    delete left;
    delete right;
}

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

void BinaryTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->getLeft());
        destroyTree(node->getRight());
        delete node;
    }
}

void BinaryTree::insert(int value) {
    root = insertRecursive(root, value);
}

Node* BinaryTree::insertRecursive(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->getValue()) {
        node->left = insertRecursive(node->getLeft(), value);
    } else if (value > node->getValue()) {
        node->right = insertRecursive(node->getRight(), value);
    }

    return node;
}

void BinaryTree::remove(int value) {
    root = removeRecursive(root, value);
}

Node* BinaryTree::removeRecursive(Node* node, int value) {
    if (node == nullptr) {
        return node;
    }

    if (value < node->getValue()) {
        node->left = removeRecursive(node->getLeft(), value);
    } else if (value > node->getValue()) {
        node->right = removeRecursive(node->getRight(), value);
    } else {
        if (node->getLeft() == nullptr) {
            Node* temp = node->getRight();
            delete node;
            return temp;
        } else if (node->getRight() == nullptr) {
            Node* temp = node->getLeft();
            delete node;
            return temp;
        }

        Node* temp = findMin(node->getRight());
        node->value = temp->getValue();
        node->right = removeRecursive(node->getRight(), temp->getValue());
    }

    return node;
}

Node* BinaryTree::findMin(Node* node) const {
    while (node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}

Node* BinaryTree::search(int value) const {
    return searchRecursive(root, value);
}

Node* BinaryTree::searchRecursive(Node* node, int value) const {
    if (node == nullptr || node->getValue() == value) {
        return node;
    }

    if (value < node->getValue()) {
        return searchRecursive(node->getLeft(), value);
    }

    return searchRecursive(node->getRight(), value);
}

std::vector<int> BinaryTree::findPath(int value) const {
    std::vector<int> path;
    return findPathRecursive(root, value, path);
}

std::vector<int> BinaryTree::findPathRecursive(Node* node, int value, std::vector<int>& path) const {
    if (node == nullptr) {
        return path;
    }

    path.push_back(node->getValue());

    if (value < node->getValue()) {
        return findPathRecursive(node->getLeft(), value, path);
    } else if (value > node->getValue()) {
        return findPathRecursive(node->getRight(), value, path);
    }

    return path;
}
