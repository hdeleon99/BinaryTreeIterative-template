#include "TreeT.h"
template<class T>
TreeT<T>::TreeT() {
    numNodes = 0;
    root = nullptr;
}

template<class T>
TreeT<T>::~TreeT() {

}

template<class T>
TreeT &TreeT<T>::operator=(const TreeT &otherTree) {
    return;
}

template<class T>
void TreeT<T>::Add(T value) {
    Node* curr = root;
    Node* parent = nullptr;
    while (curr != nullptr) {

        if(curr->value == value) {
            return;
        }

        parent = curr; // Remember parent
        if (value < curr->value) { // value less than current value

            curr = curr->left; // travel left
        }
        else {

            curr = curr->right; // travel right
        }

    }

    Node* newNode = new Node;
    newNode->value = value;
    numNodes++;

    if (root == nullptr) {
        root = newNode;
    }
    if (value < parent->value) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }
}

template<class T>
void TreeT<T>::Remove(T value) {

}

template<class T>
bool TreeT<T>::Contains(T value) {

    Node* curr = root;

    while (curr != nullptr) {

        if(curr->value == value) {
            return true;
        }
        else if (value < curr->value) { // value less than current value
            curr = curr->left; // travel left
        }
        else {
            curr = curr->right; // travel right
        }

    }
    return false;
}

template<class T>
int TreeT<T>::Size() {
    return 0;
}

template<class T>
void TreeT<T>::ResetIterator(Order traverseOrder) {

}

template<class T>
T TreeT<T>::GetNextItem() {
    return nullptr;
}

template<class T>
void TreeT<T>::DestroyTree(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::RemoveHelper(TreeT::Node *&subtree, T value) {

}

template<class T>
void TreeT<T>::DeleteNode(TreeT::Node *&subtree) {

}

template<class T>
void TreeT<T>::GetPredecessor(TreeT::Node *curr, T &value) {

}

template<class T>
void TreeT<T>::CopyHelper(TreeT::Node *&thisTree, TreeT::Node *otherTree) {

}

template<class T>
void TreeT<T>::PlacePreOrder(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::PlacePostOrder(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::PlaceInOrder(TreeT::Node *node) {

}

