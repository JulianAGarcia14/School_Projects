package oop.jgarcia.hw1.one;

/**
 * Tests methods of geometric classes within package, specifically tests for incorrect results
 * as it prints out notifications for when results are incorrect
 * @author Julian Garcia
 * @version HW 1, #1
 */
public class Test {
    //First Rectangle Test
    public static void testRectangleWrongPoints() {
        Rectangle rect = new Rectangle(3, 2, 1, 4);
        double x1 = rect.getLowerLeftX();
        double y1 = rect.getLowerLeftY();
        double x2 = rect.getUpperRightX();
        double y2 = rect.getUpperRightY();

        if (x1 != 1 || y1 != 2) {
            System.out.println("testRectangleWrongPoints: Wrong lower left point! ");
        }

        if (x2 !=3 || y2 != 4) {
            System.out.println("testRectangleWrongPoints: Wrong upper right point!");
        }
    }

    //First Point Test
    public static void testDefaultPoint() {
        Point p = new Point();
        double x = p.getX();
        double y = p.getY();

        if (x != 0) {
            System.out.println("testPoint: Wrong X!");
        }
        if (y != 0) {
            System.out.println("testPoint: Wrong Y!");
        }

    }

    //Second Point Test
    public static void testPointDistance() {
        Point p = new Point(1, 1 );
        double dist;
        dist = p.distance(new Point(4, 5));
        if (dist != 5) {
            System.out.println("testPointFromOrigin: Wrong distance! Answer should be 5. Incorrect result is " + dist);
        }
    }

    //Third Point Test
    public static void testPointFromOrigin() {
        Point p = new Point(3, 4 );
        double dist;
        dist = p.distanceFromOrigin();
        if (dist != 5) {
            System.out.println("testPointFromOrigin: Wrong distance! Answer should be 5. Incorrect result is " + dist);
        }
    }

    //Fourth Point Test
    public static void testPoint() {
        Point p = new Point(1, 2);
        double x = p.getX();
        double y = p.getY();

        if (x != 1) {
            System.out.println("testPoint: Wrong X!");
        }
        if (y != 2) {
            System.out.println("testPoint: Wrong Y!");
        }

    }

    //Fifth Point Test
    public static void testPointCopy() {
        Point p = new Point(1, 2);
        Point q = new Point(p);
        double x = q.getX();
        double y = q.getY();

        if (x != 1) {
            System.out.println("testPointCopy: Failed to copy X!");
        }
        if (y != 2) {
            System.out.println("testPointCopy: Failed to copy Y!");
        }
    }


    //Second Rectangle Test
    public static void testRectWidth() {
        Rectangle rect = new Rectangle(1, 1, 4, 4);
        double width = rect.width();
        if (width != 3) {
            System.out.println("testRectWidth: Wrong width! Incorrect Result is " + width);
        }
    }

    //Third Rectangle Test
    public static void testRectHeight() {
        Rectangle rect = new Rectangle(1, 1, 4, 4);
        double height = rect.height();
        if (height != 3) {
            System.out.println("testRectHeight: Wrong height! Incorrect Result is " + height);
        }
    }

    //Fourth Rectangle Test
    public static void testRectPerimeter() {
        Rectangle rect = new Rectangle(1, 1, 4, 4);
        double perimeter = rect.perimeter();
        if (perimeter != 12) {
            System.out.println("testAreaPerimeter: Wrong Perimeter! Incorrect Result is " + perimeter);
        }
    }

    //Fifth Rectangle Test
    public static void testRectArea() {
        Rectangle rect = new Rectangle(1, 1, 4, 4);
        double area = rect.area();
        if (area != 9) {
            System.out.println("testRectAreaPerimeter: Wong area! Incorrect Result is " + area);
        }
    }

    //Sixth Rectangle Test
    public static void testRectDistOrigin() {
        Rectangle rect = new Rectangle(3, 4, 5, 5);
        double dist = rect.distanceFromOrigin();
        if (dist != 5) {
            System.out.println("testRectDistOrigin: Wong area! Incorrect Result is " + dist);
        }
    }

