package oop.jgarcia.hw0.two;

import java.util.*;

/**
 * Rock, Paper, Scissors game, takes in user input for move and closes once computer wins two
 * games in a row. Computer cycles through the moves rock, paper, scissors in order.
 * @author Julian Garcia
 * @version HW 0, #2
 */
public class RPS {
    public static void main(String[] args) {
        int cpwin = 0;
        int rounds = 1;
        String cpmove = "rock";

        while (cpwin < 2) {
            System.out.print("Your move? [rock/paper/scissors]: ");
            Scanner in = new Scanner(System.in);
            String input = in.nextLine();
            String move = input.toLowerCase();
            switch(rounds) {
                case 1:
                    cpmove = "rock";
                    break;
                case 2:
                    cpmove = "paper";
                    break;
                case 3:
                    cpmove = "scissors";
                    break;
            }
            switch (move) {
                case "rock":
                    System.out.println(">" + cpmove);
                    if (cpmove.equals("paper")) {
                        System.out.println("Computer wins!");
                        cpwin = cpwin + 1;
                    } else if(cpmove.equals("rock")){
                        System.out.println("Draw!");
                        cpwin = 0;
                    } else {
                        System.out.println("Player wins!");
                        cpwin = 0;
                    }
                    break;
                case "paper":
                    System.out.println(">" + cpmove);
                    if (cpmove.equals("scissors")) {
                        System.out.println("Computer wins!");
                        cpwin = cpwin + 1;
                    } else if(cpmove.equals("paper")){
                        System.out.println("Draw!");
                        cpwin = 0;
                    } else {
                        System.out.println("Player wins!");
                        cpwin = 0;
                    }
                    break;
                case "scissors":
                    System.out.println(">" + cpmove);
                    if (cpmove.equals("rock")) {
                        System.out.println("Computer wins!");
                        cpwin = cpwin + 1;
                    } else if(cpmove.equals("scissors")){
                        System.out.println("Draw!");
                        cpwin = 0;
                    } else {
                        System.out.println("Player wins!");
                        cpwin = 0;
                    }
                    break;
                default:
                    System.out.println("Error! Incorrect input, please enter either rock, paper, or scissors.");
                    rounds = rounds - 1;
                    break;
            }
            rounds = rounds + 1;
            if (rounds > 3) {
                rounds = 1;
            }
        }
        System.out.println("Good Game!");
    }
}
