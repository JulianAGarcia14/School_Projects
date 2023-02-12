package oop.jgarcia.hw1.one;

import java.lang.Math.*;

/**
 * Creates a circle using a center point (x,y), contains a method to check if a given point is within the circle.
 * Also contains geometry calculations for area, circumference, and distance from origin.
 * @author Julian Garcia
 * @version HW 1, #1
 */
public class Circle {
    private double centerX;
    private double centerY;
    private double radius;

    public Circle() {
        this.centerX = 0;
        this.centerY = 0;
        this.radius = 1;
    }

    public Circle(double x, double y, double radius) {
        this.centerX = x;
        this.centerY = y;
        if(radius < 0){
            radius = Math.abs(radius);
        }
        this.radius = radius;
    }

    public double getCenterX() {
        return centerX;
    }

    public void setCenterX(double centerX) {
        this.centerX = centerX;
    }

    public double getCenterY() {
        return centerY;
    }

    public void setCenterY(double centerY) {
        this.centerY = centerY;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double diameter() {
        return 2*this.radius;
    }

    public double area() {
        return Math.PI * this.radius * this.radius;
    }

    public double perimeter() {
        return Math.PI * 2 * radius;
    }

    public double distanceFromOrigin() {
        double distance = ((this.centerX - 0) * (this.centerX - 0)) + ((this.centerY - 0) * (this.centerY - 0));
        return Math.sqrt(distance);
    }

    public boolean inBounds(double x, double y) {
        if(x <= (this.centerX + radius) && x >= (this.centerX - radius) && y <= (this.centerY + radius) && this.centerY >= this.centerY - radius){
            return true;
        } else {
            return false;
        }
    }
}
