package oop.jgarcia;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.LinkedList;
import java.util.Scanner;
/**
 * ClientThread, added a function to print to clients once game is ready (this is used to start the game)
 * @author Julian Garcia
 * @version Final Project, Option 1
 */
public class ClientThread implements Runnable {
    private Server server;
    private Socket client;
    private PrintWriter out;

    public ClientThread(Server server, Socket client) {
        this.server = server;
        this.client = client;
    }

    /**
     * Simply prints game is ready to server and clients
     */
    public void gameReady() {
        try {
            this.out = new PrintWriter(client.getOutputStream(), false);
            Scanner in = new Scanner("Game is ready");
            System.out.println("Game is ready");
            /* Write input to all other clients*/
                if (in.hasNextLine()) {
                    String input = in.nextLine();
                    for (ClientThread c : server.getClients()) {
                        PrintWriter cout = c.getWriter();
                        if (cout != null) {
                            cout.write(input + "\r\n");
                            cout.flush();
                        }
                    }
                }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public PrintWriter getWriter() {
        return out;
    }

    public void run() {
        try {
            this.out = new PrintWriter(client.getOutputStream(), false);
            Scanner in = new Scanner(client.getInputStream());
            /* Write input to all other clients*/
            while (!client.isClosed()) {
                if (in.hasNextLine()) {
                    String input = in.nextLine();
                    for (ClientThread c : server.getClients()) {
                        PrintWriter cout = c.getWriter();
                        if (cout != null) {
                            cout.write(input + "\r\n");
                            cout.flush();
                        }
                    }
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
