package oop.jgarcia.hw7.three;

import oop.jgarcia.hw7.one.DrawShape;
import oop.jgarcia.hw7.one.Point;
import oop.jgarcia.hw7.two.ClockFace;

import java.awt.*;
import javax.swing.*;
import java.awt.EventQueue;
import java.time.LocalDateTime;
import java.util.TimeZone;
import javax.swing.JFrame;
import java.util.Random;

/**
 * Implements an algorithm to draw a fractal with lines which have colors dependent on distance between points
 * @author Julian Garcia
 * @version HW 7, #3
 */
public class Sierpinski extends JPanel {
    public Sierpinski() {
        // Parent constructor sets the window title
        super();
        setPreferredSize(new Dimension(500, 500));
        setBackground(Color.BLACK);
    }

    public Color triangleColor(Point one, Point two, Point three, Point four) {

        double first = one.distance(two);
        double second = one.distance(three);
        double third = one.distance(four);
        double length = Math.max(first, second);
        length = Math.max(length, third);

        double r = 255 * ((length - one.distance(two)) / length);
        double g = 255 * ((length - one.distance(three)) / length);
        double b = 255 * ((length - one.distance(four)) / length);
        Color Col = new Color((int) r,(int) g, (int) b);
        return Col;
    }

    @Override
    public void paintComponent(Graphics gfx) {
        super.paintComponent(gfx);
        Graphics2D canvas = (Graphics2D) gfx;
        Point R = new Point(250, 77);
        Point G = new Point(50, 423);
        Point B = new Point(450, 423);
        Point a[] = {R, G, B};
        Point x = G;
        Point target;
        Point midPoint;
        int i = 0;
        Random rand = new Random();
        int choice;
        double xx;
        double yy;
        Color col;
        DrawShape shape = new DrawShape();
        while (i < 100) {
            choice = rand.nextInt(3);
            if(choice == 1) {
                target = R;
                xx = (x.getX() + target.getX())/2;
                yy = (x.getY() + target.getY())/2;
                midPoint = new Point(xx, yy);
                x = midPoint;
                col = triangleColor(x, R, G, B);
                shape.drawPoint(canvas, x, col);
            } else if(choice == 2) {
                target = G;
                xx = (x.getX() + target.getX())/2;
                yy = (x.getY() + target.getY())/2;
                midPoint = new Point(xx, yy);
                x = midPoint;
                col = triangleColor(x, R, G, B);
                shape.drawPoint(canvas, x, col);
            } else if(choice == 3) {
                target = B;
                xx = (x.getX() + target.getX())/2;
                yy = (x.getY() + target.getY())/2;
                midPoint = new Point(xx, yy);
                x = midPoint;
                col = triangleColor(x, R, G, B);
                shape.drawPoint(canvas, x, col);
            }
            i++;
        }

    }
}
