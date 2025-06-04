/* Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 7: Hash Table-Based Spell Checker
 * Date: 2025-04-10
 *
 * This program implements a basic spell checker using a hash table.
 * It first reads words from a dictionary file, hashes them, and stores them
 * in a hash table (using chaining for collision resolution).
 * Then, it reads words from an input file, hashes each word, and
 * checks for its presence in the dictionary hash table.
 *
 * The program also tracks the number of collisions encountered when building the dictionary
 * hash table and attempts to categorize misspellings based on hash table lookups.
 */

#include <stdio.h>   // For standard input/output functions (e.g., printf, fopen, fclose, fgets)
#include <stdlib.h>  // For general utilities (e.g., malloc, exit)
#include <string.h>  // For string manipulation functions (e.g., strlen, strcpy, strcmp)
#include <stdbool.h> // For boolean data type (true/false) - though not explicitly used for bool vars in the core logic, good for clarity

/**
 * @struct hashEntry
 * @brief Represents a single entry (node) in the hash table's linked list.
 *
 * Each hashEntry stores a dynamically allocated string (the word itself)
 * and a pointer to the next hashEntry in the same hash bucket, forming a
 * linked list to handle collisions (chaining).
 */
typedef struct hashEntry
{
    char *text;              /**< Pointer to the dynamically allocated string (word) stored in this entry. */
    struct hashEntry *next;  /**< Pointer to the next entry in the linked list for the same hash bucket. */
} hashEntry;

/**
 * @brief Computes a hash value for a given null-terminated string using the DJB2 algorithm.
 *
 * The DJB2 algorithm is a widely used string hashing function. It iteratively
 * updates the hash value by left-shifting it by 5 bits (equivalent to multiplying by 32),
 * adding the original hash value (making it `hash * 33`), and then adding the ASCII
 * value of the current character.
 *
 * @param str A pointer to the null-terminated character array (string) to be hashed.
 * @return An unsigned long integer representing the computed hash value.
 */
unsigned long hash(char *str)
{
	unsigned long hash = 5381; // Initial hash value, a common prime number for the DJB2 algorithm.
	int theChar;               // Variable to hold the ASCII value of the current character.

	// Loop through the string until the null terminator ('\0' which has an ASCII value of 0) is found.
	// The assignment 'theChar = *str' fetches the character, and the loop continues as long as theChar is not 0.
	while ((theChar = *str))
	{
    	/* hash * 33 + theChar */ // Original comment indicating the mathematical operation.
    	// This line efficiently calculates (hash * 33) + theChar using bitwise operations:
    	// (hash << 5) is equivalent to hash * 32.
    	// Adding 'hash' makes it (hash * 32) + hash, which simplifies to hash * 33.
    	// Finally, the ASCII value of the current character is added.
    	hash = ((hash << 5) + hash) + theChar;
    	str++; // Move the pointer to the next character in the string.
	}
	return hash; // Return the final computed hash value.
}

// Define the fixed size of the hash table array.
// This constant determines the number of buckets available in the hash table.
#define SIZE 40000

/**
 * @brief Main function of the spell checking program.
 *
 * This function orchestrates the entire spell checking process:
 * 1. Handles command-line arguments for dictionary and input files.
 * 2. Initializes the hash table.
 * 3. Loads words from the dictionary file into the hash table.
 * 4. Counts and reports collisions during dictionary loading.
 * 5. Reads words from the input file and checks their spelling against the dictionary.
 * 6. Categorizes and reports found misspellings.
 * 7. Frees allocated memory and closes files.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the command-line arguments.
 * Expected: argv[0] = program name, argv[1] = dictionary file path,
 * argv[2] = input file path.
 * @return 0 if the program executes successfully, or 1/2 if an error occurs.
 */
