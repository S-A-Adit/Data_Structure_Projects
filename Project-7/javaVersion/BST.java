package project_7;

import java.util.Scanner;
/**
 * Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 7: Binary Search Tree (BST) Implementation
 * Date: 2025-04-22
 *
 * This program uses a Binary Search Tree (BST) to sort integers.
 * Users enter positive integers (0 to stop). The BST is built,
 * printed in sorted order (inorder), and memory is implicitly cleaned by Java's GC.
 */
public class BST{

    /**
     * Represents a single node in the Binary Search Tree.
     */
    static class TreeNode {
        int value;
        TreeNode left;
        TreeNode right;

        TreeNode(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }

    /**
     * Inserts a value into the BST.
     */
    public static TreeNode insert(TreeNode root, int value) {
        if (root == null) {
            return new TreeNode(value);
        }

        if (value < root.value) {
            root.left = insert(root.left, value);
        } else if (value > root.value) {
            root.right = insert(root.right, value);
        }

        return root;
    }

    /**
     * Performs inorder traversal (Left -> Root -> Right).
     */
    public static void inorder(TreeNode root) {
        if (root == null) {
            return;
        }

        inorder(root.left);
        System.out.print(root.value + " ");
        inorder(root.right);
    }

    /**
     * Frees tree memory — not needed in Java due to garbage collection.
     * This method is provided to mirror the C version structure.
     */
    public static void freeTree(TreeNode root) {
        if (root == null) {
            return;
        }
        freeTree(root.left);
        freeTree(root.right);
        // In Java, no need to explicitly free — GC handles it.
    }

    /**
     * Main method — reads user input and runs BST operations.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        TreeNode root = null;

        System.out.println("Enter positive integers, one per line (0 to stop):");

        int userInput = scanner.nextInt();

        while (userInput != 0) {
            root = insert(root, userInput);
            userInput = scanner.nextInt();
        }

        System.out.println("Sorted Output:");
        inorder(root);
        System.out.println(); // New line after sorted output

        freeTree(root); // Optional in Java

        scanner.close();
    }
}
