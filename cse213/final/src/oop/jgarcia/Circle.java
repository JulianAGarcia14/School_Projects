package oop.jgarcia;

/**
 * Creates a circle using a center point (x,y), contains a method to check if a given point is within the circle.
 * Also contains geometry calculations for area, circumference, and distance from origin.
 * @author Julian Garcia
 * @version HW 5, #1
 */
public class Circle extends Shape implements Movable{
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

    public double width() {
        return radius * 2;
    }
    public double height() {
        return radius * 2;
    }

    public Circle() {
        this.center = new Point(0, 0);
        this.radius = 1;
    }

    public Circle(Point center, double radius) {
        this.center = new Point(center);
        this.radius = Math.abs(radius);
    }

    public Circle clone() throws CloneNotSupportedException {
        Circle copy = (Circle) super.clone();
        copy.center = (Point) center.clone();

        return copy;
    }

    public void setPosition(double x, double y) {
        this.center.setX(x);
        this.center.setY(y);
    }

    public void setPolar(double radius, double angle){
        this.center.setAngle(angle);
        this.center.setRadius(radius);
    }

    public void move(double dx, double dy) {
        double x = this.center.getX();
        double y = this.center.getY();
        this.center.setX(dx + x);
        this.center.setY(dy + y);
    }
    public void movePolar(double radius, double angle) {
        double rad = this.center.getRadius();
        double ang = this.center.getAngle();
        this.center.setAngle(angle + ang);
        this.center.setRadius(radius + rad);
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
     * Determines diameter of circle
     * @return diameter of circle
     */
    public double diameter() {
        return radius * 2;
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
