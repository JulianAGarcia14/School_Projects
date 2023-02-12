package oop.jgarcia.hw9.one;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

public class Server {
    private int port;
    private ArrayList<ClientThread> clients;
    private ArrayList<String> connections;

    private void acceptClients(ServerSocket server_socket) {
        /* Listen for new clients over the lifetime of the server */

        while (true) {
            try {
                // For Loop for iterating ArrayList
                for (int i = 0; i < clients.size(); i++) {
                    if(clients.get(i).getClient().getInputStream().read() == -1) {
                        clients.remove(i);
                    }
                }
                /* Accept new connection from the client */
                Socket client = server_socket.accept();
                System.out.println("Accepted new connection from: " + client.getRemoteSocketAddress());
                ClientThread client_thread = new ClientThread(this, client);
                /* Each client is running in the individual thread */
                Thread new_client = new Thread(client_thread);
                new_client.start();
                /* Put the thread in the ArrayList */
                clients.add(client_thread);

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
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a port number: ");
        port = scan.nextInt();
        scan.close();
        Server server = new Server(port);
    }
}
