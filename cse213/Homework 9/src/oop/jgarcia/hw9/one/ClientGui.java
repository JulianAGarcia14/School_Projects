package oop.jgarcia.hw9.one;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TimeZone;
import java.util.TimerTask;

public class ClientGui extends JFrame{

    boolean isStart = true;
    Client client;

    public ClientGui() {
        // Parent constructor sets the window title
        super("Client");
        setLayout(new BorderLayout());
        // Exit on close
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setPreferredSize(new Dimension(720, 600));

        Scanner scn = new Scanner(System.in);
        System.out.println("Enter name her to connect to server!");
        String in = scn.nextLine();
        client = new Client(8080, in);


        JTextArea textArea = new JTextArea ();
        JScrollPane scroll = new JScrollPane (textArea,
                JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        add(scroll);

        textArea.setEditable(false);


        String clientName = "My chat client";
        JLabel clientLabel = new JLabel(clientName, SwingConstants.CENTER);
        clientLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 24));
        add(clientLabel, BorderLayout.NORTH);
        pack();

        JPanel input = new JPanel();
        JButton submit = new JButton("Submit");
        JButton connect = new JButton("Connect");

        JTextField txtInput = new JTextField(20);

        submit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //textArea.append("More");

                    client.collectCoordinates(txtInput.getText());
                    txtInput.setText("");

                //input = txtInput.getText();   //receive input from text field
                //System.out.println(input);

            }
        });

        input.add(submit);
        pack();
        input.add(txtInput);
        pack();
        add(input, BorderLayout.SOUTH);
        pack();

        PrintStream old = System.out;
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        //System.out.println(baos.size());
        PrintStream ps = new PrintStream(baos);
        System.setOut(ps);
        // Create a stream to hold the output

        //System.out.flush();
        //System.setOut(old);


        ActionListener al = new ActionListener() {
            public void actionPerformed(ActionEvent event) {
                if(baos.size() != 0) {
                    String[] points = baos.toString().trim().split(" ", 2);


                    textArea.append(baos.toString());
                    System.out.flush();
                    baos.reset();
                }

                }
        };

        Timer t = new Timer(1000, al);
        t.start();
        /*
        Thread thread = new Thread(){
            public void run(){
                while (true) {
                    if (baos.size() != 0) {
                        textArea.append(baos.toString());
                        System.out.flush();
                    }
                }
            }
        };
        thread.start();

        */

        pack();

    }

    public static void main(String[] args) {
        // Create a GUI window

        ClientGui window = new ClientGui();
        // Show the window - slightly fancier than `window.setVisible(true)`
        EventQueue.invokeLater(() -> window.setVisible(true));


    }

}
