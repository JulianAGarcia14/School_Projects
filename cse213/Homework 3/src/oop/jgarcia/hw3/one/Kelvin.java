package oop.jgarcia.hw3.one;

import java.text.DecimalFormat;

public class Kelvin extends Temperature {

    double celsius;
    double fahrenheit;
    double degrees;

    public Kelvin(double deg) {

        super(deg);
        if(deg < 0) {
            deg = 0;
        };

        this.fahrenheit = (deg * (9/5)) - 459.67;
        this.celsius = deg - 273.15;
        this.degrees = deg;
    }

    public double getCelsius() {
        return celsius;
    }

    public double getFahrenheit() {
        return fahrenheit;
    }

    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.00");
        return df.format(degrees) + " Degrees Kelvin";
    }

}
