package oop.jgarcia;

/**
 * Interface for GomokuAI
 * @author Julian Garcia
 * @version HW 8, #2
 */
public interface GoPlayer {
    public Stone checkWinner(Stone[][] s);
    public int[] getMove(Stone[][] s);
}