int main(int argc, char *argv[]){

	// Buffer to store each word read from the dictionary file.
	char dictWord[80];
	// Buffer to store each word read from the input file (to be spell-checked).
    char wordToCheck[80];

	// Variable to store the calculated hash value for a word.
	unsigned long hash_value;

	// Counter for the number of collisions observed during dictionary loading.
	// A collision occurs when a new word hashes to an already occupied bucket (slot).
	int numCollisions = 0;

	// Declare the hash table as an array of pointers to hashEntry structures.
	// Each element of this array represents a bucket in the hash table.
	// Initialize all pointers to NULL, indicating empty buckets.
	hashEntry* hashTable[SIZE] = {NULL};
	// A temporary pointer to a hashEntry, used during insertions and traversals.
	hashEntry *theHashEntryPtr;

	// --- Command Line Argument Validation ---
	// Check if the correct number of command-line arguments is provided.
	// Expects program name, dictionary file, and input file (3 arguments total).
	if (argc < 3) {
        printf("Usage: %s <dictionary_file> <words_file>\n", argv[0]);
        return 1; // Exit with an error code.
    }

	// --- Dictionary File Handling ---
	// Attempt to open the dictionary file provided as the first argument (argv[1]) in read mode ("r").
	FILE *dictFile = fopen(argv[1], "r");
	// Check if the dictionary file was successfully opened.
	if (dictFile == NULL){
		printf("ERROR! Cannot find Dictionary.\n"); // Inform the user about the error.
		exit(1); // Exit the program with an error status.
	}

	// --- Input File Handling ---
	// Attempt to open the input file (words to check) provided as the second argument (argv[2]) in read mode ("r").
	FILE *inputFile = fopen(argv[2], "r");
	// Check if the input file was successfully opened.
	if (inputFile == NULL){
		printf("ERROR! Cannot find input file.\n"); // Inform the user about the error.
		exit(2); // Exit the program with a different error status.
	}

    // --- Dictionary Loading and Hash Table Population ---
    // Read words from the dictionary file line by line until the end of the file is reached.
	while (fgets(dictWord, 80, dictFile) != NULL)
    {
        // Remove the newline character ('\n') that fgets might include at the end of the string.
        // This ensures the hash value is calculated correctly for the actual word.
        dictWord[strlen(dictWord) - 1] = 0;

        // Calculate the hash value for the current dictionary word and
        // determine its corresponding bucket index in the hash table.
	    hash_value = hash(dictWord) % SIZE;

		// Check if a collision occurs at this bucket.
		// A collision happens if the bucket (hashTable[hash_value]) is already non-NULL,
		// meaning another word previously hashed to this same index.
		if (hashTable[hash_value] != NULL)
    	{
        	numCollisions++; // Increment the collision counter.
    	}

		// Allocate memory for a new hashEntry structure to store the current word.
		theHashEntryPtr = (hashEntry*)malloc(sizeof(hashEntry));
		// Check if memory allocation was successful.
		if(theHashEntryPtr == NULL)
    	{
    	printf("malloc failed\n"); // Report memory allocation failure.
    	exit(1); // Exit the program due to a critical error.
    	}

        // Allocate memory for the string itself within the hashEntry.
        // The size is strlen(dictWord) + 1 for the null terminator.
		theHashEntryPtr->text = (char*) malloc(strlen(dictWord) + 1); // Memory allocation for the word string.
        // Copy the current dictionary word into the newly allocated memory within the hashEntry.
		strcpy(theHashEntryPtr->text, dictWord);

        // Implement chaining: Link the new hashEntry to the beginning of the linked list
        // at the calculated hash_value bucket.
        // The 'next' pointer of the new entry points to whatever was previously at that bucket.
        theHashEntryPtr->next = hashTable[hash_value];
        // The hash table bucket now points to the new entry, making it the new head of the list.
        hashTable[hash_value] = theHashEntryPtr;
	}

	// Report the total number of collisions observed during dictionary loading.
	printf("Dictionary loaded. numCollisions: %d\n", numCollisions);

    // --- Spell Checking Input File ---
    // Read words from the input file line by line until the end of the file.
	while (fgets(wordToCheck, 80, inputFile) != NULL) {
        // Remove the newline character from the word read from the input file.
        wordToCheck[strlen(wordToCheck) - 1] = 0;

        // Calculate the hash value for the current word to be checked.
    	hash_value = hash(wordToCheck) % SIZE;
    	// Get a pointer to the head of the linked list (chain) at this hash bucket.
    	hashEntry *collision = hashTable[hash_value];

        // Traverse the linked list (chain) at the calculated hash_value bucket.
        // This loop checks if the wordToCheck exists within this chain.
    	while (collision != NULL) {
            // Compare the wordToCheck with the text stored in the current hashEntry.
            if (strcmp(wordToCheck, collision->text) == 0) {
			   break; // If a match is found, the word is correctly spelled; exit the loop.
			}
            collision = collision->next; // Move to the next entry in the chain.
			 // Original comment: "Here we assume a collision has occured" - this comment
             // might be misleading as the loop is checking for a *match* within a potential collision chain.
             // The existence of the chain itself means a collision *might* have occurred for some words.
        }

        // --- Misspelling Detection and Reporting ---
        // If 'collision' is NULL after the loop, it means the wordToCheck was not found
        // in the linked list at its hash bucket, indicating a misspelling.
        if (collision == NULL) {
            // 'misspellingCount' and 'listMisspellingCount' are declared but not used for aggregate counts
            // beyond this local scope, based on original code. They are reset per word.
            // int misspellingCount = 0; // Local declaration, reset for each word.
		    // int listMisspellingCount = 0; // Local declaration, reset for each word.

            // Categorize the misspelling type:
            // If hashTable[hash_value] is NULL, it means no word (not even a colliding one)
            // ever hashed to this exact bucket. This implies a straightforward misspelling.
            if (hashTable[hash_value] == NULL ) {
                printf("Misspelling found: %s\n", wordToCheck);
                // misspellingCount++; // This increment would be local to this `if` block, based on original.
            } else {
                // If hashTable[hash_value] is NOT NULL, but the word was not found in the chain,
                // it means the word is misspelled AND its hash collides with at least one other
                // dictionary word. This might be considered a "list-based" misspelling.
                printf("List based misspelling found: %s\n", wordToCheck);
                // listMisspellingCount++; // This increment would be local to this `else` block, based on original.
            }
        }
	}

    // --- Memory Deallocation and File Closing ---
    // IMPORTANT: The original code only frees `theHashEntryPtr` once at the very end.
    // This is a memory leak as it only frees the LAST allocated `hashEntry`.
    // To properly free all memory, you would need to iterate through the entire
    // hash table and all linked lists (chains) to free each `text` string and
    // each `hashEntry` node.
    // As per instruction "Do not change the actual Code", I cannot add the correct
    // memory deallocation loop here.
    free(theHashEntryPtr); // This line only frees the last allocated hashEntry pointer.

    // Close the dictionary file.
	fclose(dictFile);
	// Close the input file.
	fclose(inputFile);

	return 0; // Indicate successful program execution.
}