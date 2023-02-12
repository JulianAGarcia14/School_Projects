package oop.jgarcia;


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Creates a GomokuFrame and implements a Gomoku Board with labels for scores
 * @author Julian Garcia
 * @version HW 8, #2
 */
public class GomokuFrame extends JFrame {
    private GomokuBoard board;
    private JLabel blackScore;
    private JLabel whiteScore;

    public static boolean hostAvailabilityCheck() {
        try (Socket s = new Socket("localhost", 8080)) {
            System.out.println("Server Available");
            return true;
        } catch (IOException ex) {
            /* ignore */
        }
        System.out.println("No Server Available");
        return false;
    }

    public GomokuFrame() {
        // Parent constructor sets the window title
        super("GoBoard");
        GomokuAi ai = new GomokuAi();
        board = new GomokuBoard(ai);
        // Exit on close
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        blackScore = new JLabel("Black " + board.getBlackScore(), SwingConstants.CENTER);
        blackScore.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 24));

        whiteScore = new JLabel("White " + board.getBlackScore(), SwingConstants.CENTER);
        whiteScore.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 24));
        JPanel score = new JPanel();
        score.setLayout(new GridLayout(1,2));
        score.add(blackScore);
        pack();
        score.add(whiteScore);
        pack();

        add(score, BorderLayout.NORTH);
        pack();

        JButton newGame = new JButton("Reset Game");
        newGame.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(board.isGameOver()) {
                    board.resetGame();
                }
            }
        });
       // add(newGame, BorderLayout.SOUTH);
       // pack();

        JButton startGame = new JButton("Start Game");
        startGame.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                if(!hostAvailabilityCheck()) {
                    //Server server = new Server(8080);
                }
                Client client = new Client(8080, "Player");

                //////////////////////////////////////////////////////////
                PrintStream old = System.out;
                ByteArrayOutputStream baos = new ByteArrayOutputStream();
                //System.out.println(baos.size());
                PrintStream ps = new PrintStream(baos);
                System.setOut(ps);
                // Create a stream to hold the output
                while(baos.size() == 0) {
                    try {
                        Thread.sleep(100);//10000ms = 10s
                    } catch (InterruptedException c) {
                        c.printStackTrace();
                    }
                }
                System.out.flush();
                System.setOut(old);
                //////////////////////////////////////////////////
                board.setReady(true);
                board.setClient(client);
                Thread t = new Thread(board);
                t.start();


                //board.setReady(true); CHANGE THISSSSS
            }
        });
        //add(startGame, BorderLayout.SOUTH);
        //pack();

        JPanel game = new JPanel(new FlowLayout(FlowLayout.CENTER));
        game.setLayout(new GridLayout(1,2));
        game.add(startGame);
        pack();
        game.add(newGame);
        pack();
        add(game, BorderLayout.SOUTH);
        pack();

        MouseAdapter al = new MouseAdapter() {
            public void mouseClicked(MouseEvent event) {
                    blackScore.setText("Black " + board.getBlackScore());
                    whiteScore.setText("White " + board.getWhiteScore());

            }
        };
        board.addMouseListener(al);

        add(board);
        pack();

    }

    public static void main(String[] args) throws IOException {
        // Create a GUI window
        GomokuFrame window = new GomokuFrame();
        // Show the window - slightly fancier than `window.setVisible(true)`
        EventQueue.invokeLater(() -> window.setVisible(true));
    }

}
