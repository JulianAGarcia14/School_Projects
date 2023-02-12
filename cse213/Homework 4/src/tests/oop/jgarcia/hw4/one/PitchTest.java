package oop.jgarcia.hw4.one;

import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class PitchTest {

    @Test
    public void checkPitchAGetOffset() {
        double expected = 0;
        double actual = Pitch.A.getOffset();
        double delta = 0.1;

        Assert.assertEquals("Pitch A offset incorrect.", expected, actual, delta);

    }

    @Test
    public void checkPitchCGetOffset() {
        double expected = -9;
        double actual = Pitch.C.getOffset();
        double delta = 0.1;

        Assert.assertEquals("Pitch A offset incorrect.", expected, actual, delta);

    }

}