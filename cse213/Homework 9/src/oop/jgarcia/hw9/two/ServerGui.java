package oop.jgarcia.hw9.two;

import oop.jgarcia.hw9.one.Client;
import oop.jgarcia.hw9.one.ClientThread;
import oop.jgarcia.hw9.one.Server;
import oop.jgarcia.hw9.one.ServerThread;

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

public class ServerGui extends JFrame{



    public ServerGui() {
        // Parent constructor sets the window title
        super("Server");
        setLayout(new BorderLayout());
        // Exit on close
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setPreferredSize(new Dimension(720, 600));

        Scanner scn = new Scanner(System.in);
        System.out.println("Enter port to start server!");
        int in = scn.nextInt();


        JTextArea textArea = new JTextArea ();
        JScrollPane scroll = new JScrollPane (textArea,
                JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        add(scroll);

        textArea.setEditable(false);


        String serverName = "My Server";
        JLabel serverLabel = new JLabel(serverName, SwingConstants.CENTER);
        serverLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 24));
        add(serverLabel, BorderLayout.NORTH);
        pack();




        Thread thread = new Thread(){
            public void run(){
                Server server = new Server(in);
                ArrayList<ClientThread> clients = server.getClients();
                int sizeList = clients.size();

                while (true) {
                    System.out.println(clients.size());
                    System.out.println(sizeList);
                    if(clients.size() > sizeList) {
                        textArea.setText("");

                        // For Loop for iterating ArrayList
                        for (int i = 0; i < clients.size(); i++) {
                            textArea.append("hello");
                            textArea.append(clients.get(i).toString());
                        }
                        sizeList = clients.size();
                    }
                    }
                }
        };
        thread.start();

       /* ActionListener al = new ActionListener() {
            public void actionPerformed(ActionEvent event) {

            }
        };

        Timer t = new Timer(1000, al);
        t.start();
        */
        pack();

    }

    public static void main(String[] args) {
        // Create a GUI window

        ServerGui window = new ServerGui();
        // Show the window - slightly fancier than `window.setVisible(true)`
        EventQueue.invokeLater(() -> window.setVisible(true));


    }

}
