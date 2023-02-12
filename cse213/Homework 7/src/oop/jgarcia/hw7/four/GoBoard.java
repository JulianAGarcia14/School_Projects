package oop.jgarcia.hw7.four;
import oop.jgarcia.hw7.one.DrawShape;
import oop.jgarcia.hw7.one.Rectangle;
import oop.jgarcia.hw7.one.Circle;
import oop.jgarcia.hw7.one.Point;


import java.awt.*;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.EventQueue;
import java.awt.image.BufferedImage;
import java.io.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TimeZone;
import javax.swing.JFrame;
// import javax.swing.text.html.StyleSheet;
import java.util.Random;

/**
 * Creates a go board using JFrame and Jpanel
 * @author Julian Garcia
 * @version HW 7, #4
 */
public class GoBoard extends JComponent {
    private Color stones[][];

    public GoBoard() {
        super();
        setPreferredSize(new Dimension(720, 720));
        this.stones = new Color[19][19];
    }

    public GoBoard fromFile(String str) throws IOException {

        Scanner s = new Scanner(new FileReader(str)).useDelimiter(" |\\n");
        ArrayList<Integer> ii = new ArrayList<Integer>();
        ArrayList<Integer> jj = new ArrayList<Integer>();
        ArrayList<Color> col = new ArrayList<Color>();
        //StyleSheet ss = new StyleSheet;
        int i = 0;
        int a;
        char cc;
        while (s.hasNext()){
            if (i == 0) {
                if(s.next() == "B") {
                    col.add(Color.BLACK);
                } else {
                    col.add(Color.WHITE);
                }
                //Color c1 = ss.stringToColor(s.next());
                //col.add(c1);
                i++;
            } if (i == 1) {
                cc = s.next().charAt(0);
                if(cc < 'I') {
                    a = cc - 'A';
                    ii.add(a);
                } else if (cc == 'I') {
                    ii.add(-1);
                } else {
                    a = cc - 'A' - 1;
                    ii.add(a);
                }
                i++;
            } if (i == 2) {
                a = Integer.parseInt(s.next());
                jj.add(a);
                i = 0;
            }
        }
        s.close();
        GoBoard go = new GoBoard();
        int inc = 0;
        while (inc < 19) {
            if (ii.get(inc) != -1) {
                go.addStone(ii.get(inc), jj.get(inc), col.get(inc));
            }
            inc++;
        }

        return go;
    }

    public void addStone(int i, int j, Color col) {
        if(i < 19 & j < 19 ) {
            this.stones[i][j] = col;
        }
    }

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
        oop.jgarcia.hw7.one.Rectangle rect = new Rectangle(35, 35);
        rect.move(-720, -720);
        DrawShape shape = new DrawShape();
        int i = 0;
        int j = 0;
        while (i < 18) {
            while (j < 18) {
                shape.drawRectangle(canvas, rect, Color.BLACK);
                rect.move(0, -35);
                j++;
            }
            j = 0;
            rect.move(35, 0);
            i++;
        }



        i = 0;
        j = 0;
        Point p = new Point(0, 0);
        Circle circle = new Circle(p, 16);
        while(i < 19) {
            if(stones[i][j] != null) {
                shape.drawCircle(canvas, circle, stones[i][j]);
                circle.move(45 + i*35, 45 + j*35);
            }
            i++;
            j++;
        }


    }
}
