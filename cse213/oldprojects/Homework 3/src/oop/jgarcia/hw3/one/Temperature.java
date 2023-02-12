package oop.jgarcia.hw3.one;
import java.text.*;


/**
 * Records temperature in kelvin, celsius, and fahrenheit
 * @author Julian Garcia
 * @version HW 2, #2
 */
public class Temperature {
    protected double degrees;

    public double getDegrees() {
        return degrees;
    }

    public void setDegrees(double degrees) {
        this.degrees = degrees;
    }

    public double getCelsius() {
        return degrees;
    }

    public double getFahrenheit() {
        return degrees;
    }

    public double getKelvin() {
        return degrees;
    }

    public Temperature(double t) {
        degrees = t;
    }

    /*
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
    */
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.00");
        return df.format(degrees) + " Degrees";
    }
}