    //Seventh Rectangle Test
    public static void testRectInbounds() {
        Rectangle rect = new Rectangle(3, 4, 6, 6);
        boolean in = rect.inBounds(4, 5);
        if (!in) {
            System.out.println("testRectInbounds: Wrong answer, point should be inbounds!");
        }
    }

    //Eighth Rectangle Test
    public static void testRectOutbounds() {
        Rectangle rect = new Rectangle(3, 4, 6, 6);
        boolean in = rect.inBounds(7, 7);
        if (in) {
            System.out.println("testRectInbounds: Wrong answer, point should be outbounds!");
        }
    }

    //Ninth Rectangle Test
    public static void testDefaultRectangleWrongPoints() {
        Rectangle rect = new Rectangle();
        double x1 = rect.getLowerLeftX();
        double y1 = rect.getLowerLeftY();
        double x2 = rect.getUpperRightX();
        double y2 = rect.getUpperRightY();

        if (x1 != 0 || y1 != 0) {
            System.out.println("testDefaultRectangleWrongPoints: Wrong lower left point! ");
        }

        if (x2 !=1 || y2 != 1) {
            System.out.println("testDefaultRectangleWrongPoints: Wrong upper right point!");
        }
    }

    //First Circle Test
    public static void testCircleInbounds() {
        Circle c = new Circle(5,5,5);
        boolean in = c.inBounds(6,6);
        if (!in) {
            System.out.println("testCircleInbounds: Wrong answer, point should be inbounds!");
        }
    }

    //Second Circle Test
    public static void testCircleOutbounds() {
        Circle c = new Circle(5,5,5);
        boolean in = c.inBounds(11,9);
        if (in) {
            System.out.println("testCircleOutbounds: Wrong answer, point should be outbounds!");
        }
    }

    //Third Circle Test
    public static void testCircleDistOrigin() {
        Circle c = new Circle(3,4,5);
        double dist = c.distanceFromOrigin();
        if (dist != 5) {
            System.out.println("testCircleDistOrigin: Wrong answer! Incorrect Result is " + dist);
        }
    }

    //Fourth Circle Test
    public static void testCircleArea() {
        Circle c = new Circle(3,4,1.78);
        double area = c.area();
        if (area != 9.953822163633902) {
            System.out.println("testCircleArea: Wrong area! Incorrect Result is " + area);
        }
    }

    //Fifth Circle Test
    public static void testCirclePerimeter() {
        Circle c = new Circle(3,4,1.59);
        double perimeter = c.perimeter();
        if (perimeter != 9.990264638415542) {
            System.out.println("testCirclePerimeter: Wrong area! Incorrect Result is " + perimeter);
        }
    }

    //Sixth Circle Test
    public static void testCircle() {
        Circle c = new Circle(6,7,8);
        double x = c.getCenterX();
        double y = c.getCenterY();
        double radius = c.getRadius();
        if (x != 6) {
            System.out.println("testCircle: Wrong centerX! Answer should be 6. Incorrect Result is " + x);
        }
        if (y != 7) {
            System.out.println("testCircle: Wrong centerY! Answer should be 7. Incorrect Result is " + y);
        }
        if (radius != 8) {
            System.out.println("testCircle: Wrong radius! Answer should be 8. Incorrect Result is " + radius);
        }

    }

    //Seventh Circle Test
    public static void testCircleDiameter() {
        Circle c = new Circle(3,4,2);
        double diameter = c.diameter();
        if (diameter != 4) {
            System.out.println("testCircleDiameter: Wrong Diameter! Incorrect Result is " + diameter);
        }
    }

    public static void main(String[] args) {
        testRectangleWrongPoints();
        testDefaultPoint();
        testPointDistance();
        testPointFromOrigin();
        testPoint();
        testPointCopy();
        testRectWidth();
        testRectHeight();
        testRectPerimeter();
        testRectArea();
        testRectDistOrigin();
        testRectInbounds();
        testRectOutbounds();
        testDefaultRectangleWrongPoints();
        testCircleInbounds();
        testCircleOutbounds();
        testCircleDistOrigin();
        testCircleArea();
        testCirclePerimeter();
        testCircle();
        testCircleDiameter();
    }
}
