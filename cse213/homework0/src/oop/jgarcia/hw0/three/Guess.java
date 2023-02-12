package oop.jgarcia.hw0.three;

import java.util.*;

/**
 * Rock, Paper, Scissors game, takes in user input for move and closes once computer wins two
 * games in a row. Computer cycles through the moves rock, paper, scissors in order.
 * @author Julian Garcia
 * @version HW 0, #2
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
