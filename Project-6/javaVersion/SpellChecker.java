package project_6;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 7: Hash Table-Based Spell Checker
 * Date: 2025-04-10
 *
 * Java implementation of a hash table-based spell checker using chaining for collision resolution.
 */

public class SpellChecker {
	// Fixed size of the hash table
  // Fixed size of the hash table
    private static final int SIZE = 40000;

    // The hash table: each bucket is a linked list of HashEntry
    private static HashEntry[] hashTable = new HashEntry[SIZE];

    // HashEntry class for chaining (linked list node)
    static class HashEntry {
        String text;
        HashEntry next;

        public HashEntry(String text) {
            this.text = text;
            this.next = null;
        }
    }

    /**
     * DJB2 Hash Function for Strings
     */
    public static long hash(String str) {
        long hash = 5381;
        for (int i = 0; i < str.length(); i++) {
            hash = ((hash << 5) + hash) + str.charAt(i); // hash * 33 + c
        }
        return hash;
    }

    /**
     * Load dictionary file into hash table with chaining
     */
    public static int loadDictionary(String dictPath) {
        int numCollisions = 0;
        try (BufferedReader dictReader = new BufferedReader(new FileReader(dictPath))) {
            String word;
            while ((word = dictReader.readLine()) != null) {
                word = word.trim();
                long hashValue = hash(word) % SIZE;
                int index = (int) hashValue;

                // Count collisions
                if (hashTable[index] != null) {
                    numCollisions++;
                }

                // Insert at head of chain
                HashEntry newEntry = new HashEntry(word);
                newEntry.next = hashTable[index];
                hashTable[index] = newEntry;
            }
        } catch (IOException e) {
            System.err.println("ERROR! Cannot open dictionary file: " + dictPath);
            System.exit(1);
        }
        return numCollisions;
    }

    /**
     * Spell check words from input file against hash table
     */
    public static void checkSpelling(String inputPath) {
        try (BufferedReader inputReader = new BufferedReader(new FileReader(inputPath))) {
            String word;
            while ((word = inputReader.readLine()) != null) {
                word = word.trim();
                long hashValue = hash(word) % SIZE;
                int index = (int) hashValue;

                HashEntry current = hashTable[index];
                boolean found = false;

                while (current != null) {
                    if (current.text.equals(word)) {
                        found = true;
                        break;
                    }
                    current = current.next;
                }

                if (!found) {
                    if (hashTable[index] == null) {
                        System.out.println("Misspelling found: " + word);
                    } else {
                        System.out.println("List based misspelling found: " + word);
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("ERROR! Cannot open input file: " + inputPath);
            System.exit(2);
        }
    }    
public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage: java SpellChecker <dictionary_file> <words_file>");
            return;
        }

        String dictFile = args[0];
        String inputFile = args[1];

        int collisions = loadDictionary(dictFile);
        System.out.println("Dictionary loaded. numCollisions: " + collisions);
        checkSpelling(inputFile);
    }
    
}
