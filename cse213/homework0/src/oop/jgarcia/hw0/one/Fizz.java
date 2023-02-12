package oop.jgarcia.hw0.one;

/**
 * Loops through 1 to 100 and prints fizz, buzz, razz corresponding respectively to
 * if the number is a multiple of 3, 4, 5 or some combination of the three.
 * @author Julian Garcia
 * @version HW 0, #1
 */
public class Fizz {
    public static void main(String[] args){
        for (int n = 1; n <= 100; n++) {
            if(n % 3 == 0 && n % 4 == 0 && n % 5 == 0){
                System.out.println("FizzRazzBuzz");
            } else if(n % 3 == 0 && n % 5 == 0) {
                System.out.println("FizzBuzz");
            } else if(n % 4 == 0 && n % 5 == 0) {
                System.out.println("RazzBuzz");
            } else if(n % 3 == 0 && n % 4 == 0) {
                System.out.println("FizzRazz");
            } else if(n % 5 == 0) {
                System.out.println("Buzz");
            } else if(n % 4 == 0) {
                System.out.println("Razz");
            } else if(n % 3 == 0) {
                System.out.println("Fizz");
            } else {
                System.out.println(n);
            }
        }
    }
}
