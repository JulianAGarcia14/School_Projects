package oop.jgarcia.hw7.four;

import oop.jgarcia.hw7.two.ClockFace;
import oop.jgarcia.hw7.two.ClockFrame;

import java.awt.*;
import javax.swing.*;
import java.awt.EventQueue;
import java.io.IOException;
import java.time.LocalDateTime;
import java.util.TimeZone;
import javax.swing.JFrame;

/**
 * Creates a go Board and implements GoBoard.java
 * @author Julian Garcia
 * @version HW 7, #4
 */
public class GoFrame extends JFrame {
    public GoFrame(GoBoard Go) {
        // Parent constructor sets the window title
        super("GoBoard");
        // Exit on close
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        add(Go);

        pack();
    }

    public static void main(String[] args) throws IOException {
        // Create a GUI window
        GoBoard Go = new GoBoard();
        Go = Go.fromFile("Stones.txt");
        GoFrame window = new GoFrame(Go);
        // Show the window - slightly fancier than `window.setVisible(true)`
        EventQueue.invokeLater(() -> window.setVisible(true));
    }

}
