import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class HashCollisionDetector {

    private static final int TABLE_SIZE = 10000;
    private int[] hashTable = new int[TABLE_SIZE];

    /**
     * DJB2 string hashing algorithm.
     */
    public long hash(String str) {
        long hash = 5381;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            hash = ((hash << 5) + hash) + c; // hash * 33 + c
        }
        return hash;
    }

    /**
     * Reads words from a file, hashes them, and reports collisions.
     */
    public void detectCollisions(String filename) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String inputLine;

            while ((inputLine = reader.readLine()) != null) {
                // Remove newline or trailing spaces
                inputLine = inputLine.strip();

                // Compute hash and index
                long hashValue = hash(inputLine);
                int index = (int)(hashValue % TABLE_SIZE);

                // Check for collision
                if (hashTable[index] != 0) {
                    System.out.println("Collision found! " + inputLine);
                }

                // Mark the slot as used
                hashTable[index] = 1;
            }

        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    /**
     * Main method: expects filename as command-line argument.
     */
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Usage: java HashCollisionDetector <inputFile>");
            return;
        }

        String filename = args[0];
        HashCollisionDetector detector = new HashCollisionDetector();
        detector.detectCollisions(filename);
    }
}
