package oop.jgarcia.hw4.one;
import java.util.ArrayList;

/**
 * Creates a Note using enumerations in package
 * Contains functions for parsing SDN, MIDI, and Frequency to give note values
 * @author Julian Garcia
 * @version HW 4, #1
 */
public class Note {
    private Pitch note;
    private int octave;
    private Beat length;

    public void setLength(Beat length) {
        this.length = length;
    }

    public Beat getLength() {
        return length;
    }

    public int getOctave() {
        return octave;
    }

    public void setOctave(int octave) {
        this.octave = octave;
    }

    public void setNote(Pitch note) {
        this.note = note;
    }

    public Pitch getNote() {
        return note;
    }

    public Note() {
        this.note = Pitch.C;
        this.length = Beat.QUARTER;
        this.octave = 4;
    }

    public Note(Pitch p, int i, Beat b) {
        if(p == Pitch.CSHARP || p == Pitch.ASHARP || p == Pitch.DSHARP || p == Pitch.FSHARP || p == Pitch.GSHARP) {
            if(i < -1 || i > 8) {
                System.out.println("Incorrect pitch, must be -1-8 for sharp notes, reverting to C4");
                this.note = Pitch.C;
                this.length = Beat.QUARTER;
                this.octave = 4;
            }
        } else {
            if(i < -1 || i > 9) {
                System.out.println("Incorrect pitch, must be -1-9 for natural notes, reverting to C4");
                this.note = Pitch.C;
                this.length = Beat.QUARTER;
                this.octave = 4;
            }
        }

        this.octave = i;
        this.length = b;
        this.note = p;

    }

    public Note(String s, Beat b) {
        setSPN(s);
        this.length = b;
    }

    public Note(int i, Beat b) {
        setMIDI(i);
        this.length = b;
    }

    public Note(double d, Beat b) {
        setFrequency(d);
        this.length = b;
    }

    /**
     * Returns an SPN using given values
     */
    public String getSPN() {
        return (note.toString() + Integer.toString(this.octave));
    }

    /**
     * Sets tone values using spn
     * @param spn A given string ideally in spn format
     */
    public void setSPN(String spn) {
        if (spn.matches("(([CDFGA]#?|[EB])(-1|[0-8])|([CDF]#?|[EG])9)")) {
            char c = spn.charAt(1);
            if(c == '#') {
                for (Pitch p : Pitch.values()) {
                    if(p.toString().equals(spn.substring(0, 2))) {
                        this.note = p;
                    }
                }
                if(spn.charAt(2) == '-') {
                    this.octave = Integer.parseInt(spn.substring(2, 3));
                } else {
                    this.octave = Integer.parseInt(spn.substring(2));
                }

            } else {
                for (Pitch p : Pitch.values()) {
                    String d = spn.substring(0, 1);
                    //System.out.println(d);
                    if(p.toString().equals(d)) {
                        this.note = p;
                    }
                }
                if(spn.charAt(1) == ('-')) {
                    this.octave = Integer.parseInt(spn.substring(2));
                    this.octave = this.octave * -1;
                } else {
                    this.octave = Integer.parseInt(spn.substring(1));
                }

            }

        } else {
            System.out.println("Incorrect input, reverting to C4");
            this.note = Pitch.C;
            this.length = Beat.QUARTER;
            this.octave = 4;
        }
    }

    /**
     * Determines MIDI value of present Note
     */
    public int getMIDI() {
        return 69 + note.getOffset() + 12*(octave - 4);
    }

    /**
     * Sets Tone values using MIDI value
     * @param i MIDI value to be parsed
     */
    public void setMIDI(int i) {
        this.octave = (i/12) - 1;
        for (Pitch p : Pitch.values()) {
            if(p.getOffset() == ((i % 12) - 9)) {
                this.note = p;
            }
        }
    }

    /**
     * Gets frequency of present Note
     */
    public double getFrequency() {
        return 440*Math.pow(2, ((getMIDI() - 69)/12));
    }

    /**
     * Sets Note values using given Frequency
     * @param f given frequency
     */
    public void setFrequency(double f) {
        int midi = (int) (12*(Math.log(f/440)/Math.log(2)) + 69);
        setMIDI(midi);
    }

    /**
     * Returns a string using spn and length value
     */
    public String toString() {
        return getSPN() + " " + this.length.toString();
    }

}
