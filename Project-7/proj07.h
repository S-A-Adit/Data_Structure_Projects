/* Adit Syed Afnan
Data Structures CSCI-230
Project 8
04/22/2025 
Header File contains all the functions.
*/

// All functions are recursive
typedef struct treeNode
{
    int value;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;
void inorder(treeNode* root);
void freeTree(treeNode* root);
