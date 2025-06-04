/* Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 5
 * Date: 2025-04-01
 *
 * Hash Table and String Utility Header File
 * This header file declares function prototypes for hashing strings
 * and for printing string content. It's designed to be included in
 * files that utilize these utility functions, excluding the main application logic.
 */

#ifndef HASH_UTILITIES_H // Include guard: Prevents multiple inclusions of this header file
#define HASH_UTILITIES_H // Defines a unique macro to mark this header as included

/**
 * @brief Computes a hash value for a given string.
 *
 * This function takes a null-terminated string as input and
 * calculates an unsigned long hash value. The specific hashing algorithm
 * (e.g., DJB2, SDBM, CRC32, etc.) is implemented in the corresponding .c file.
 * Hash functions are crucial for efficient data storage and retrieval in hash tables.
 *
 * @param str A pointer to the null-terminated character array (string) to be hashed.
 * @return An unsigned long integer representing the computed hash value of the string.
 */
unsigned long hash(char *str);

/**
 * @brief Prints the contents of a null-terminated string to standard output.
 *
 * This utility function iterates through the characters of the provided string
 * and prints each character until a null terminator ('\0') is encountered.
 * It's useful for debugging and displaying string data.
 *
 * @param theString A pointer to the null-terminated character array (string) to be printed.
 */
void printString(char *theString);

#endif // HASH_UTILITIES_H