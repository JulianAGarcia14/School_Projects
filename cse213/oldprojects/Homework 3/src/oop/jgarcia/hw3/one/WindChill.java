package oop.jgarcia.hw3.one;

import java.text.DecimalFormat;
import java.util.Scanner;


/**
 * Uses the temperature class to determine temperature accounting for wind speed as well as the time it takes for someone
 * to be frostbitten at a user given temperature and wind speed.
 * @author Julian Garcia
 * @version HW 2, #2
 */
public class WindChill {
    /**
     * Determines temperature accounting for windChill
     * @param t user given temperature
     * @param w user given wind speed
     * @return temperature adjusted for windchill
     */
    public static Temperature windChill(Temperature t, Double w) {
        double temp =  35.74 + 0.6125*t.getFahrenheit() - 35.75*Math.pow(w, 0.16) + 0.4275*t.getFahrenheit()*Math.pow(w, 0.16);
        return new Fahrenheit(temp);
    }

    /**
     * Determines skin temperature in celsius
     * @param t user given temperature
     * @param w user given wind speed
     * @return skin temperature
     */
    public Celsius skinTemperature(Temperature t, Double w) {
        double temp = ((t.getCelsius() * 0.1) - 2.7883) * Math.log(w) + ((0.2977)*t.getCelsius()) + 19.874;
        return new Celsius(temp);
    }

    /**
     * Determines time needed to develop frostbite, essentially frostbiteWarning
     * @param t temperature given by user
     * @param w wind speed in mph given by user
     * @return time to frostbite, or -1 for no risk of frostbite or 0 for definite frostbite
     */
    public double frostBite(Temperature t, Double w) {
        if(t.getCelsius() > -15) {
            return -1;
        } else if(t.getCelsius() < -50 || w > 50) {
            return 0;
        }
        double time = (-26.133 * w + 1994.6) * Math.pow((-4.8 - t.getCelsius()), -1.668);
        return time;
    }


    public static void main(String[] args) {
        boolean input = false;
        DecimalFormat df2 = new DecimalFormat("#.00");
        double temp = 0;
        double wind = 0;
        Temperature T = new Temperature(0);
        Scanner in;
        System.out.println("Wind Chill Frostbite Clock");
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
                    T = new Kelvin(temp);
                    input = true;
                    break;
                case "C":
                    T = new Celsius(temp);
                    input = true;
                    break;
                case "F":
                    T = new Fahrenheit(temp);
                    input = true;
                    break;
                default:
                    System.out.println("Error! Please enter K or C or F");
                    break;
            }
        }
        input = false;
        while (input == false) {
            System.out.print("Enter the wind speed (mph)> ");
            in = new Scanner(System.in);

            if (in.hasNextDouble()) {
                wind = in.nextDouble() ;
                input = true;
            } else {
                System.out.println("Have to enter a double!");
            }
        }
        WindChill w = new WindChill();
        Temperature n = w.windChill(T, wind);
        double time = w.frostBite(T, wind);
        Temperature m = w.skinTemperature(T, wind);
        System.out.println("Wind Chill Temperature: " + df2.format(n.getFahrenheit()) + " Degrees Fahrenheit");
        System.out.println("Final Skin Temperature: " + df2.format(m.getCelsius()) + " Degrees Celsius");
        if(time == -1) {
            System.out.println("No danger of Frostbite");
        } else if (time == 0) {
            System.out.println("omae wa mou shindeiru (you are already dead)");
        } else {
            System.out.println("Time to frostbite: " + df2.format(time) + " minutes");
        }
    }
}
