package oop.jgarcia.hw3.testing.one;

import oop.jgarcia.hw3.one.Fahrenheit;
import oop.jgarcia.hw3.one.Temperature;
import oop.jgarcia.hw3.one.WindChill;
import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;


 public class WindChillTest {

        @Test
        public void checkWindChillTemperature() {
            Temperature temperature = new Fahrenheit(-11.5);
            double windSpeed = 25;
            double expected = -39.365;
            double actual = WindChill.windChill(temperature, windSpeed).getFahrenheit();
            double delta = 0.1;

            Assert.assertEquals("Wind Chill Temp incorrect.", expected, actual, delta);

        }


    }

