package oop.jgarcia.hw9.one;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class ClientThread implements Runnable {
    private Server server;
    private Socket client;
    private PrintWriter out;
    public ClientThread(Server server, Socket client) {
        this.server = server;
        this.client = client;
    }
    public PrintWriter getWriter() {
        return out;
    }

    public Socket getClient() {
        return client;
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
