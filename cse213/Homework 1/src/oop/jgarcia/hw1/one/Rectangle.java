package oop.jgarcia.hw1.one;

import java.lang.Math.*;

/**
 * Creates a rectangle using two points, contains a method to check if a given point is within the rectangle.
 * Also contains geometry calculations for area, perimeter, and distance from origin.
 * @author Julian Garcia
 * @version HW 1, #1
 */
public class Rectangle {
    private double lowerLeftX;
    private double lowerLeftY;
    private double upperRightX;
    private double upperRightY;

    public double getLowerLeftX() {
        return lowerLeftX;
    }

    public void setLowerLeftX(double lowerLeftX) {
        this.lowerLeftX = lowerLeftX;
    }

    public double getLowerLeftY() {
        return lowerLeftY;
    }

    public void setLowerLeftY(double lowerLeftY) {
        this.lowerLeftY = lowerLeftY;
    }

    public double getUpperRightX() {
        return upperRightX;
    }

    public void setUpperRightX(double upperRightX) {
        this.upperRightX = upperRightX;
    }

    public double getUpperRightY() {
        return upperRightY;
    }

    public void setUpperRightY(double upperRightY) {
        this.upperRightY = upperRightY;
    }

    public Rectangle() {
        this.lowerLeftX = 0;
        this.lowerLeftY = 0;
        this.upperRightX = 1;
        this.upperRightY = 1;
    }

    public Rectangle(double width, double height) {
        this.lowerLeftX = 0;
        this.lowerLeftY = 0;
        if(height < 0) {
            height = 0;
        }
        if(width < 0) {
            height = 0;
        }
        this.upperRightX = width;
        this.upperRightY = height;
    }

    public Rectangle(double x1, double y1, double x2, double y2) {

        if(x1 < 0) {
            x1 = 0;
        }
        if(y1 < 0) {
            y1 = 0;
        }
        if(x2 < 0) {
            x2 = 0;
        }
        if(y2 < 0) {
            y2 = 0;
        }

        if(x1 > x2 && y1 > y2) {
            double temp;
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y2;
            y2 = y1;
            y1 = temp;
        } else if(x1 > x2 && y1 < y2) {
            double temp2;
            temp2 = x1;
            x1 = x2;
            x2 = temp2;
        } else if(x1 < x2 && y1 > y2) {
            double temp3;
            temp3 = y1;
            y1 = y2;
            y2 = temp3;
        }
        this.lowerLeftX = x1;
        this.lowerLeftY = y1;
        this.upperRightX = x2;
        this.upperRightY = y2;
    }

    public double width() {
        double width = Math.abs(this.upperRightX - this.lowerLeftX);
        return width;
    }

    public double height() {
        double height = Math.abs(this.upperRightY - this.lowerLeftY);
        return height;
    }

    public double area() {
        return width() * height();
    }

    public double perimeter() {
        double width = 2 * Math.abs(this.upperRightX - this.lowerLeftX);
        double height = 2 * Math.abs(this.upperRightY - this.lowerLeftY);
        return width + height;
    }

    public double distanceFromOrigin() {
        double distance = ((this.lowerLeftX - 0) * (this.lowerLeftX - 0)) + ((this.lowerLeftY - 0) * (this.lowerLeftY - 0));
        return Math.sqrt(distance);
    }

    public boolean inBounds(double x, double y) {
        if(x <= this.upperRightX && x >= this.lowerLeftX && y <= this.upperRightY && y >= this.lowerLeftY) {
            return true;
        } else {
            return false;
        }

    }
}
