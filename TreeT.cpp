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
    T data;
    Node* tempPtr;

    tempPtr = subtree;
    if (subtree->left == nullptr && subtree->right == nullptr){
        delete subtree;
    }
    else if (subtree->left == nullptr){
        subtree = subtree->right;
        delete tempPtr;
    }
    else if (subtree->right == nullptr){
        subtree = subtree->left;
        delete tempPtr;
    }
    else{
        GetPredecessor(subtree->left, data);
        subtree->info = data;
        Delete(subtree->left, data);
    }
}

template<class T>
void TreeT<T>::GetPredecessor(TreeT::Node *curr, T &value) {
    while(curr->right != nullptr)
        curr = curr->right;
    value = curr->info;
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

template<class T>
void TreeT<T>::AddR(T value) {

}

template<class T>
bool TreeT<T>::ContainsR(T value) {
    return ContainsHelper(root, value); // if value somewhere under the root
}

template<class T>
bool TreeT<T>::ContainsHelper(Node *subroot, T value) {

    if (subroot == nullptr) {
        return false;
    }

    if(subroot->value == value){
        return true;
    }

    if (value < subroot->value) {
        return ContainsHelper(subroot->left, value); // Look in the left subtree
    }

    if (value < subroot->value) {
        return ContainsHelper(subroot->right, value); // Look in the right subtree
    }
    return false;
}

