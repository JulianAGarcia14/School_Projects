package oop.jgarcia;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Server class, also determines if we have two players connected
 * @author Julian Garcia
 * @version Final Project, Option 1
 */
public class Server {
    private int port;
    private ArrayList<ClientThread> clients;

    /**
     * Accepts new clients and determines if there are enough clients to play
     */
    private void acceptClients(ServerSocket server_socket) {
        /* Listen for new clients over the lifetime of the server */
        while (true) {
            try {
                /* Accept new connection from the client */
                Socket client = server_socket.accept();
                System.out.println("Accepted new connection from: " + client.getRemoteSocketAddress());
                ClientThread client_thread = new ClientThread(this, client);
                /* Each client is running in the individual thread */
                Thread new_client = new Thread(client_thread);
                new_client.start();
                /* Put the thread in the ArrayList */
                clients.add(client_thread);

                /*Message that game is ready when more than one player available*/
                if(clients.size() % 4 == 0) {
                    client_thread.gameReady();
                }

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }


    public Server(int port) {
        /* Initialize the fields*/
        this.port = port;
        clients = new ArrayList<ClientThread>();
        /* Begin the server socket */
        ServerSocket server_socket = null;
        try {
            server_socket = new ServerSocket(port);
            /* Begin accepting clients */
            acceptClients(server_socket);
        } catch (IOException e) {
            System.out.println("Failed to start the server on port: " + port);
            e.printStackTrace();
        }
    }

    /* Getter for all clients */
    public ArrayList<ClientThread> getClients() {
        return clients;
    }

    public static void main(String[] args) {
        int port;
        //Scanner scan = new Scanner(System.in);
        //System.out.print("Enter a port number: ");
        //port = scan.nextInt();
        port = 8080;
        //scan.close();
        Server server = new Server(port);
    }
}
