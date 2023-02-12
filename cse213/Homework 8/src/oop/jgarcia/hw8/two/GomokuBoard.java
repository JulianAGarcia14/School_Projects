package oop.jgarcia.hw8.two;


import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;



/**
 * Draws a 18x18 GomokuBoard with a mouslistener that draws plays
 * @author Julian Garcia
 * @version HW 8, #2
 */
public class GomokuBoard extends JComponent {
    private Stone[][] stones;
    private GoPlayer ai;
    private int blackScore;
    private int whiteScore;
    private boolean gameOver;

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
        this.stones = new Stone[19][19];
        for (int i = 0; i < stones.length; i++) {
            for (int j = 0; j < stones[i].length; j++) {
                this.stones[i][j] = Stone.EMPTY;

            }
        }
    }

    /**
     * Adds a new black play to the stones matrix
     * @param i x coordinate of black play
     * @param j y coordinate of black play
     * @return true if valid placement, false if not
     */
    public boolean playBlack(int i, int j) {
        if(this.stones[i][j] == Stone.EMPTY && i < 19 && j < 19 && !gameOver) {
            this.stones[i][j] = Stone.BLACK;
            repaint();
            return true;
        }
        return false;
    }

    /**
     * Adds a new white play to the stones matrix by calling ai
     * @return true if valid placement, false if not
     */
    public boolean playWhite(){
        int[] i;
        i = ai.getMove(stones);
        if(this.stones[i[1]][i[0]] == Stone.EMPTY && i[0] < 19 && i[1] < 19 && !gameOver) {
            this.stones[i[1]][i[0]] = Stone.WHITE;
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

        BufferedImage bg;
        try {
            bg = ImageIO.read(new File("bamboo.jpg"));
            gfx.drawImage(bg, 0, 0, null);
        } catch (IOException e) {
            e.printStackTrace();
        }
        Graphics2D canvas = (Graphics2D) gfx;
        oop.jgarcia.hw8.two.Rectangle rect = new Rectangle(35, 35);
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





    private class PlayHandler extends MouseAdapter {
        /**
         * Checks for winner on each mouse click as well as determine where new stones are placed
         * on every click.
         * @param m mouse click event
         */
        @Override
        public void mouseClicked(MouseEvent m) {
            int x = (int) Math.floor((m.getX() -27.5) /35.0);
            int y = (int) Math.floor((m.getY() -27.5) /35.0);
            boolean playB = playBlack(x, y);
            if(playB == true) {
                Stone s = ai.checkWinner(stones);
                if(s == Stone.BLACK) {
                    blackScore++;
                    gameOver = true;
                } else{
                    playWhite();
                    s = ai.checkWinner(stones);
                    if(s == Stone.WHITE) {
                        whiteScore++;
                        gameOver = true;
                    }
                }
            }
        }
    }

}
