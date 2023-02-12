package oop.jgarcia;


import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.*;
import java.net.Socket;
import java.net.URL;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.net.ServerSocket;
import java.net.Socket;



/**
 * Draws a 18x18 GomokuBoard with a mouselistener that draws plays by parsing what the server sends to all clients
 * @author Julian Garcia
 * @version Final Project, Option 1
 * @bugs First move always disregarded
 */
public class GomokuBoard extends JComponent implements Runnable {
    private Stone[][] stones;
    private GoPlayer ai;
    private int blackScore;
    private int whiteScore;
    private boolean gameOver;
    private boolean isBlackTurn;
    private boolean ready;
    private Server server;
    private Client client;


    public int getBlackScore() {
        return blackScore;
    }

    public int getWhiteScore() {
        return whiteScore;
    }

    public boolean isGameOver() {
        return gameOver;
    }

    public GomokuBoard(GoPlayer play) {
        super();
        this.ai = play;
        PlayHandler p = new PlayHandler();
        addMouseListener(p);
        setPreferredSize(new Dimension(720, 720));
        this.blackScore = 0;
        this.whiteScore = 0;
        this.gameOver = false;
        this.ready = false;

        this.isBlackTurn = true;

        this.stones = new Stone[19][19];
        for (int i = 0; i < stones.length; i++) {
            for (int j = 0; j < stones[i].length; j++) {
                this.stones[i][j] = Stone.EMPTY;

            }
        }

    }

    public void setReady(boolean ready) {
        this.ready = ready;
    }

    public void setServer(Server s) {
        this.server = s;
    }


    public void setClient(Client c) {
        this.client = c;
    }

    /**
     * Adds a new black play to the stones matrix
     * @param i x coordinate of black play
     * @param j y coordinate of black play
     * @return true if valid placement, false if not
     */
    public boolean playBlack(int i, int j) {
        if(this.stones[i][j] == Stone.EMPTY && i < 19 && j < 19 && !gameOver && isBlackTurn) {
            this.stones[i][j] = Stone.BLACK;
            this.isBlackTurn = false;
            repaint();
            return true;
        }
        return false;
    }

    /**
     * Adds a new white play to the stones matrix
     * @param i x coordinate of black play
     * @param j y coordinate of black play
     * @return true if valid placement, false if not
    */
    public boolean playWhite(int i, int j) {
        if(this.stones[i][j] == Stone.EMPTY && i < 19 && j < 19 && !gameOver && !isBlackTurn) {
            this.stones[i][j] = Stone.WHITE;
            this.isBlackTurn = true;
            repaint();
            return true;
        }
        return false;
    }

    /**
     * Resets the board and game
     */
    public void resetGame() {
        for (int i = 0; i < stones.length; i++) {
            for (int j = 0; j < stones[i].length; j++) {
                this.stones[i][j] = Stone.EMPTY;

            }
        }
        this.gameOver = false;
        repaint();
    }


    /**
     * Draws the Gomoku Board by drawing an 18x18 grid of 35x35 rectangles
     * Also draws black/white circles over the board dependent on the stones array
     * @param gfx canvas to draw over
     */
    @Override
    public void paintComponent(Graphics gfx) {
        super.paintComponent(gfx);

        URL imageurl = getClass().getResource("/resources/bamboo.jpg");
        //Image myPicture = Toolkit.getDefaultToolkit().getImage(imageurl);
        Image image = new ImageIcon(imageurl).getImage();

        /*BufferedImage bg;
        try {
            bg = ImageIO.read(new File("/resources/bamboo.jpg"));
            gfx.drawImage(bg, 0, 0, null);
        } catch (IOException e) {
            e.printStackTrace();
        }*/
        gfx.drawImage(image, 0, 0, null);

        Graphics2D canvas = (Graphics2D) gfx;
        Rectangle rect = new Rectangle(35, 35);
        DrawShape shape = new DrawShape();
        rect.move(45, 45);
        //shape.drawRectangle(canvas, rect, Color.BLACK);
        int i = 0;
        int j = 0;
        while (i < 18) {
            while (j < 18) {
                shape.drawRectangle(canvas, rect, Color.BLACK);
                rect.move(0, 35);
                j++;
            }
            j = 0;
            rect.move(35, -630);
            i++;
        }



        for (i = 0; i < stones.length; i++) {
            for (j = 0; j < stones[i].length; j++) {
                if(stones[i][j] != Stone.EMPTY) {
                    Point p = new Point(0, 0);
                    Circle circle = new Circle(p, 16);
                    circle.move(45 + i*35, 45 + j*35);
                    shape.drawCircle(canvas, circle, Stone.getColor(stones[i][j]));

                }
            }
        }

    }


    /**
     * Thread constantly runs and gets move from other player by waiting for
     * coordinates to be printed to system.out, does this by changing standard out
     * to a stream that will capture whatever strings given through input.
     */
    public void run() {


        while(true) {

                PrintStream old = System.out;
                ByteArrayOutputStream baos = new ByteArrayOutputStream();
                //System.out.println(baos.size());
                PrintStream ps = new PrintStream(baos);
                System.setOut(ps);
                // Create a stream to hold the output
                while(baos.size() == 0) {
                    try {
                        Thread.sleep(100);//10000ms = 10s
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                // IMPORTANT: Save the old System.out!
                //PrintStream old = System.out;
                // Tell Java to use your special stream

                // Print some output: goes to your special stream
                // Put things back
                System.out.flush();
                System.setOut(old);

                String[] points = baos.toString().trim().split(",", 2);
                //System.out.println("Here: " + baos.toString());
                System.out.println(points[0]);
                //System.out.println(points[1]);
                // Show what happened
                // String xline[] = points[0].split("\\r?\\n");
                String xline[] = points[0].split("\\r?\\n");
                String yline[] = points[1].split("\\r?\\n");
                //System.out.println(xline[0]);
                int x = Integer.valueOf(xline[0].trim());
                int y = Integer.valueOf(yline[0].trim());

                playWhite(x, y);
                Stone s = ai.checkWinner(stones);
                if (s == Stone.WHITE) {
                    whiteScore++;
                    gameOver = true;
                }


        }
    }

    private class PlayHandler extends MouseAdapter {
        /**
         * Places player stones down, only does black as white will always be the other players stone
         * @param m mouse click event
         */
        @Override
        public void mouseClicked(MouseEvent m) {
            if (ready) {
                int x = (int) Math.floor((m.getX() - 27.5) / 35.0);
                int y = (int) Math.floor((m.getY() - 27.5) / 35.0);
                boolean playB = playBlack(x, y);
                if (playB == true) {
                    Stone s = ai.checkWinner(stones);
                    if (s == Stone.BLACK) {
                        blackScore++;
                        gameOver = true;
                    }
                    String xx = String.valueOf(x);
                    String yy = String.valueOf(y);
                    String turn = xx + "," + yy;

                    client.collectCoordinates(turn);
                }

                //System.out.println("This code is running in a thread");


            /*else{
                playWhite(x, y);
                Stone s = ai.checkWinner(stones);
                if(s == Stone.WHITE) {
                    whiteScore++;
                    gameOver = true;
                }
            }*/

                //Scanner scan = new Scanner(System.in);
            }

        }
    }

}

