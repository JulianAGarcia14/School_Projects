package oop.jgarcia.hw3.one;

import java.text.DecimalFormat;

public class Fahrenheit extends Temperature {

    double celsius;
    double kelvin;
    double degrees;

    public Fahrenheit(double deg) {

        super(deg);
        if(deg < 0) {
            deg = 0;
        };
        this.degrees = deg;
        this.celsius = (0.5555)*(deg - 32);
        this.kelvin = (deg - 32) * (0.5555) + 273.15;;
    }

    public double getCelsius() {
        return celsius;
    }

    public double getKelvin() {
        return kelvin;
    }

    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.00");
        return df.format(degrees) + " Degrees Fahrenheit";
    }

}
