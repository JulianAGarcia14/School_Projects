package oop.jgarcia.hw5.one;

public class Ellipse extends Circle{
    private double minorRadius;

    public double getMinorRadius() {
        return minorRadius;
    }

    public Ellipse() {
        super();
        this.minorRadius = getRadius();
    }

    public Ellipse(Point p, double q, double r) {
        super(p, q);
        this.minorRadius = getRadius();
    }

    public double focalDistance() {
        return Math.sqrt(Math.abs(Math.pow(getRadius(), 2) - Math.pow(minorRadius, 2)));
    }

    public double eccentricity() {
        return focalDistance()/(Math.max(minorRadius, getRadius()));
    }

    @Override
    public double width() {
        return getRadius() * 2;
    }

    @Override
    public double height() {
        return minorRadius * 2;
    }

    @Override
    public double diameter() {
        if(minorRadius > getRadius()) {
            return minorRadius * 2;
        } else {
            return getRadius() * 2;
        }
    }

    @Override
    public double area() {
        return Math.PI * getRadius() * this.minorRadius;
    }

    @Override
    public double perimeter() {
        return Math.sqrt(Math.PI * 2) * Math.sqrt(Math.pow(minorRadius, 2) + Math.pow(getRadius(), 2));
    }

    @Override
    public boolean inBounds(double x, double y) {
        Point c = getCenter();

        double ans = ((Math.pow((x - c.getX()), 2) / Math.pow(getRadius(), 2))) + (Math.pow(y - c.getY(), 2) / (Math.pow(minorRadius, 2)));

        if(ans <= 1){
            return true;
        } else {
            return false;
        }
    }

    @Override
    public Rectangle getBoundingBox() {
        Point c = getCenter();
        Rectangle rect = new Rectangle(new Point(c.getX() + getRadius(), c.getY() + minorRadius), new Point(c.getX() - getRadius(), c.getY() - minorRadius));
        return rect;
    }

}
