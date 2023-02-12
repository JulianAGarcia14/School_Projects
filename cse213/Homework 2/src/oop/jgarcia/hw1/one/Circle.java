package oop.jgarcia.hw1.one;

import java.lang.Math.*;

/**
 * Creates a circle using a center point (x,y), contains a method to check if a given point is within the circle.
 * Also contains geometry calculations for area, circumference, and distance from origin.
 * @author Julian Garcia
 * @version HW 2, #1
 */
public class Circle {
    private Point center;
    private double radius;

    public Point getCenter() {
        return new Point(center);
    }

    public void setCenter(Point center) {
        this.center = new Point(center);
    }

    public double getRadius() {
        return Math.abs(radius);
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public Circle() {
        this.center = new Point(0, 0);
        this.radius = 1;
    }

    public Circle(Point center, double radius) {
        this.center = new Point(center);
        this.radius = Math.abs(radius);
    }

    /**
     * Determines diameter of circle
     * @return diameter of circle
     */
    public double diameter() {
        return 2*this.radius;
    }

    /**
     * Determines area of circle
     * @return area of circle
     */
    public double area() {
        return Math.PI * this.radius * this.radius;
    }

    /**
     * Determines perimeter of circle
     * @return perimeter of circle
     */
    public double perimeter() {
        return Math.PI * 2 * radius;
    }

    /**
     * determines distance of circle center from origin point (0,0)
     * @return distance from the origin point
     */
    public double distanceFromOrigin() {
        double distance = ((this.center.getX() - 0) * (this.center.getX() - 0)) + ((this.center.getY() - 0) * (this.center.getY() - 0));
        return Math.sqrt(distance);
    }

    /**
     * Determines if a point is inside of the area of the circle
     * @return true or false
     */
    public boolean inBounds(double x, double y) {
        if(x <= (this.center.getX() + radius) && x >= (this.center.getX() - radius) && y <= (this.center.getY() + radius) && this.center.getY() >= this.center.getY() - radius){
            return true;
        } else {
            return false;
        }
    }

    /**
     * "Draws" a rectangle around the edges of the circle
     * @return
     */
    public Rectangle getBoundingBox() {
        Rectangle rect = new Rectangle(new Point(center.getX() + radius, center.getY() + radius), new Point(center.getX() - radius, center.getY() - radius));
        return rect;
    }
}
