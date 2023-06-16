#ifndef BINARYTREE_H
#define BINARYTREE_H

class Node {
public:
    Node(int value);
    ~Node();

    int getValue() const { return value; }
    Node* getLeft() const { return left; }
    Node* getRight() const { return right; }

private:
    int value;
    Node* left;
    Node* right;
};

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    void insert(int value);
    void remove(int value);
    Node* search(int value) const;
    std::vector<int> findPath(int value) const;

private:
    Node* root;

    void destroyTree(Node* node);
    Node* insertRecursive(Node* node, int value);
    Node* removeRecursive(Node* node, int value);
    Node* findMin(Node* node) const;
    Node* searchRecursive(Node* node, int value) const;
    std::vector<int> findPathRecursive(Node* node, int value, std::vector<int>& path) const;
};

#endif  // BINARYTREE_H
