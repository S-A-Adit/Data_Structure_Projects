/* Adit Syed Afnan
Data Structures CSCI-230
Project 6
04/01/2025 (current date)
Project 6 Code. This program reads a file. Uses a hash algorithm and stores it in an array. Checks if there is words in a file with the same hashcode and prints collision found each time.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned long hash(char *str)
{
	unsigned long hash = 5381;
	int theChar;

	while ((theChar = *str))
	{
    	/* hash * 33 + theChar */
        // Shifting multiplication
    	hash = ((hash << 5) + hash) + theChar;
    	str++;
	}
	return hash;
}

void printString(char *theString){
    while(*theString!=0){
        putchar(*theString);
        theString++;
    }
}

int main(int argc, char **argv){
    FILE *theFile;
    char inputString[255];
    int hashtable[10000];



    if(argc < 2){
        printf("Usage: filefun <theFile>\n");
        exit(2); // NEW
    }

    theFile = fopen(argv[1], "r");
    printf("%s",*argv);



    if (!theFile) {
        printf("Error opening file");
        exit(1); // NEW
    }

    while (fgets(inputString, 256, theFile)){


     inputString[strlen(inputString -1)] = 0;
     
     int hash_value = hash(inputString) % 10000;

     if (hashtable[hash_value]) {
         printString("Collision found! ");
         printString(inputString);
         putchar('\n');
     }
     hashtable[hash_value] = 1;


    }

    fclose(theFile);
                              

    return 0;

}