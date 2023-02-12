package oop.jgarcia.hw7.one;

import java.awt.*;


/**
 * Contains functions to draw different shapes
 * @author Julian Garcia
 * @version HW 7, #1
 */
public class DrawShape {

    public void drawPoint(Graphics2D gfx, Point p, Color col) {

        Graphics2D canvas = gfx;
        Color old = canvas.getColor();
        canvas.setStroke(new BasicStroke(1));
        canvas.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);

        // Draw a point
        canvas.setColor(col);
        canvas.drawOval((int) p.getX(), (int) p.getY(), 1, 1);
        canvas.setColor(old);

    }

    public void drawRectangle(Graphics2D gfx, Rectangle r, Color col) {
        Graphics2D canvas = gfx;
        Color old = canvas.getColor();
        canvas.setStroke(new BasicStroke(1));
        canvas.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);
        int x = (int) ((r.getLowerLeft().getX() + r.getUpperRight().getX()) / 2);
        int y =  (int) ((r.getLowerLeft().getY() + r.getUpperRight().getY()) / 2);
        //int x = (int) r.getLowerLeft().getX();
        //int y = (int) r.getLowerLeft().getY();
        canvas.setColor(col);
        canvas.drawRect(x, y, (int) r.width(), (int) r.height());
        canvas.setColor(old);
    }

    public void drawCircle(Graphics2D gfx, Circle c, Color col) {
        Graphics2D canvas = gfx;
        Color old = canvas.getColor();
        canvas.setStroke(new BasicStroke(2));
        canvas.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);
        Rectangle box = c.getBoundingBox();
        int x = (int) box.getLowerLeft().getX();
        int y = (int) box.getLowerLeft().getY();

        // Draw a circle
        canvas.setColor(col);
        canvas.fillOval(x, y, (int) c.width(), (int) c.height());
        canvas.setColor(old);
    }
}
