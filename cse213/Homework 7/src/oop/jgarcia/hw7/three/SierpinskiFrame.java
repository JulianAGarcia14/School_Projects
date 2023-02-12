package oop.jgarcia.hw7.three;

import oop.jgarcia.hw7.two.ClockFace;
import oop.jgarcia.hw7.two.ClockFrame;

import javax.swing.*;
import java.awt.*;
import java.util.TimeZone;

import java.awt.*;
import javax.swing.*;
import java.awt.EventQueue;
import java.time.LocalDateTime;
import java.util.TimeZone;
import javax.swing.JFrame;

/**
 * Creates a frame for Sierpinski drawing from sierpinski.java
 * @author Julian Garcia
 * @version HW 7, #3
 */
public class SierpinskiFrame extends JFrame{
    public SierpinskiFrame() {
        // Parent constructor sets the window title
        super();
        // Exit on close
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setPreferredSize(new Dimension(600, 600));
        JPanel sier = new Sierpinski();
        add(sier);
        pack();
    }

    public static void main(String[] args) {
        // Create a GUI window
        SierpinskiFrame window = new SierpinskiFrame();
        // Show the window - slightly fancier than `window.setVisible(true)`
        EventQueue.invokeLater(() -> window.setVisible(true));
    }
}
