/* Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 7
 * Date: 2025-04-10
 *
 * Hash Table Entry and Utility Header File
 *
 * This header file defines the structure for an entry in a hash table,
 * specifically designed for handling string data with chaining for collision resolution.
 * It also declares utility functions for string hashing and printing.
 * This file is intended for inclusion in modules that implement or use these functionalities,
 * excluding the main application logic.
 */

#ifndef HASH_TABLE_UTILITIES_H // Include guard: Prevents multiple inclusions of this header file
#define HASH_TABLE_UTILITIES_H // Defines a unique macro to mark this header as included

/**
 * @struct hashEntry
 * @brief Represents a single entry (node) within a hash table's linked list.
 *
 * This structure is used in hash tables that employ chaining to resolve collisions.
 * Each entry stores a pointer to a string (its key) and a pointer to the next
 * hashEntry in the same linked list (bucket).
 */
typedef struct hashEntry
{
    char *text;           /**< Pointer to the null-terminated string stored in this entry. This is typically the key. */
    struct hashEntry *next; /**< Pointer to the next hashEntry in the linked list for this bucket. NULL if this is the last entry. */
} hashEntry; // 'hashEntry' is an alias for 'struct hashEntry'

/**
 * @brief Computes a hash value for a given null-terminated string.
 *
 * This function takes a string as input and calculates an unsigned long hash value.
 * The specific hashing algorithm used (e.g., DJB2, SDBM) determines how the hash
 * is generated. Hash functions are fundamental for efficient data placement
 * and retrieval within hash tables.
 *
 * @param str A pointer to the null-terminated character array (string) to be hashed.
 * @return An unsigned long integer representing the computed hash value of the string.
 */
unsigned long hash(char *str);

/**
 * @brief Prints the contents of a null-terminated string to standard output.
 *
 * This utility function iterates through the characters of the provided string
 * and prints each character until it encounters a null terminator ('\0').
 * It's a convenient function for displaying string data to the console,
 * often used for debugging or outputting results.
 *
 * @param theString A pointer to the null-terminated character array (string) to be printed.
 */
void printString(char *theString);

#endif // HASH_TABLE_UTILITIES_H