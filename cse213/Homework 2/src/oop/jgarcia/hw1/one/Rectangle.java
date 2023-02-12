package oop.jgarcia.hw1.one;

import java.lang.Math.*;

/**
 * Creates a rectangle using two points, contains a method to check if a given point is within the rectangle.
 * Also contains geometry calculations for area, perimeter, and distance from origin.
 * @author Julian Garcia
 * @version HW 2, #1
 */
public class Rectangle {
    private Point lowerLeft;
    private Point upperRight;

    public Point getLowerLeft() {
        return new Point(lowerLeft);
    }

    public Point getUpperRight() {
        return new Point(upperRight);
    }

    public Point getUpperLeft() {
        return new Point(lowerLeft.getX(), upperRight.getY());
    }
    public Point getLowerRight() {
        return new Point(upperRight.getX(), lowerLeft.getY());
    }


    public Rectangle() {
        this.lowerLeft = new Point(0, 0);
        this.upperRight = new Point(1, 1);
    }

    /**
     * Takes two points and creates a rectangle using them, also auto adjusts for incorrect point placements
     * @param upperRight ideally the upper right point of rectangle
     * @param lowerLeft ideally the lower left point of rectangle
     */
    public Rectangle(Point upperRight, Point lowerLeft) {

        if(lowerLeft.getX()  > upperRight.getX()  && lowerLeft.getY()  > upperRight.getY() ) {
            Point p = upperRight;
            upperRight = lowerLeft;
            lowerLeft = p;
        } else if(lowerLeft.getX() > upperRight.getX() && lowerLeft.getY() < upperRight.getY()) {
            double urx;
            double ury;
            double llx;
            double lly;
            urx = lowerLeft.getX();
            ury = upperRight.getY();
            llx = upperRight.getX();
            lly = lowerLeft.getY();
            lowerLeft = new Point(llx, lly);
            upperRight = new Point(urx, ury);
        } else if(lowerLeft.getX() < upperRight.getX() && lowerLeft.getY() > upperRight.getY()) {
            double urx;
            double ury;
            double llx;
            double lly;
            urx = upperRight.getX();
            ury = lowerLeft.getY();
            llx = lowerLeft.getX();
            lly = upperRight.getY();
            lowerLeft = new Point(llx, lly);
            upperRight = new Point(urx, ury);
        }
        this.lowerLeft = lowerLeft;
        this.upperRight = upperRight;
    }

    public Rectangle(double width, double height) {
        this(new Point(0, 0), new Point(width, height));
    }

    /**
     * Finds width of the rectangle
     * @return width of the rectangle
     */
    public double width() {
        double width = Math.abs(this.upperRight.getX() - this.lowerLeft.getX());
        return width;
    }

    /**
     * Finds height of the rectangle
     * @return height of the rectangle
     */
    public double height() {
        double height = Math.abs(this.upperRight.getY() - this.lowerLeft.getY());
        return height;
    }

    /**
     * Finds area of the rectangle
     * @return area of the rectangle
     */
    public double area() {
        return width()*height();
    }

    /**
     * Finds the perimeter of the rectangle
     * @return perimeter of the rectangle
     */
    public double perimeter() {
        return (2* width()) + (2 * height());
    }

    /**
     * Finds distance of lower left corner of rectangle from origin point (0,0)
     * @return distance from origin point
     */
    public double distanceFromOrigin() {
        double distance = ((this.lowerLeft.getX() - 0) * (this.lowerLeft.getX() - 0)) + ((this.lowerLeft.getY() - 0) * (this.lowerLeft.getY() - 0));
        return Math.sqrt(distance);
    }

    /**
     * Determines if a point is inside the area of the rectangle
     * @param x x coordinate of point
     * @param y y coordinate of point
     * @return true or false
     */
    public boolean inBounds(double x, double y) {
        if(x <= this.upperRight.getX() && x >= this.lowerLeft.getX() && y <= this.upperRight.getY() && y >= this.lowerLeft.getY()) {
            return true;
        } else {
            return false;
        }

    }
}
