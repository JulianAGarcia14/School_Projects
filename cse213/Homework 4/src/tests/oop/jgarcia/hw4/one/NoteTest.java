package oop.jgarcia.hw4.one;

import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class NoteTest {

    @Test
    public void checkNoteConstructorOne() {
        Pitch expected = Pitch.C;
        double expected2 = 4;
        Note n = new Note();
        Pitch actual = n.getNote();
        double actual2 = n.getOctave();
        double delta = 0.1;

        Assert.assertEquals("Default Note incorrect pitch.", expected, actual);
        Assert.assertEquals("Default Note incorrect octave.", expected2, actual2, delta);

    }

    @Test
    public void checkNoteConstructorTwo() {
        Pitch expected = Pitch.ASHARP;
        double expected2 = 8;
        Note n = new Note(Pitch.ASHARP, 8, Beat.EIGHTH);
        Pitch actual = n.getNote();
        double actual2 = n.getOctave();
        double delta = 0.1;

        Assert.assertEquals("Second Constructor Note incorrect pitch.", expected, actual);
        Assert.assertEquals("Second Constructor Note incorrect octave.", expected2, actual2, delta);

    }

    @Test
    public void checkNoteConstructorThree() {
        Pitch expected = Pitch.C;
        double expected2 = 4;
        Note n = new Note("C4", Beat.QUARTER);
        Pitch actual = n.getNote();
        double actual2 = n.getOctave();
        double delta = 0.1;

        Assert.assertEquals("Third Constructor Note incorrect pitch.", expected, actual);
        Assert.assertEquals("Third Constructor Note incorrect octave.", expected2, actual2, delta);

    }

    @Test
    public void checkNoteConstructorFour() {
        Pitch expected = Pitch.C;
        double expected2 = 4;
        Note n = new Note(60, Beat.QUARTER);
        Pitch actual = n.getNote();
        double actual2 = n.getOctave();
        double delta = 0.1;

        Assert.assertEquals("Default Note incorrect pitch.", expected, actual);
        Assert.assertEquals("Default Note incorrect octave.", expected2, actual2, delta);

    }

    @Test
    public void checkNoteConstructorFive() {
        Pitch expected = Pitch.C;
        double expected2 = 4;
        double d = 262;
        Note n = new Note(d, Beat.QUARTER);
        Pitch actual = n.getNote();
        double actual2 = n.getOctave();
        double delta = 0.1;

        Assert.assertEquals("Fifth Constructor Note incorrect pitch.", expected, actual);
        Assert.assertEquals("Fifth Constructor Note incorrect octave.", expected2, actual2, delta);

    }

}