package oop.jgarcia.hw1.two;
import java.text.*;


/**
 * Records temperature in kelvin, celsius, and fahrenheit
 * @author Julian Garcia
 * @version HW 2, #2
 */
public class Temperature {
    private double kelvin;
    private double celsius;
    private double fahrenheit;

    public double getCelsius() {
        return celsius;
    }

    public double getFahrenheit() {
        return fahrenheit;
    }

    public double getKelvin() {
        return kelvin;
    }

    public void setCelsius(double celsius) {
        this.celsius = celsius;
        fahrenheit = (1.8*celsius) + 32;
        kelvin = celsius + 273.15;
    }

    public void setFahrenheit(double fahrenheit) {
        this.fahrenheit = fahrenheit;
        celsius = (0.5555)*(fahrenheit - 32);
        kelvin = (fahrenheit - 32) * (0.5555) + 273.15;;
    }

    public void setKelvin(double kelvin) {
        this.kelvin = kelvin;
        fahrenheit = (kelvin * (9/5)) - 459.67;
        celsius = kelvin - 273.15;
    }

    public Temperature(double t) {
        celsius = t;
        fahrenheit = (1.8*celsius) + 32;
        kelvin = celsius + 273.15;
    }
    public Temperature(double t, Degrees d) {
        if(d == Degrees.CELSIUS) {
            celsius = t;
            fahrenheit = (1.8*celsius) + 32;
            kelvin = celsius + 273.15;
        }else if(d == Degrees.KELVIN) {
            kelvin = t;
            fahrenheit = (kelvin * (9/5)) - 459.67;
            celsius = kelvin - 273.15;
        }else if(d == Degrees.FAHRENHEIT) {
            fahrenheit = t;
            celsius = (0.5555)*(fahrenheit - 32);
            kelvin = (fahrenheit - 32) * (0.5555) + 273.15;
        }
    }

    public String toString() {
        DecimalFormat df = new DecimalFormat("#.00");
        return df.format(celsius) + " C";
    }
}
