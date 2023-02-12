package oop.jgarcia;

/**
 * Creates a point with a getter, setter, constructor, copy constructor,
 * and geometry calculations for distance between points and distance from origin.
 * @author Julian Garcia
 * @version HW 5, #1
 */
public class Point implements Cloneable {
    private double x;
    private double y;
    private double radius;
    private double angle;

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
        this.x = radius * Math.cos(angle);
        this.y = radius * Math.sin(angle);
    }

    public Point clone() throws CloneNotSupportedException {
        Point copy = (Point) super.clone();

        return copy;
    }

    public double getAngle() {
        return angle;
    }

    public void setAngle(double angle){
        this.angle = angle;
        this.x = radius * Math.cos(angle);
        this.y = radius * Math.sin(angle);
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
        radius = Math.sqrt((Math.pow(x, 2)) * (Math.pow(y, 2)));
        angle = Math.atan2(y, x);
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
        radius = Math.sqrt((Math.pow(x, 2)) * (Math.pow(y, 2)));
        angle = Math.atan2(y, x);
    }

    public Point() {
        this.x = 0;
        this.y = 0;
        radius = Math.sqrt((Math.pow(x, 2)) * (Math.pow(y, 2)));
        angle = Math.atan2(y, x);
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
        radius = Math.sqrt((Math.pow(x, 2)) * (Math.pow(y, 2)));
        angle = Math.atan2(y, x);
    }

    public Point(Point p) {
        x = p.x;
        y = p.y;
        radius = Math.sqrt((Math.pow(x, 2)) * (Math.pow(y, 2)));
        angle = Math.atan2(y, x);
    }

    /**
     * Finds distance between two points
     * @param p point to be compared to
     * @return distance
     */
    public double distance(Point p) {
        return Math.sqrt(((this.x - p.x) * (this.x - p.x)) + ((this.y - p.y) * (this.y - p.y)));
    }

    /**
     * Finds distance between point and origin point (0,0)
     * @return distance
     */
    public double distanceFromOrigin() {
        double distance = ((this.x - 0) * (this.x - 0)) + ((this.y - 0) * (this.y - 0));
        distance = Math.sqrt(distance);
        return distance;
    }

    /**
     * Determines which direction a point is compared to another point
     * @param p point to be compared to
     * @return 0 for equal points, 1 for a point above and to the right, -1 for a point below or to the left
     */
    public int compareTo(Point p) {
        if(p.x == this.x && p.y == this.y){
            return 0;
        } else if (p.x > this.x && p.y > this.y) {
            return 1;
        } else if (p.x < this.x || p.y < this.y) {
            return -1;
        }
        return 0;
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}
