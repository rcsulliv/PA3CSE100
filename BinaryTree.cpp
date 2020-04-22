#include "BinaryTree.h"

/**
 * Implement balanceFactors() correctly
 */
int balanceHelper(BinaryTree::Node * curr, int * nodeNum, unordered_map<int, int> * balenceMap);

unordered_map<int,int> BinaryTree::balanceFactors() {
    /* YOUR CODE HERE */
    unordered_map<int, int> balenceMap;
    int nodeNum = 0;
    balanceHelper(root, &nodeNum, &balenceMap);   
    return balenceMap;
}

int balanceHelper(BinaryTree::Node * curr, int * nodeNum, unordered_map<int, int> * balenceMap){
    if( curr == NULL){
        return 0;
    }
    int leftHeight = balanceHelper(curr->leftChild, nodeNum,balenceMap);
    int rightHeight = balanceHelper(curr->rightChild, nodeNum, balenceMap);
    int subtreeHeight;
    if( leftHeight>rightHeight){
        subtreeHeight = leftHeight + 1;
    }else if (leftHeight == rightHeight){
        subtreeHeight = leftHeight + 1;
    }else{
        subtreeHeight = rightHeight + 1;
    }
    
    (*balenceMap)[*nodeNum] = rightHeight - leftHeight;
    (*nodeNum)++;
    return subtreeHeight;
}
