package oop.jgarcia.hw5.one;

public class Parallelogram extends Rectangle {
    private double skewAngle;

    public double getSkewAngle() {
        return skewAngle;
    }

    public Parallelogram() {
        super();
        this.skewAngle = Math.PI / 2;
    }

    public Parallelogram(Point p, Point q, double r) {

        super(p, q);
        if (r > Math.atan2(q.getY() - p.getY(), q.getX() - p.getX()) || r > Math.PI) {
            this.skewAngle = Math.PI / 2;
        } else {
            this.skewAngle = r;
        }
    }

    public double baseLength() {
        return width()/skewAngle;
    }

    @Override
    public Point getUpperLeft() {
        Point ll = getLowerLeft();
        Point ur = getUpperRight();
        return new Point(ll.getX() + baseLength(), ur.getY());
    }

    @Override
    public Point getLowerRight() {
        Point ll = getLowerLeft();
        Point ur = getUpperRight();
        return new Point(ur.getX() - baseLength(), ll.getY());
    }

    @Override
    public double width() {
        if(skewAngle > Math.PI / 2) {
            return 2 * baseLength();
        } else {
            return baseLength();
        }
    }

    @Override
    public double area() {
        Point ll = getLowerLeft();
        Point ur = getUpperRight();
        double width = Math.abs(ur.getX() - ll.getX() - baseLength());
        double height = Math.abs(ur.getY() - ll.getY());
        return width*height;
    }

    @Override
    public double perimeter() {
        Point ll = getLowerLeft();
        Point ur = getUpperRight();
        double width = 2 * Math.abs(ur.getX() - ll.getX() - baseLength());
        double height = 2 * Math.abs(ur.getY() - ll.getY());
        return width + height;
    }

    @Override
    public boolean inBounds(double x, double y) {
        Point ll = getLowerLeft();
        Point ur = getUpperRight();
        if(x <= ur.getX() && x >= ll.getX() && y <= ur.getY() && y >= ll.getY()) {
            return true;
        } else {
            return false;
        }

    }

}
