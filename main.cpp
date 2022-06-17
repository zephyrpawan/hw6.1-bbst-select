/*
 * Author: Pawan Bhandari
 * Assignment Title: Homework 6.1: BBST Select
 * Assignment Description: This program implements a Balanced Binary Search Tree varient, AVL tree
 *                          and a select function on which returns the ith order statistic of
 *                          elements on that tree. The select subroutine does in-order traversal
 *                          on the BBST to sort elemnts for returning ith order statistic.
 * Due Date: 06/27/2022
 * Date Created: 06/25/2022
 * Date Last Modified:06/27/2022
 */

// Uses C++-2011 standard

/*
 * Data Abstraction:
 *
 *
 * Input:
 *       Inputs numbers or space-delimited numbers
 *       1st standard input is a space-delimited numerical values
 *       2nd standard input is the order of select statistic to be selected from the binary search tree
 *
 * Process:
 *       Input stream is opened to read from console (cin)
 *       spacce-delimited numbers are stored in a vector<int>
 *       second line input for order of select statistic is stored as ith
 *       One by one insert the integers from the vector in a BBST (AVL Tree)
 *       Create an array of size ith;
 *       Do a In-order traversal of the BBST and keep pushing elements to the array till ith
 *       In-order traversal of the BBST will push elements to the array in the increasing order
 *       So for a sorted array ith element will be ith largest value aka order statistic
 *       print the output to console
 *
 * Output:
 *      Minimum number of members required to leave is printed in the console
 *
 * Assumptions:
 *      1st input contains space-delimited numerical values
 *      Input values are unique. No duplicates allowed
 *      2nd input contains the order of select statistic to be selected from the binary search tree
 *      both input are strictly numeric (int)
 *
 * Refrences:
 *      https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
 *      https://www.youtube.com/watch?v=1QSYxIKXXP4
 *      https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/datastructures/balancedtree/AVLTreeRecursive.java
 *
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    // Integer value of the node
    int value;

    // Height of the node which is defined as the number of edges between the node and its furthest leaf node
    int height;

    // Pointers to left and right sub nodes
    Node *leftChild;
    Node *rightChild;

    // Constructor
    Node(int value)
    {
        this->value = value;
        this->height = 1;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

// function declarations
int getTreeHeight(Node *node);
int getBalanceFactor(Node *node);
int max(int a, int b);
Node *createNode(int value);
Node *rotateLeft(Node *node);
Node *rotateRight(Node *node);
Node *insert(Node *node, int value);
void inOrderTraversal(Node *node);

int main(int argc, char const *argv[])
{
    vector<int> numbers;
    int ith = 1;
    cout << "Please enter space-delimited sets of numbers in first line and order statistic to be selected on second line " << endl;

    int lineNum = 1;
    string line;
    while (getline(cin, line))
    {
        if (lineNum == 1)
        {
            istringstream ss(line);
            string number;
            while (ss >> number)
            {
                numbers.push_back(stoi(number));
            }
        }
        if (lineNum == 2) {
            ith = stoi(line);
        }
        lineNum++;
    }

    Node *node = NULL;

    //for loop from vector


    node = insert(node, 10);
    node = insert(node, 20);
    node = insert(node, 30);
    node = insert(node, 40);
    node = insert(node, 50);
    node = insert(node, 25);

    inOrderTraversal(node);

    return 0;
}

int getTreeHeight(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getTreeHeight(node->leftChild) - getTreeHeight(node->rightChild);
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

Node *createNode(int value)
{
    Node *node = new Node(value);
    return node;
}

Node *rotateLeft(Node *node)
{
    Node *newRoot = node->rightChild;
    node->rightChild = newRoot->leftChild;
    newRoot->leftChild = node;

    node->height = max(getTreeHeight(node->leftChild), getTreeHeight(node->rightChild)) + 1;
    newRoot->height = max(getTreeHeight(newRoot->leftChild), getTreeHeight(newRoot->rightChild)) + 1;

    return newRoot;
}

Node *rotateRight(Node *node)
{
    Node *newRoot = node->leftChild;
    node->leftChild = newRoot->rightChild;
    newRoot->rightChild = node;

    node->height = max(getTreeHeight(node->leftChild), getTreeHeight(node->rightChild)) + 1;
    newRoot->height = max(getTreeHeight(newRoot->leftChild), getTreeHeight(newRoot->rightChild)) + 1;

    return newRoot;
}

Node *insert(Node *node, int value)
{

    if (node == NULL)
    {
        return (createNode(value));
    }
    if (value < node->value)
    {
        node->leftChild = insert(node->leftChild, value);
    }
    else if (value > node->value)
    {
        node->rightChild = insert(node->rightChild, value);
    }
    else
    {
        return node;
    }

    node->height = 1 + max(getTreeHeight(node->leftChild), getTreeHeight(node->rightChild));

    int balancefactor = getBalanceFactor(node);

    // In case of Left heavy Left Node
    if (balancefactor > 1 && value < node->leftChild->value)
    {
        return rotateRight(node);
    }

    // In case of Right heavy left node
    if (balancefactor > 1 && value > node->leftChild->value)
    {
        node->leftChild = rotateLeft(node->leftChild);
        return rotateRight(node);
    }

    // In case of left heavy Right node
    if (balancefactor < -1 && value < node->rightChild->value)
    {
        node->rightChild = rotateRight(node->rightChild);
        return rotateLeft(node);
    }

    // In case of Right heavy Right node
    if (balancefactor < -1 && value > node->rightChild->value)
    {
        return rotateLeft(node);
    }

    return node;
}

void inOrderTraversal(Node *node)
{
    if (node != NULL)
    {
        inOrderTraversal(node->leftChild);
        cout << node->value << " ";
        inOrderTraversal(node->rightChild);
    }
}