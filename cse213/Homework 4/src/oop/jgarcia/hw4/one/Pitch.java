package oop.jgarcia.hw4.one;

/**
 * Stores sound Pitch from notes A to G
 * @author Julian Garcia
 * @version HW 4, #1
 */
public enum Pitch {
    C("C", 0),
    CSHARP("C#", 1),
    D("D", 2),
    DSHARP("D#", 3),
    E("E", 4),
    F("F", 5),
    FSHARP("F#", 6),
    G("G", 7),
    GSHARP("G#", 8),
    A("A", 9),
    ASHARP("A#", 10),
    B("B", 11);

    private String abbrev;
    private int value;

    private Pitch(String abbrev, int value) {
        this.abbrev = abbrev;
        this.value = value;
    }

    /**
     * Returns offset of Pitch
     */
    int getOffset() {
        return value - 9;
    }

    /**
     * Returns abbreviation for Pitch
     */
    public String toString() {
        return this.abbrev;
    }
}
