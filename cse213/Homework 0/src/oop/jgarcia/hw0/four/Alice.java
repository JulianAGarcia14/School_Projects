package oop.jgarcia.hw0.four;

import java.util.*;
import java.io.*;

/**
 * Parses the file Alice.txt and outputs a modified version of the file
 * specifically edits every other line to uppercase and lowercase.
 * @author Julian Garcia
 * @version HW 0, #4
 */
public class Alice {
    public static void main(String[] args) throws IOException{
        boolean caps = false;
        FileWriter Alice = new FileWriter("alice_in_mixed_case.txt");
        PrintWriter output = new PrintWriter(Alice);

        Scanner in = new Scanner(new FileReader("alice.txt"));
        while (in.hasNextLine()) {
            String line = in.nextLine();
            if (line.length() > 0) {
                if (!caps) {
                    line = line.toUpperCase();
                    output.println(line);
                    caps = true;
                } else {
                    line = line.toLowerCase();
                    output.println(line);
                    caps = false;
                }
            } else {
                output.println("");
            }
        }

        in.close();
        output.close();
    }
}
