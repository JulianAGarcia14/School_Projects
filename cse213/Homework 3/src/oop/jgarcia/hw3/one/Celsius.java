package oop.jgarcia.hw3.one;

import java.text.DecimalFormat;

public class Celsius extends Temperature {

    double fahrenheit;
    double kelvin;
    double degrees;

    public Celsius(double celsius) {

        super(celsius);
        if(celsius < 0) {
            celsius = 0;
        };
        this.degrees = celsius;
        this.fahrenheit = (1.8*celsius) + 32;
        this.kelvin = celsius + 273.15;
    }

    public double getKelvin() {
        return kelvin;
    }

    public double getFahrenheit() {
        return fahrenheit;
    }

    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.00");
        return df.format(degrees) + " Degrees Celsius";
    }

}
