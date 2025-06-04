/* Adit Syed Afnan
Data Structures CSCI-230
Project 7
04/10/2025 (current date)
This is the header file. Contains both functions except for the main.
*/
typedef struct hashEntry
{
  char *text;
  struct hashEntry *next;  
}hashEntry;
unsigned long hash(char *str);
void printString(char *theString);