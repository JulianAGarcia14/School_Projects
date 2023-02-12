package oop.jgarcia.hw1.one;
import java.lang.Math.*;

/**
 * Creates a point with a getter, setter, constructor, copy constructor,
 * and geometry calculations for distance between points and distance from origin.
 * @author Julian Garcia
 * @version HW 1, #1
 */
public class Point {
    private double x;
    private double y;

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public Point() {
        this.x = 0;
        this.y = 0;
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Point(Point p) {
        x = p.x;
        y = p.y;
    }

    public double distance(Point p) {
        return Math.sqrt(((this.x - p.x) * (this.x - p.x)) + ((this.y - p.y) * (this.y - p.y)));
    }

    public double distanceFromOrigin() {
        double distance = ((this.x - 0) * (this.x - 0)) + ((this.y - 0) * (this.y - 0));
        distance = Math.sqrt(distance);
        return distance;
    }
}
