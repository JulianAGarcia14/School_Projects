package oop.jgarcia.hw6.one;
import java.io.*;
import java.util.*;

/**
 * Parses library.txt to write to binary trees using BinarySearchTree.java
 * @author Julian Garcia
 * @version HW 6, #1
 */
public class Library<E> {

    public static void main(String[] args) throws IOException {
        FileWriter A = new FileWriter("revisedLib.txt");
        PrintWriter output = new PrintWriter(A);
        Scanner in = new Scanner(new FileReader("library.txt")).useDelimiter("\\n");
        boolean caps = false;
        while (in.hasNextLine()) {
            String line = in.nextLine();
            if (line.length() > 0) {
                if (!caps) {
                    output.println(line);
                    caps = true;
                } else {
                    caps = false;
                }
            }
        }
        in.close();
        output.close();

        Scanner s = new Scanner(new FileReader("revisedLib.txt")).useDelimiter(",|\\n");
        ArrayList<String> authList = new ArrayList<String>();
        ArrayList<String> titleList = new ArrayList<String>();
        ArrayList<String> yearList = new ArrayList<String>();
        int i = 0;
        while (s.hasNext()){
            if (i == 0) {
                authList.add(s.next());
                i++;
            } if (i == 1) {
                titleList.add(s.next());
                i++;
            } if (i == 2) {
                yearList.add(s.next());
                i = 0;
            }
        }
        s.close();


        Comparator<String> c;
        c = (e1, e2) -> ((Comparable<String>)e1).compareTo(e2);
        Comparator<String> d;
        d = (e1, e2) -> ((Comparable<String>)e1).compareTo(e2);
        BinarySearchTree authors = new BinarySearchTree(c);
        BinarySearchTree titles = new BinarySearchTree(c);
        BinarySearchTree years = new BinarySearchTree(d);

        authors.addAll(authList);
        titles.addAll(titleList);
        years.addAll(yearList);

        titles.print(Traversal.PREORDER);
        years.print(Traversal.INORDER);
        authors.print(Traversal.POSTORDER);

        Object recent = years.findMax();
        System.out.print("Most Recent Publishing is" + recent);

    }
}
