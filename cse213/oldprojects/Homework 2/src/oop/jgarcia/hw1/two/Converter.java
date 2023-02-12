package oop.jgarcia.hw1.two;

import java.text.DecimalFormat;
import java.util.*;

/**
 * Uses temperature.java to convert user given temperatures to desired unit.
 * @author Julian Garcia
 * @version HW 2, #2
 */
public class Converter {
    public static void main(String[] args) {
        boolean input = false;
        DecimalFormat df2 = new DecimalFormat("#.0");
        double temp = 0;
        Temperature T = new Temperature(0);
        Scanner in;
        System.out.println("Temperature Conversion Calculator");
        System.out.println("==================================");

        while (input == false) {
            System.out.print("Enter the temperature> ");
            in = new Scanner(System.in);

            if (in.hasNextDouble()) {
                temp = in.nextDouble() ;
                input = true;
            } else {
                System.out.println("Have to enter a double!");
            }
        }
        input = false;

       while(input == false) {
           System.out.print("Enter the temperature unit [K/C/F]> ");
           in = new Scanner(System.in);
           String un1 = in.nextLine();

           switch (un1) {
               case "K":
                   T = new Temperature(temp, Degrees.KELVIN);
                   input = true;
                   break;
               case "C":
                   T = new Temperature(temp, Degrees.CELSIUS);
                   input = true;
                   break;
               case "F":
                   T = new Temperature(temp, Degrees.FAHRENHEIT);
                   input = true;
                   break;
               default:
                   System.out.println("Error! Please enter K or C or F");
                   break;
           }
       }
        input = false;
        while(input == false) {
            System.out.print("Enter the desired unit [K/C/F]> ");
            in = new Scanner(System.in);
            String un2 = in.nextLine();

            switch (un2) {
                case "K":
                    System.out.print("Current Temperature: " + df2.format(T.getKelvin()) + " Kelvin");
                    input = true;
                    break;
                case "C":
                    System.out.print("Current Temperature: " + df2.format(T.getCelsius()) + " degrees Celsius");
                    input = true;
                    break;
                case "F":
                    System.out.print("Current Temperature: " + df2.format(T.getFahrenheit()) + " degrees Fahrenheit");
                    input = true;
                    break;
                default:
                    System.out.println("Error! Please enter K or C or F");
                    break;
            }
        }


    }
}
