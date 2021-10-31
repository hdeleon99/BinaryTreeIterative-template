#include "TreeT.h"
template<class T>
TreeT<T>::TreeT() {
    numNodes = 0;
    root = nullptr;
}

template<class T>
TreeT<T>::~TreeT() {
    DestroyTree(root);
}

template<class T>
TreeT<T>& TreeT<T>::operator=(const TreeT &otherTree){

    if(this != &otherTree){
        copyOther((TreeT<int> &) (TreeT<int> &) otherTree);
    }
    return *this;
}

template<class T>
TreeT<T>::TreeT(const TreeT &otherTree) {
    copyOther(otherTree);

}


template<class T>
void TreeT<T>::Add(T value) {
    Node* curr = root;
    Node* parent = nullptr;


    while (curr != nullptr) {

        if(curr->value == value) {
            return;
        }

        parent = curr; // before we travel, remember who the parent is

        if (value < curr->value) { // value less than current value
            curr = curr->left; // travel left
        }
        else {
            curr = curr->right; // travel right
        }

    }

    // once I hit nullptr
    Node* newNode = new Node;
    newNode->value = value;
    numNodes++;

    if(root == nullptr){
        root = newNode;
    }
    else if(value < parent->value){
        parent->left = newNode;
    }
    else{
        parent->right = newNode;
    }
}



template<class T>
bool TreeT<T>::Contains(T value) {

    Node* curr = root;

    while (curr != nullptr){

        if(curr->value == value){ // if we find the value
            return true;
        }
        else if(value < curr->value){ // if curr is less than the value
            curr = curr->left; // move to the left
        }
        else if(value > curr->value){
            curr = curr->right; // move to the right
        }
    }

    return false;
}

template<class T>
int TreeT<T>::Size() {
    return 0;
}





template<class T>
void TreeT<T>::DestroyTree(TreeT::Node *node) {
    if(node == nullptr)
        return;

    DestroyTree(node->left);

    DestroyTree(node->right);

    delete node;
}

template<class T>
void TreeT<T>::RemoveHelper(TreeT::Node *&subtree, T value) {
    if (subtree == nullptr){
        return;
    }
    else if (subtree->value == value){
        DeleteNode(subtree);
    }
    else if (value < subtree->value){
        RemoveHelper(subtree->left, value);
    }
    else{
        RemoveHelper(subtree->right, value);
    }
}

template<class T>
void TreeT<T>::Remove(T value) {
    RemoveHelper(root, value);


}

template<class T>
void TreeT<T>::DeleteNode(TreeT::Node *&subtree) {
    T data;
    Node* tempPtr;

    tempPtr = subtree;
    if (subtree->left == nullptr && subtree->right == nullptr){
        delete subtree;
        numNodes--;
    }
    else if (subtree->left == nullptr){
        subtree = subtree->right;
        delete tempPtr;
        numNodes--;
    }
    else if (subtree->right == nullptr){
        subtree = subtree->left;
        delete tempPtr;
        numNodes--;
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
T TreeT<T>::GetNextItem() {
    T item = iterQue.front();
    iterQue.pop();
    return item;
}

template<class T>
void TreeT<T>::ResetIterator(Order traverseOrder) {
    if (traverseOrder == IN_ORDER){
        PlaceInOrder(root);
    }
    else if (traverseOrder == PRE_ORDER) {
        PlacePreOrder(root);
    }
    else if (traverseOrder == POST_ORDER){
        PlacePostOrder(root);
    }
}

template<class T>
void TreeT<T>::PlacePreOrder(TreeT::Node *node) {
    if (node == nullptr){
        return;
    }
    iterQue.push(node->value);
    PlaceInOrder(node->left);
    PlaceInOrder(node->right);
}

template<class T>
void TreeT<T>::PlacePostOrder(TreeT::Node *node) {
    if (node == nullptr){
        return;
    }

    PlaceInOrder(node->left);
    PlaceInOrder(node->right);
    iterQue.push(node->value);
}

template<class T>
void TreeT<T>::PlaceInOrder(TreeT::Node *node) {
    if (node == nullptr){
        return;
    }

    PlaceInOrder(node->left);
    iterQue.push(node->value); // Remember values in order
    PlaceInOrder(node->right);
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

template<class T>
void TreeT<T>::CopyHelper(TreeT::Node *&thisTree, TreeT::Node *otherTree) {
    if (otherTree == nullptr){
        thisTree = nullptr;
        return;
    }

    thisTree = new Node;
    thisTree->value = otherTree->value;
    CopyHelper(thisTree->left, otherTree->left);
    CopyHelper(thisTree->right, otherTree->right);
}

template<class T>
void TreeT<T>::copyOther(TreeT &otherTree) {
    // operator = function
    // copy function

    CopyHelper(this->root, otherTree.root); // copies tree structure

    // copy over private variables
    this->numNodes = otherTree.numNodes;
    this->iterQue = otherTree.iterQue;
}


