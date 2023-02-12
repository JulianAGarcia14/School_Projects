package oop.jgarcia.hw7.two;

import java.awt.*;
import javax.swing.*;
import java.awt.EventQueue;
import java.time.LocalDateTime;
import java.util.TimeZone;
import javax.swing.JFrame;

/**
 * Creates a clock frame
 * @author Julian Garcia
 * @version HW 7, #2
 */
public class ClockFrame extends JFrame{
    public ClockFrame() {
        // Parent constructor sets the window title
        super("Clock");
        // Exit on close
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        String tzName = TimeZone.getDefault().getDisplayName();
        JLabel L = new JLabel(tzName, SwingConstants.CENTER);
        add(L);
        add(new ClockFace());

        pack();
    }

    public static void main(String[] args) {
        // Create a GUI window
        ClockFrame window = new ClockFrame();
        // Show the window - slightly fancier than `window.setVisible(true)`
        EventQueue.invokeLater(() -> window.setVisible(true));
    }
}
