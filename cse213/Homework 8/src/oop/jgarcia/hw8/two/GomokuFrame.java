package oop.jgarcia.hw8.two;

import oop.jgarcia.hw8.one.ClockFace;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.util.TimeZone;

/**
 * Creates a GomokuFrame and implements a Gomoku Board with labels for scores
 * @author Julian Garcia
 * @version HW 8, #2
 */
public class GomokuFrame extends JFrame {
    private GomokuBoard board;
    private JLabel blackScore;
    private JLabel whiteScore;

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

        JButton newGame = new JButton("New Game");
        newGame.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                board.resetGame();
            }
        });
        add(newGame, BorderLayout.SOUTH);
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
