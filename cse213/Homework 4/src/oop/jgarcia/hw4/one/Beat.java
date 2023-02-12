package oop.jgarcia.hw4.one;


/**
 * Stores different types of beats.
 * @author Julian Garcia
 * @version HW 4, #1
 */
public enum Beat {
    WHOLE("(1)", 4.0),
    THREEQUARTER("(3/4)", 3.0),
    HALF("(1/2)",2.0),
    THREEIGHTH("(3/8)",3.0/2.0),
    QUARTER("(1/4)",1.0),
    THREESIXTEENTH("(3/16)",3.0/4.0),
    EIGHTH("(1/8)",1.0/2.0),
    SIXTEENTH("(1/16)",1.0/4.0);

    private double beats;
    private String beet;

    private Beat(String beet, double beats) {
        this.beet = beet;
        this.beats = beats;
    }

    double getBeats() {
        return this.beats;
    }
    /**
     * Returns duration given tempo
     * @param tempo given tempo for song
     */
    double getDuration(double tempo) {
        return (60.0 * beats) / tempo;
    }

    /**
     * Returns string of current beat
     */
    public String toString() {
        return this.beet;
    }
}
