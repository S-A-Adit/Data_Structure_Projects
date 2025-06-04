/* Adit Syed Afnan
 * Data Structures CSCi-230
 * Project 7: Binary Tree Operations
 * Date: 2025-04-22
 *
 * This header file declares the fundamental structure for a binary tree node
 * and provides prototypes for essential recursive functions to operate on the tree.
 * All functions listed here are designed to be implemented recursively.
 */

#ifndef BINARY_TREE_H // Include guard: Prevents multiple inclusions of this header file
#define BINARY_TREE_H // Defines a unique macro to indicate that this header has been included

/**
 * @struct treeNode
 * @brief Represents a single node in a binary tree.
 *
 * Each `treeNode` contains an integer `value` and two pointers,
 * `left` and `right`, which point to its child nodes.
 * These pointers are `NULL` if a child does not exist.
 */
typedef struct treeNode
{
    int value;          /**< The integer data value stored within this node. */
    struct treeNode *left;  /**< Pointer to the left child node. NULL if no left child. */
    struct treeNode *right; /**< Pointer to the right child node. NULL if no right child. */
} treeNode; // 'treeNode' is an alias for 'struct treeNode'

/**
 * @brief Performs an in-order traversal of the binary tree.
 *
 * This recursive function traverses the tree by visiting the left subtree,
 * then processing the current node (e.g., printing its value), and finally
 * visiting the right subtree. This typically results in sorted output for a Binary Search Tree.
 *
 * @param root A pointer to the root node of the (sub)tree to be traversed.
 * If the root is NULL, the function does nothing.
 */
void inorder(treeNode* root);

/**
 * @brief Frees all dynamically allocated memory associated with the binary tree.
 *
 * This recursive function deallocates memory for each node in the tree.
 * It typically performs a post-order traversal (freeing children before the parent)
 * to ensure all memory is properly released, preventing memory leaks.
 *
 * @param root A pointer to the root node of the (sub)tree to be freed.
 * If the root is NULL, the function does nothing.
 */
void freeTree(treeNode* root);

#endif // BINARY_TREE_H