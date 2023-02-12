package oop.jgarcia;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.LinkedList;
import java.util.Scanner;

public class ServerThread implements Runnable {
    private Socket client;
    private String name;
    private final LinkedList<String> messages;

    public void newMessage(String new_message) {
        synchronized (messages) {
            messages.push(new_message);
        }
    }


    public ServerThread(Socket client, String name) {
        this.client = client;
        this.name = name;
        messages = new LinkedList<String>();
    }

    public void run() {
        //System.out.println("Welcome " + name);
        try {
            /* Use Socket object to get input and output stream */
            PrintWriter out_stream = new PrintWriter(client.getOutputStream(), false);
            InputStream in_stream = client.getInputStream();
            Scanner in = new Scanner(in_stream);
            while (!client.isClosed()) {
                /* Get input from the client socket */
                if (in_stream.available() > 0) {
                    if (in.hasNextLine()) {
                        System.out.println(in.nextLine());
                    }
                }
                /* Send messages to the socket server */
                if (!messages.isEmpty()) {
                    String next = null;
                    synchronized (messages) {
                        next = messages.pop();
                    }
                    out_stream.println(next);
                    out_stream.flush();                }

            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
