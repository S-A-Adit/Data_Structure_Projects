/* Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 7: Binary Search Tree (BST) Implementation
 * Date: 2025-04-22
 *
 * This program demonstrates the use of a Binary Search Tree (BST)
 * to sort a list of integers provided by the user.
 * It reads positive integers, inserts them into the BST,
 * then prints them in sorted order using an inorder traversal.
 * Finally, it properly deallocates all memory used by the tree.
 *
 * Key Concepts:
 * - Binary Search Tree (BST): Values smaller than the parent go to the left subtree,
 * larger values go to the right subtree.
 * - Recursion: Used for insertion, traversal, and memory deallocation.
 * - Inorder Traversal: Visits nodes in ascending order (Left -> Root -> Right).
 */

#include <stdio.h>  // Required for standard input/output functions like printf, scanf
#include <stdlib.h> // Required for memory allocation functions like malloc, free

/**
 * @struct treeNode
 * @brief Represents a single node within the Binary Search Tree.
 *
 * Each node holds an integer value and has two pointers:
 * one for its left child (smaller values) and one for its right child (larger values).
 */
typedef struct treeNode
{
    int value;          /**< The integer data value stored in this node. */
    struct treeNode *left;  /**< Pointer to the left child node. NULL if no left child. */
    struct treeNode *right; /**< Pointer to the right child node. NULL if no right child. */
} treeNode; // 'treeNode' is an alias for 'struct treeNode'

/**
 * @brief Inserts a new integer value into the Binary Search Tree.
 *
 * This function recursively finds the correct position for the new value
 * based on BST properties (smaller values go to the left, larger values to the right).
 * If the value already exists in the tree, it's typically ignored (no duplicates are added
 * in this specific implementation if values are equal to root's value).
 *
 * @param root A pointer to the current root of the (sub)tree.
 * @param value The integer value to be inserted into the tree.
 * @return A pointer to the root of the modified (sub)tree.
 */
treeNode* insert(treeNode* root, int value)
{
    // Base case: If the current root is NULL, we've found the insertion point.
    // Create a new node, initialize its fields, and return it.
    if (root == NULL)
    {
        treeNode* newNode = (treeNode*)malloc(sizeof(treeNode)); // Allocate memory for the new node.
        newNode->value = value;      // Assign the given value to the new node.
        newNode->left =  NULL;      // Initialize left child pointer to NULL.
        newNode->right = NULL;     // Initialize right child pointer to NULL.
        return newNode;              // Return the newly created node as the root of this subtree.
    }

    // Recursive step: Compare the value with the current root's value.
    if (value < root->value) {
        // If the value is smaller, insert it into the left subtree.
        // Update the current root's left pointer to the result of the recursive call.
        root->left = insert(root->left, value);
    }
    else if (value > root->value) { // Note: If value == root->value, it is not inserted again based on this logic.
        // If the value is larger, insert it into the right subtree.
        // Update the current root's right pointer to the result of the recursive call.
        root->right = insert(root->right, value);
    }

    // Return the current root (unmodified if value was equal, or updated if a child was inserted).
    return root;
}

/**
 * @brief Performs an inorder traversal of the Binary Search Tree and prints node values.
 *
 * An inorder traversal visits nodes in the order: Left Subtree -> Root -> Right Subtree.
 * For a BST, this results in printing the node values in ascending (sorted) order.
 *
 * @param root A pointer to the current root of the (sub)tree to traverse.
 */
void inorder(treeNode* root){
    // Base case: If the current root is NULL, there's nothing to traverse; simply return.
    if (root == NULL)
        return;

    inorder(root->left);     // Recursively traverse the left subtree.

    printf("%d ", root->value); // Print the value of the current root node.

    inorder(root->right);    // Recursively traverse the right subtree.
}

/**
 * @brief Frees all dynamically allocated memory used by the Binary Search Tree.
 *
 * This function performs a postorder traversal (Left -> Right -> Root) to
 * ensure that child nodes are freed before their parent. This prevents memory leaks.
 * After this function completes, the entire tree structure is deallocated.
 *
 * @param root A pointer to the current root of the (sub)tree to free.
 */
void freeTree(treeNode* root){
    // Base case: If the current root is NULL, there's no node to free; simply return.
    if (root == NULL)
        return;

    freeTree(root->left);  // Recursively free the left subtree.
    freeTree(root->right); // Recursively free the right subtree.
    free(root);            // Free the memory allocated for the current root node itself.
}

/**
 * @brief Main function of the Binary Search Tree sorting program.
 *
 * This function serves as the entry point of the program.
 * It prompts the user for integers, builds the BST, prints the sorted output,
 * and ensures proper memory cleanup.
 *
 * @param void No command-line arguments are expected for this program.
 * @return 0 if the program executes successfully.
 */
int main(void){

    int user_input;          // Variable to store the integer entered by the user.
    treeNode* root = NULL;   // Initialize the root of the BST to NULL (an empty tree).

    printf("Enter positive integers, one per line (0 to stop):\n");

    // Read the first integer from the user.
    scanf("%d", &user_input);

    // Loop to continuously read integers and insert them into the BST
    // until the user enters '0'.
    do
    {
      // Insert the current user_input into the tree.
      // The 'root' pointer might be updated if the tree was initially empty.
      root = insert(root, user_input);
      // Read the next integer from the user for the next iteration.
      scanf("%d", &user_input);
    } while (user_input != 0); // Continue as long as the input is not 0.

    printf("Sorted Output:\n");
    // Perform an inorder traversal to print the elements in sorted order.
    inorder(root);
    printf("\n"); // Add a newline after the sorted output for cleaner presentation.

    // Free all dynamically allocated memory used by the tree to prevent memory leaks.
    freeTree(root);
    // At the end, the `root` pointer itself is not explicitly set to NULL here,
    // but the memory it pointed to is freed. In C, it's good practice to set
    // freed pointers to NULL to avoid dangling pointers, but this is a
    // demonstration of the `freeTree` function's effect.

    return 0; // Indicate successful program execution.
}