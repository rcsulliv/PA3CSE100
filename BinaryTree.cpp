#include "BinaryTree.h"

/**
 * 
 * Implement balanceFactors() correctly
 */
int balanceHelper(BinaryTree::Node * curr,  unordered_map<int, int> * balenceMap);

unordered_map<int,int> BinaryTree::balanceFactors() {
    /* YOUR CODE HERE */
    unordered_map<int, int> balenceMap;
    balanceHelper(root, &balenceMap);   
    return balenceMap;
}

int balanceHelper(BinaryTree::Node * curr,  unordered_map<int, int> * balenceMap){
    if( curr == NULL){
        return 0;
    }
    int leftHeight = balanceHelper(curr->leftChild, balenceMap);
    int rightHeight = balanceHelper(curr->rightChild,  balenceMap);
    int subtreeHeight;
    if( leftHeight>rightHeight){
        subtreeHeight = leftHeight + 1;
    }else if (leftHeight == rightHeight){
        subtreeHeight = leftHeight + 1;
    }else{
        subtreeHeight = rightHeight + 1;
    }
    (*balenceMap)[curr->label] = rightHeight - leftHeight;
    
    return subtreeHeight;
}
