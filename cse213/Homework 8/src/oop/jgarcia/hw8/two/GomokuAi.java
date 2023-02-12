package oop.jgarcia.hw8.two;

/**
 * Handles checking for if the game is won and determine Ai's next move
 * @author Julian Garcia
 * @version HW 8, #2
 */
public class GomokuAi implements GoPlayer {
    /**
     * Checks to see if game is won by looking for 5 in a row plays
     * @param s list of stone values to be evaluated
     * @return stone returns the color of the player that won or EMPTY if nobody has won yet
     */
    public Stone checkWinner(Stone[][] s){
        Stone[][] i = s;
        Stone row = checkRows(i);
        Stone column = checkColumns(i);
        Stone diagonal = checkMainDiagonal(i);
        Stone backDiagonal = checkCounterDiagonal(i);
        if (row != Stone.EMPTY) {
            return row;
        } else if (column != Stone.EMPTY) {
            return column;
        } else if (diagonal != Stone.EMPTY) {
            return diagonal;
        } else if (backDiagonal != Stone.EMPTY) {
            return backDiagonal;
        }
        return Stone.EMPTY;
    }

    /**
     * Determines the next move of the ai, simply finds first open space on board
     * @param s the list of current stones on the board
     * @return int[] a list containing the coordinates of the move
     */
    public int[] getMove(Stone[][] s){
        for (int i = 0; i < s.length; i++) {
            for (int j = 0; j < s[i].length; j++) {
                if (s[i][j] == Stone.EMPTY) {
                    int[] move = {j, i};
                    return move;
                }
            }
        }
        int[] incorrect = {-1};
        return incorrect;
    }

    /**
     * Checks rows of the board for 5 in a row
     * @param matrix a Stone matrix with current stones on the board
     * @return the enum value for the color which has the winning 5 in a row
     */
    private static Stone checkRows(Stone[][] matrix)
    {
        for (int row = 0; row < matrix.length; row++)
        {
            for (int col = 0; col < matrix[row].length - 4; col++)
            {
                Stone element = matrix[row][col];
                if (element == matrix[row][col + 1] &&
                        element == matrix[row][col + 2] &&
                        element == matrix[row][col + 3] &&
                        element == matrix[row][col + 4])
                {
                    return element;
                }
            }
        }
        return Stone.EMPTY;
    }

    /**
     * Checks columns of the board for 5 in a row
     * @param matrix a Stone matrix with current stones on the board
     * @return the enum value for the color which has the winning 5 in a row
     */
    private static Stone checkColumns(Stone[][] matrix)
    {
        for (int row = 0; row < matrix.length - 4; row++)
        {
            for (int col = 0; col < matrix.length; col++)
            {
                Stone element = matrix[row][col];
                if (element == matrix[row + 1][col] &&
                        element == matrix[row + 2][col] &&
                        element == matrix[row + 3][col] &&
                        element == matrix[row + 4][col])
                {
                    return element;
                }
            }
        }
        return Stone.EMPTY;
    }

    /**
     * Checks diagonal of the board for 5 in a row
     * @param matrix a Stone matrix with current stones on the board
     * @return the enum value for the color which has the winning 5 in a row
     */
    private static Stone checkMainDiagonal(Stone[][] matrix)
    {
        for (int row = 0; row < matrix.length - 4; row++)
        {
            for (int col = 0; col < matrix[row].length - 4; col++)
            {
                Stone element = matrix[row][col];
                if (element == matrix[row + 1][col + 1] &&
                        element == matrix[row + 2][col + 2] &&
                        element == matrix[row + 3][col + 3] &&
                        element == matrix[row + 4][col + 4])
                {
                    return element;
                }
            }
        }
        return Stone.EMPTY;
    }

    /**
     * Checks counter diagonals of the board for 5 in a row
     * @param matrix a Stone matrix with current stones on the board
     * @return the enum value for the color which has the winning 5 in a row
     */
    private static Stone checkCounterDiagonal(Stone[][] matrix)
    {
        for (int row = 0; row < matrix.length - 4; row++)
        {
            for (int col = 3; col < matrix[row].length - 4; col++)
            {
                Stone element = matrix[row][col];
                if (element == matrix[row + 1][col - 1] &&
                        element == matrix[row + 2][col - 2] &&
                        element == matrix[row + 3][col - 3]) //&&
                        //element == matrix[row + 4][col - 4])
                {
                    return element;
                }
            }
        }
        return Stone.EMPTY;
    }

}
