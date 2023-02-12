package oop.jgarcia.hw0.three;

import java.util.*;

/**
 * Implements a binary search to determine which number the user is guessing
 * asks for an upper and lower bound and counts how many guesses the machine needed to get the right number.
 * @author Julian Garcia
 * @version HW 0, #3
 */
public class Guess {
    public static void main(String[] args) {
        int guess;
        int count = 0;
        boolean correct = false;
        String ans;
        System.out.println("Think of a number!");

        System.out.print("Lower bound: ");
        Scanner in = new Scanner(System.in);
        int lower = in.nextInt();

        System.out.print("Upper bound: ");
        in = new Scanner(System.in);
        int upper = in.nextInt();

        if(upper < lower) {
            guess = upper;
            upper = lower;
            lower = guess;
        } else if(upper == lower){
            System.out.println("Not a valid bound. Your number is obviously " + upper);
        }

        while (!correct) {
            guess = (upper + lower) / 2;
            count = count + 1;
            System.out.print("Is it " + guess + "? [lt/eq/gt]: ");
            in = new Scanner(System.in);
            ans = in.nextLine();
            switch(ans) {
                case "lt":
                    upper = guess;
                    break;
                case "gt":
                    lower = guess;
                    break;
                case "eq":
                    System.out.println("It took " + count + " guesses to find the number " + guess + "!");
                    correct = true;
                    break;
                default:
                    System.out.println("Error! Please enter lt or eq or gt");
                    count = count - 1;
                    break;
            }
        }


    }
}
