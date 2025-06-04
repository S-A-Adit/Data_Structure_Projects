/* Adit Syed Afnan
Data Structures CSCI-230
Project 8
04/22/2025 
Here is the main. The program uses left to store the smaller values and right to store the larger values to sort the list of integers.
At the end the left and right and root is freed. So it ends in NULL.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int value;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode* insert(treeNode* root, int value)
{
    if (root == NULL)
    {
        treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode->value = value;
        newNode->left =  NULL;
        newNode->right = NULL;
        return newNode;
    }


    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);


    return root;
}


void inorder(treeNode* root){

    if (root == NULL)
        return;

    inorder(root->left);

    printf("%d ", root->value);

    inorder(root->right);

}

void freeTree(treeNode* root){
    if (root == NULL)
        return;
   
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void){

int user_input;
treeNode* node = NULL;

printf("Enter positive integers, one per line (0 to stop):\n");

(scanf("%d", &user_input));


do
{
  node = insert(node, user_input);
  (scanf("%d", &user_input));
}while (user_input!= 0);





printf("Sorted Output:\n");
inorder(node);
freeTree(node);
return 0;

}