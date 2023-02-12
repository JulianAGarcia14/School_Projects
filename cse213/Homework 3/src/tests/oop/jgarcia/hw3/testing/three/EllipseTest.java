package oop.jgarcia.hw3.testing.three;

import oop.jgarcia.hw3.three.Ellipse;
import oop.jgarcia.hw3.three.Point;
import oop.jgarcia.hw3.three.Rectangle;
import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class EllipseTest {

    @Test
    public void checkEllipse() {
        Ellipse ellipse = new Ellipse();
        Ellipse expected = new Ellipse(new Point(0, 0), 1, 1);
        Ellipse actual = ellipse;
        //double delta = 0.1;

        Assert.assertEquals("Skew Angle incorrect.", expected, actual);

    }

    @Test
    public void checkFocalDistance() {
        Ellipse ellipse = new Ellipse(new Point(0, 0), 4, 2);
        double expected = Math.sqrt(Math.abs(Math.pow(4, 2) - Math.pow(2, 2)));
        double actual = ellipse.focalDistance();
        double delta = 0.1;

        Assert.assertEquals("Skew Angle incorrect.", expected, actual, delta);

    }

    @Test
    public void checkEccentricity() {
        Ellipse ellipse = new Ellipse(new Point(0, 0), 4, 2);
        double part = Math.sqrt(Math.abs(Math.pow(4, 2) - Math.pow(2, 2)));
        double expected = part / 4;
        double actual = ellipse.eccentricity();
        double delta = 0.1;

        Assert.assertEquals("Skew Angle incorrect.", expected, actual, delta);

    }

    @Test
    public void checkWidth() {
        Ellipse ellipse = new Ellipse(new Point(0, 0), 4, 2);
        double expected = 8;
        double actual = ellipse.width();
        double delta = 0.1;

        Assert.assertEquals("Width incorrect.", expected, actual, delta);

    }

    @Test
    public void checkHeight() {
        Ellipse ellipse = new Ellipse(new Point(0, 0), 4, 2);
        double expected = 4;
        double actual = ellipse.height();
        double delta = 0.1;

        Assert.assertEquals("Height incorrect.", expected, actual, delta);

    }

    @Test
    public void checkDiameter() {
        Ellipse ellipse = new Ellipse(new Point(0, 0), 4, 2);
        double expected = 8;
        double actual = ellipse.diameter();
        double delta = 0.1;

        Assert.assertEquals("Diameter incorrect.", expected, actual, delta);

    }

    @Test
    public void checkDiameterAlt() {
        Ellipse ellipse = new Ellipse(new Point(0, 0), 2, 4);
        double expected = 8;
        double actual = ellipse.diameter();
        double delta = 0.1;

        Assert.assertEquals("Diameter incorrect.", expected, actual, delta);

    }

    @Test
    public void checkArea() {
        Ellipse ellipse = new Ellipse(new Point(0, 0), 4, 2);
        double expected = Math.PI * 4 * 2;
        double actual = ellipse.area();
        double delta = 0.1;

        Assert.assertEquals("Diameter incorrect.", expected, actual, delta);

    }

    @Test
    public void checkPerimeter() {
        Ellipse ellipse = new Ellipse(new Point(0, 0), 4, 2);
        double expected = Math.sqrt(Math.PI * 2) * Math.sqrt(Math.pow(2, 2) + Math.pow(4, 2));
        double actual = ellipse.perimeter();
        double delta = 0.1;

        Assert.assertEquals("Diameter incorrect.", expected, actual, delta);

    }

    @Test
    public void checkInBounds() {
        Ellipse ellipse = new Ellipse(new Point(0, 0), 4, 2);
        boolean expected = true;
        boolean actual = ellipse.inBounds(1, 2);
        //double delta = 0.1;

        Assert.assertEquals("Diameter incorrect.", expected, actual);

    }

    @Test
    public void checkInBoundsAlt() {
        Ellipse ellipse = new Ellipse(new Point(0, 0), 4, 2);
        boolean expected = false;
        boolean actual = ellipse.inBounds(4, 6);
        //double delta = 0.1;

        Assert.assertEquals("Diameter incorrect.", expected, actual);

    }

    @Test
    public void checkGetBoundingBox() {
        Ellipse ellipse = new Ellipse(new Point(0, 0), 4, 2);
        Rectangle expected = new Rectangle(new Point(4, 2), new Point(-4, 0));
        Rectangle actual = ellipse.getBoundingBox();
        //double delta = 0.1;

        Assert.assertEquals("Diameter incorrect.", expected, actual);

    }




}