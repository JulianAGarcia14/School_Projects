package oop.jgarcia.hw1.three;
import oop.jgarcia.hw1.two.*;
import java.lang.Math.*;
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
     * @param w user given wind speed in mph
     * @return temperature adjusted for windchill
     */
    public Temperature windChill(Temperature t, Double w) {
        double temp =  35.74 + 0.6215*t.getFahrenheit() - 35.75*Math.pow(w, 0.16) + 0.4275*t.getFahrenheit()*Math.pow(w, 0.16);
        return new Temperature(temp, Degrees.FAHRENHEIT);
    }

    /**
     * Determines skin temperature accounting for windChill
     * @param t user given temperature
     * @param w user given wind speed in km/h
     * @return skin temperature adjusted for windchill
     */
    public Temperature skinTemperature(Temperature t, Double w) {
        w = 0.621 * w; //converting to km/h
        double temp = ((0.1*t.getCelsius() - 2.7883) * Math.log(w)) + (0.2977*t.getCelsius()) + 19.874;
        return new Temperature(temp, Degrees.CELSIUS);
    }


    /**
     * Prints out level of frostbite danger
     * @param t temperature given by user
     * @param w wind speed in mph given by user
     * @return void
     */
    public void frostbiteWarning(Temperature t, Double w) {
        w = 0.621 * w; //converting to km/h
        if (t.getCelsius() < -45 || w > 150){
            System.out.print("Extreme Danger!");
        } else if(skinTemperature(windChill(t, w), w).getCelsius() > -4.8 || t.getCelsius() > -10 || w < 15) {
            System.out.print("No Danger");
        } else if(t.getCelsius() <= 7.5*Math.log(w) - 51.4) {
            System.out.print("Warning");
        } else {
            System.out.print("Extreme Danger! Get inside within 10 minutes to avoid freezing!");
        }
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
        Temperature skin = w.skinTemperature(n, wind);
        System.out.println("Wind Chill Temperature: " + df2.format(n.getFahrenheit()) + " Degrees Fahrenheit");
        System.out.println("Final Skin Temperature: " + df2.format(skin.getCelsius()) + " Degrees Celsius");
        w.frostbiteWarning(T, wind);
    }
}
