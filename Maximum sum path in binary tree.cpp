#include <iostream>
#include <algorithm> // For std::max
#include <climits>   // For INT_MIN and INT_MAX
using namespace std;

// Structure of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a new node into the binary tree
void insert(Node*& root, int value) {
    if (root == NULL) {
        root = new Node(value);
    } else if (value < root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

// Function to calculate the maximum path sum
int maxPathSumUtil(Node* node, int& maxSum) {
    if (node == NULL) return 0;

    // Recursively get the maximum sum of left and right subtrees
    int leftSum = max(0, maxPathSumUtil(node->left, maxSum));   // Ignore negative sums
    int rightSum = max(0, maxPathSumUtil(node->right, maxSum)); // Ignore negative sums

    // Update the maximum sum if needed
    maxSum = max(maxSum, leftSum + rightSum + node->data);

    // Return the maximum sum of the path that can be extended to the parent
    return max(leftSum, rightSum) + node->data;
}

// Function to find the maximum path sum in the binary tree
int maxPathSum(Node* root) {
    int maxSum = INT_MIN; // Initialize to minimum integer value
    maxPathSumUtil(root, maxSum);
    return maxSum;
}

// Function to delete the entire binary tree
void deleteTree(Node* node) {
    if (node == NULL) return; // Base case: if the node is null, return

    deleteTree(node->left);  // Delete left subtree
    deleteTree(node->right); // Delete right subtree
    delete node;             // Delete current node
}

// Driver code
int main() {
    Node* root = NULL; // Initialize the root of the tree
    int number;

    cout << "Enter numbers to insert into the binary tree (type -1 to stop):" << endl;

    while (true) {
        cin >> number;
        if (number == -1) break; // Exit condition for input
        insert(root, number);     // Insert the number into the binary tree
    }

    int result = maxPathSum(root); // Calculate maximum path sum
    cout << "Maximum Path Sum of the binary tree is: " << result << endl;

    // Clean up memory
    deleteTree(root);

    return 0;
}