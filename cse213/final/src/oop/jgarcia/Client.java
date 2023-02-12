package oop.jgarcia;

import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

/**
 * Client class, added a method to send coordinates of stone play
 * @author Julian Garcia
 * @version Final Project, Option 1
 */
public class Client {
    private int port;
    private String name;
    private ServerThread server_thread;
    public Client(int port, String name) {
        this.port = port;
        this.name = name;
        startClient();
    }

    /**
     * Sends a message of the coordinates
     * @param coordinates string containing coordinates
     */
    public void collectCoordinates(String coordinates) {
        this.server_thread.newMessage(coordinates);
    }

    private void startClient() {
        try {
            /* Establish a connection with the server */
            Socket client = new Socket("localhost", port);
            Thread.sleep(1000);
            /* Start a server thread */
            this.server_thread = new ServerThread(client, name);
            Thread server = new Thread(server_thread);
            server.start();
            /* Send new messages to the server */
            //Scanner scan = new Scanner(System.in);

            /*while (server.isAlive()) {
                if (scan.hasNextLine()) {
                    server_thread.newMessage(scan.nextLine());
                    System.out.println("hello?");
                }
            }*/
            //server_thread.newMessage(coordinates);

        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

   /* public static void main(String[] args) { */
        /* Choose a port to connect to */
        /*   int port;
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a port number: ");
        port = Integer.parseInt(scan.nextLine());
        /* Get the client's user name */
        /*String name = null;
        //System.out.print("Enter a username: ");
        //name = scan.nextLine();
        name = "player"; */
        /* Create the client with the port */
        //Client client = new Client(port, name);
    //}
}
