/* Adit Syed Afnan
Data Structures CSCI-230
Project 7
04/10/2025 (current date)
This is where the code is. Contains the main. The files are read. Dictionary is hashed. Input file is hashed to compare.
Collsions are compared to spell check since the mathematical operation is constant
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct hashEntry
{
  char *text;
  struct hashEntry *next;  
}hashEntry;


unsigned long hash(char *str)
{
	unsigned long hash = 5381;
	int theChar;

	while ((theChar = *str))
	{
    		/* hash * 33 + theChar */
    		hash = ((hash << 5) + hash) + theChar;
    		str++;
	}
	return hash;
}

// Array Size
#define SIZE 40000



int main(int argc, char *argv[]){
    
	char dictWord[80]; // this array reads each word in dictionary
    char wordToCheck[80];// this array reads each word in inputFile
    
	unsigned long hash_value; // hash value calculation

	int numCollisions = 0; // number of collisions initialized to 0

	hashEntry* hashTable[SIZE] = {NULL};
	hashEntry *theHashEntryPtr;

	      
	if (argc < 3) {
        printf("Usage: %s <dictionary_file> <words_file>\n", argv[0]);
        return 1;
    }

	// Making space for dictionary
	FILE *dictFile = fopen(argv[1], "r");

	if (dictFile == NULL){
		printf("ERROR! Cannot find Dictionary.");// Checking
		exit(1);
	}

	// Making space for the file with dictionaries
	FILE *inputFile = fopen(argv[2], "r");	

	if (inputFile == NULL){
		printf("ERROR! Cannot find input file."); // Checking
		exit(2);
	}

   
	while (fgets(dictWord, 80, dictFile) != NULL)
    {
        // Remove newline character
        dictWord[strlen(dictWord) - 1] = 0;
	    hash_value = hash(dictWord) % SIZE;


		if (hashTable[hash_value] != NULL)
    	{
        	numCollisions++;
    	}

		theHashEntryPtr = (hashEntry*)malloc(sizeof(hashEntry));
		if(theHashEntryPtr == NULL)
    	{

    	printf("malloc failed\n");
    	exit(1);
    	}
       

		theHashEntryPtr->text = (char*) malloc(strlen(dictWord) + 1); // Memory allocation

		strcpy(theHashEntryPtr->text,dictWord);
		

        theHashEntryPtr->next = hashTable[hash_value];
        hashTable[hash_value] = theHashEntryPtr;

	}

	printf("Dictionary loaded. numCollisions: %d\n", numCollisions);

	while (fgets(wordToCheck, 80, inputFile) != NULL) {
        // Remove newline character
        wordToCheck[strlen(wordToCheck) - 1] = 0;

        // Hash the word and look it up in the hash table
    	hash_value = hash(wordToCheck) % SIZE;
    	hashEntry *collision = hashTable[hash_value];

	

    	while (collision != NULL) {
            if (strcmp(wordToCheck, collision->text) == 0) {
			   break; 
			}
            collision = collision->next; 
			 // Here we assume a collision has occured
        }
        
        int misspellingCount = 0;
		int listMisspellingCount = 0;

		// Inside the above check:
	if (collision == NULL) {
    	misspellingCount++;
    	if (hashTable[hash_value] == NULL ) {
        	printf("Misspelling found: %s\n", wordToCheck);
    	} else {
        	printf("List based misspelling found: %s\n", wordToCheck);
        	listMisspellingCount++;
    	}
	}
	}

    // FREE THE MEMORY!
	free(theHashEntryPtr);
	fclose(dictFile);
	fclose(inputFile);
	return 0;
}
