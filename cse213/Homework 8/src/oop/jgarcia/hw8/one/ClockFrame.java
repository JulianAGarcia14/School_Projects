package oop.jgarcia.hw8.one;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.TimeZone;

/**
 * Creates a clock frame which can switch between three different timezones, and updates time live
 * @author Julian Garcia
 * @version HW 8, #2
 */
public class ClockFrame extends JFrame{
    public ClockFrame() {
        // Parent constructor sets the window title
        super("Clock");
        setLayout(new BorderLayout());
        // Exit on close
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        String tzName = TimeZone.getDefault().getDisplayName();
        JLabel tzLabel = new JLabel(tzName, SwingConstants.CENTER);
        tzLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 24));
        ClockFace clock = new ClockFace();
        add(tzLabel, BorderLayout.NORTH);
        pack();
        add(clock);


        JPanel zone = new JPanel();
        JButton america = new JButton("America/Denver");
        JButton europe = new JButton("Europe/London");
        JButton asia = new JButton("Asia/Taipei");

        america.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String tzName = "America/Denver";
                TimeZone id = TimeZone.getTimeZone("America/Denver");
                clock.setTimeZone(id);
                tzLabel.setText(tzName);
            }
        });

        europe.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String tzName = "Europe/London";
                TimeZone id = TimeZone.getTimeZone("Europe/London");
                clock.setTimeZone(id);
                tzLabel.setText(tzName);
            }
        });


        asia.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String tzName = "Asia/Taipei";
                TimeZone id = TimeZone.getTimeZone("Asia/Taipei");
                clock.setTimeZone(id);
                tzLabel.setText(tzName);
            }
        });

        zone.add(america);
        pack();
        zone.add(europe);
        pack();
        zone.add(asia);
        pack();

        add(zone, BorderLayout.SOUTH);
        pack();

        ActionListener al = new ActionListener() {
                public void actionPerformed(ActionEvent event) {
                    clock.tick();
            }
        };

        Timer t = new Timer(1000, al);
        t.start();
        pack();
    }

    public static void main(String[] args) {
        // Create a GUI window
        ClockFrame window = new ClockFrame();
        // Show the window - slightly fancier than `window.setVisible(true)`
        EventQueue.invokeLater(() -> window.setVisible(true));
    }
}
