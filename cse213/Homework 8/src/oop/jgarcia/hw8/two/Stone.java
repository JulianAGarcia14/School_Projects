package oop.jgarcia.hw8.two;


import java.awt.*;
/**
 * Simple enum for holding colors
 * @author Julian Garcia
 * @version HW 8, #2
 */
public enum Stone {
    EMPTY, BLACK, WHITE;

    /**
     * Finds color of the stone
     * @param s given stone with enum value
     * @return the color of the given stone
     */
    public static Color getColor(Stone s){

        switch(s) {
            case EMPTY:
                return null;
            case BLACK:
                return Color.BLACK;
            case WHITE:
                return Color.WHITE;
        }
        return null;
    }
}
