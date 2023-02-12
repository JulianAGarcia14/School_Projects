package oop.jgarcia.hw3.testing.three;

import oop.jgarcia.hw3.three.Parallelogram;
import oop.jgarcia.hw3.three.Point;
import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class ParallelogramTest {

    @Test
    public void checkParallelogram() {
        Parallelogram parallelogram = new Parallelogram();
        double expected = Math.PI / 2;
        double actual = parallelogram.getSkewAngle();
        double delta = 0.1;

        Assert.assertEquals("Skew Angle incorrect.", expected, actual, delta);

    }

    @Test
    public void checkBaseLength() {
        Parallelogram parallelogram = new Parallelogram(new Point(0, 0), new Point(4, 4), Math.PI / 4);
        double expected = 4 / (Math.PI / 4);
        double actual = parallelogram.baseLength();
        double delta = 0.1;

        Assert.assertEquals("Base Length incorrect.", expected, actual, delta);

    }

    @Test
    public void checkgetUpperLeft() {
        Parallelogram parallelogram = new Parallelogram(new Point(0, 0), new Point(4, 4), Math.PI / 4);
        Point expected = new Point(4 + (4/(Math.PI / 4)), 4);
        Point actual = parallelogram.getUpperLeft();
        //double delta = 0.1;

        Assert.assertEquals("Upper Left incorrect.", expected, actual);

    }

    @Test
    public void checkgetLowerRight() {
        Parallelogram parallelogram = new Parallelogram(new Point(0, 0), new Point(4, 4), Math.PI / 4);
        Point expected = new Point(4 - (4/(Math.PI / 4)), 4);
        Point actual = parallelogram.getLowerRight();
        //double delta = 0.1;

        Assert.assertEquals("Upper Left incorrect.", expected, actual);

    }

    @Test
    public void checkWidth() {
        Parallelogram parallelogram = new Parallelogram(new Point(0, 0), new Point(4, 4), Math.PI / 4);
        double expected = 4/(Math.PI / 4);
        double actual = parallelogram.width();
        double delta = 0.1;

        Assert.assertEquals("Upper Left incorrect.", expected, actual, delta);

    }

    public void checkWidthBig() {
        Parallelogram parallelogram = new Parallelogram(new Point(0, 0), new Point(4, 4), Math.PI / 1.5);
        double expected = 2 * (4/(Math.PI / 1.5));
        double actual = parallelogram.width();
        double delta = 0.1;

        Assert.assertEquals("Upper Left incorrect.", expected, actual, delta);

    }

    @Test
    public void checkArea() {
        Parallelogram parallelogram = new Parallelogram(new Point(0, 0), new Point(4, 4), Math.PI / 4);
        double expected = 4 * (4 - (4/(Math.PI / 4)));
        double actual = parallelogram.area();
        double delta = 0.1;

        Assert.assertEquals("Upper Left incorrect.", expected, actual, delta);

    }

    @Test
    public void checkPerimeter() {
        Parallelogram parallelogram = new Parallelogram(new Point(0, 0), new Point(4, 4), Math.PI / 4);
        double expected = 2 * (4 + (4 - (4/(Math.PI / 4))));
        double actual = parallelogram.perimeter();
        double delta = 0.1;

        Assert.assertEquals("Upper Left incorrect.", expected, actual, delta);

    }

    @Test
    public void checkInBounds() {
        Parallelogram parallelogram = new Parallelogram(new Point(0, 0), new Point(4, 4), Math.PI / 4);
        boolean expected = true;
        boolean actual = parallelogram.inBounds(1, 1);
        //double delta = 0.1;

        Assert.assertEquals("Upper Left incorrect.", expected, actual);

    }

    @Test
    public void checkInBoundsFalse() {
        Parallelogram parallelogram = new Parallelogram(new Point(0, 0), new Point(4, 4), Math.PI / 4);
        boolean expected = false;
        boolean actual = parallelogram.inBounds(5, 5);
        //double delta = 0.1;

        Assert.assertEquals("Upper Left incorrect.", expected, actual);

    }

}