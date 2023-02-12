package oop.jgarcia.hw8.two;

/**
 * Creates a rectangle using two points, contains a method to check if a given point is within the rectangle.
 * Also contains geometry calculations for area, perimeter, and distance from origin.
 * @author Julian Garcia
 * @version HW 5, #1
 */
public class Rectangle extends Shape implements Movable, Cloneable{
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

    public double width() {
        return upperRight.getX() - lowerLeft.getX();
    }
    public double height() {
        return upperRight.getY() - lowerLeft.getY();
    }


    public Rectangle clone() throws CloneNotSupportedException {
        Rectangle copy = (Rectangle)super.clone();
        copy.lowerLeft = (Point) lowerLeft.clone();
        copy.upperRight = (Point) upperRight.clone();

        return copy;
        }


    public void setPosition(double x, double y) {
        this.lowerLeft.setX(x);
        this.lowerLeft.setY(y);
        double urx = width() + x;
        double ury = height() + y;
        this.upperRight.setX(urx);
        this.upperRight.setY(ury);
    }

    public void setPolar(double radius, double angle){
        this.lowerLeft.setAngle(angle);
        this.lowerLeft.setRadius(radius);
        double urx = width() + this.lowerLeft.getX();
        double ury = height() + this.upperRight.getY();
        this.upperRight.setX(urx);
        this.upperRight.setY(ury);

    }

    public void move(double dx, double dy) {
        double x = this.lowerLeft.getX();
        double y = this.lowerLeft.getY();

        double urx = this.upperRight.getX();
        double ury = this.upperRight.getY();

        this.lowerLeft.setX(dx + x);
        this.lowerLeft.setY(dy + y);



        this.upperRight.setX(urx + dx);
        this.upperRight.setY(ury + dy);
    }
    public void movePolar(double radius, double angle) {
        double rad = this.lowerLeft.getRadius();
        double ang = this.lowerLeft.getAngle();
        this.lowerLeft.setAngle(angle + ang);
        this.lowerLeft.setRadius(radius + rad);
        double urx = width() + this.lowerLeft.getX();
        double ury = height() + this.upperRight.getY();
        this.upperRight.setX(urx);
        this.upperRight.setY(ury);
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
     * Finds area of the rectangle
     * @return area of the rectangle
     */
    public double area() {
        double width = Math.abs(this.upperRight.getX() - this.lowerLeft.getX());
        double height = Math.abs(this.upperRight.getY() - this.lowerLeft.getY());
        return width*height;
    }

    /**
     * Finds the perimeter of the rectangle
     * @return perimeter of the rectangle
     */
    public double perimeter() {
        double width = 2 * Math.abs(this.upperRight.getX() - this.lowerLeft.getX());
        double height = 2 * Math.abs(this.upperRight.getY() - this.lowerLeft.getY());
        return width + height;
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
