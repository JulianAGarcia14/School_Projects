package oop.jgarcia.hw8.one;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.time.LocalTime;
import java.util.TimeZone;


/**
 * Creates a clock face
 * @author Julian Garcia
 * @version HW 8, #2
 */
public class ClockFace extends JComponent{

    private int hour;
    private int minute;
    private int second;

    public int getHour() {
        return hour;
    }

    public int getMinute() {
        return minute;
    }

    public int getSecond() {
        return second;
    }

    public void setHour(int hour) {
        this.hour = hour;
    }

    public void setMinute(int minute) {
        this.minute = minute;
    }

    public void setSecond(int second) {
        this.second = second;
    }


    public ClockFace() {
        super();
        setPreferredSize(new Dimension(400, 400));
        LocalTime time = LocalTime.now();
        this.hour = time.getHour();
        this.minute = time.getMinute();
        this.second = time.getSecond();
    }

    public ClockFace(int hour, int minute, int second) {
        super();
        setPreferredSize(new Dimension(400, 400));
        LocalTime time = LocalTime.now();
        if(hour < 24 & hour >= 0) {
            this.hour = hour;
        } else {
            this.hour = time.getHour();
        }

        if(minute < 60 & minute >= 0) {
            this.minute = minute;
        } else {
            this.minute = time.getMinute();
        }

        if(second < 60 & second >= 0) {
            this.second = second;
        } else {
            this.second = time.getSecond();
        }


    }

    /**
     * Draws the actual clockface
     * @param gfx canvas to draw over
     */
    public void paintComponent(Graphics gfx) {
        BufferedImage bg;
        try {
            bg = ImageIO.read(new File("clock.jpg"));
            gfx.drawImage(bg, 0, 0, null);
        } catch (IOException e) {
            e.printStackTrace();
        }

        int rSec = 190;
        int rMin = 160;
        int rHour = 100;

        double thetaSec = ((Math.PI / 30) * this.second);
        double thetaMin = ((Math.PI / 30) * this.minute);
        double thetaHour = (Math.PI / 6) * (this.hour % 12) + (Math.PI / 360) * this.minute;


        Graphics2D canvas = (Graphics2D) gfx;
        double secX = 200 + rSec * Math.sin(thetaSec);
        double secY = 200 - rSec * Math.cos(thetaSec);
        double minX = 200 + rMin * Math.sin(thetaMin);
        double minY = 200 - rMin * Math.cos(thetaMin);
        double hourX = 200 + rHour * Math.sin(thetaHour);
        double hourY = 200 - rHour * Math.cos(thetaHour);

        canvas.setColor(Color.BLACK);
        canvas.setStroke(new BasicStroke(3));
        canvas.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);
        canvas.drawLine(200, 200, (int) hourX, (int) hourY);

        canvas.setStroke(new BasicStroke(2));
        canvas.drawLine(200, 200, (int) minX, (int) minY);

        canvas.setColor(Color.RED);
        canvas.setStroke(new BasicStroke(1));
        canvas.drawLine(200, 200, (int) secX, (int) secY);
    }

    /**
     * Updates time by one second, updates minutes and hours if needed
     */
    public void tick() {
        this.second++;
        if (this.second == 60) {
            this.minute++;
            this.second = 0;
            if (this.minute == 60) {
                this.hour++;
                this.minute = 60;
                if(this.hour == 60) {
                    this.hour = 0;
                }
            }
        }
        repaint();
    }

    /**
     * Sets default time zone to given time zone
     * @param t given time zone
     */
    public void setTimeZone(TimeZone t) {
        TimeZone old = TimeZone.getDefault();
        TimeZone.setDefault(t);
        this.second = LocalTime.now().getSecond();
        this.minute = LocalTime.now().getMinute();
        this.hour = LocalTime.now().getHour();
        repaint();
        TimeZone.setDefault(old);
    }
}
