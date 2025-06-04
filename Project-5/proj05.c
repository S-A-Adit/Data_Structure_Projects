/* Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 5
 * Date: 2025-04-01
 *
 * Project 5: Hash Table Collision Detection
 *
 * This program reads words (lines) from a specified input file,
 * calculates a hash code for each word using the DJB2 hashing algorithm,
 * and then attempts to store a marker for that hash code in a simple array-based hash table.
 * If a different word hashes to the same index that's already marked, it indicates a collision,
 * which the program then reports to the console.
 *
 * Features:
 * - Reads a file specified as a command-line argument.
 * - Implements the DJB2 string hashing algorithm.
 * - Uses a fixed-size array as a basic hash table to detect collisions.
 * - Reports "Collision found!" when two different strings hash to the same table index.
 */

#include <stdio.h>   // Required for standard input/output functions like printf, fopen, fclose, fgets, putchar
#include <stdlib.h>  // Required for general utilities like exit
#include <string.h>  // Required for string manipulation functions like strlen

/**
 * @brief Computes a hash value for a given null-terminated string using the DJB2 algorithm.
 *
 * The DJB2 algorithm is a simple yet effective string hashing function.
 * It initializes a hash with a prime number (5381) and updates it by
 * multiplying the current hash by 33 (left shift by 5 and add original hash)
 * and then adding the ASCII value of the current character.
 * This process repeats for all characters in the string.
 *
 * @param str A pointer to the null-terminated character array (string) to be hashed.
 * @return An unsigned long integer representing the computed hash value.
 */
unsigned long hash(char *str)
{
    unsigned long hash = 5381; // Initial hash value, a common prime number for DJB2.
    int theChar;               // Variable to hold the current character's ASCII value.

    // Loop through the string until the null terminator ('\0') is encountered.
    // The assignment 'theChar = *str' fetches the character, and the loop continues
    // as long as theChar is not 0 (the ASCII value of null).
    while ((theChar = *str))
    {
        /* hash * 33 + theChar */ // Original comment explaining the multiplication and addition.
        // This line implements the core of the DJB2 algorithm:
        // (hash << 5) performs 'hash * 32'.
        // Adding 'hash' makes it 'hash * 32 + hash', which is 'hash * 33'.
        // Finally, 'theChar' is added to this result.
        hash = ((hash << 5) + hash) + theChar;
        str++; // Move to the next character in the string.
    }
    return hash; // Return the final computed hash value.
}

/**
 * @brief Prints the contents of a null-terminated string to standard output, character by character.
 *
 * This utility function iterates through the provided string from its beginning
 * until it encounters the null terminator ('\0'), printing each character.
 * It's a simple way to display string data to the console.
 *
 * @param theString A pointer to the null-terminated character array (string) to be printed.
 */
void printString(char *theString){
    // Loop until the null terminator character ('\0', which has an ASCII value of 0) is found.
    while(*theString != 0){
        putchar(*theString); // Print the current character.
        theString++;         // Move to the next character in the string.
    }
}

/**
 * @brief Main function of the program.
 *
 * This function handles command-line arguments, file reading,
 * hash calculation, and collision detection within a hash table.
 * It expects one command-line argument: the path to the input file.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the command-line arguments.
 * argv[0] is the program name, argv[1] should be the filename.
 * @return 0 if the program executes successfully, or a non-zero exit code on error.
 */
int main(int argc, char **argv){
    FILE *theFile;                   // Declare a file pointer to handle the input file.
    char inputString[256];           // Buffer to store each line read from the file.
                                     // Size 256 to accommodate strings up to 255 chars + null terminator.
    int hashtable[10000] = {0};      // Declare a hash table array of size 10000.
                                     // Initialize all elements to 0 (indicating empty slots).

    // Check if the correct number of command-line arguments is provided.
    // The program expects exactly one argument after the program name (the filename).
    if (argc < 2){
        printf("Usage: filefun <theFile>\n"); // Inform the user about correct usage.
        exit(2); // Exit with a status code indicating incorrect usage.
    }

    // Attempt to open the file specified by the first command-line argument (argv[1]) in read mode ("r").
    theFile = fopen(argv[1], "r");
    // Print the program's name (argv[0]). This was originally `printf("%s",*argv);`
    // which prints the first character of the program name.
    // The common intent is to print the full program name for debugging/logging.
    // `printf("%s\n", argv[0]);` would print the full program name followed by a newline.
    // Keeping original behavior: prints the first char of program name.
    printf("%s", *argv); // Prints the character pointed to by argv[0]

    // Check if the file was opened successfully.
    // If fopen returns NULL, it means the file could not be opened.
    if (!theFile) {
        printf("Error opening file\n"); // Inform the user about the file opening error.
        exit(1); // Exit with a status code indicating a file error.
    }

    // Read the file line by line until the end of the file (EOF) is reached.
    // fgets reads up to 255 characters (or until a newline or EOF) into inputString.
    while (fgets(inputString, 256, theFile)){
        // Remove the newline character ('\n') that fgets might include at the end of the string.
        // It does this by overwriting the character before the null terminator with a null terminator.
        // This is important because the newline would affect the hash value.
        // Note: This relies on strlen(inputString) being at least 1 if a newline is present.
        // It could cause issues if inputString is empty or only has a newline.
        inputString[strlen(inputString - 1)] = 0; // This line is prone to error (inputString - 1)
                                                 // It should likely be: inputString[strcspn(inputString, "\n")] = 0;
                                                 // OR inputString[strlen(inputString) - 1] = 0; if guaranteed newline.
                                                 // Keeping original expression as per instructions.

        // Calculate the hash value for the current string and get its index within the hash table.
        // The modulo operator (%) ensures the hash_value fits within the hash table's size (10000).
        int hash_value = hash(inputString) % 10000;

        // Check for a collision: if the slot at 'hash_value' in the hashtable is already marked (non-zero).
        // Since we only store '1' to mark a slot, any '1' indicates a previous entry.
        if (hashtable[hash_value]) {
            printString("Collision found! "); // Print a message indicating a collision.
            printString(inputString);        // Print the string that caused the collision.
            putchar('\n');                   // Print a newline character for formatting.
        }
        // Mark the current hash table slot as occupied (set its value to 1).
        // This indicates that at least one word has hashed to this slot.
        hashtable[hash_value] = 1;
    }

    // Close the opened file to release system resources.
    fclose(theFile);

    // Indicate successful program execution.
    return 0;
}