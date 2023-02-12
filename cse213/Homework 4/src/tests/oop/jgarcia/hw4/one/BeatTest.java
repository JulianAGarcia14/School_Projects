package oop.jgarcia.hw4.one;

import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class BeatTest {

    @Test
    public void checkBeatGetDurationWhole() {
        double expected = 2;
        double actual = Beat.WHOLE.getDuration(120);
        double delta = 0.1;

        Assert.assertEquals("Beat duration incorrect.", expected, actual, delta);

    }

    @Test
    public void checkBeatGetDurationSixteenth() {
        double expected = 0.125;
        double actual = Beat.SIXTEENTH.getDuration(120.0);
        double delta = 0.1;

        Assert.assertEquals("Beat Duration incorrect.", expected, actual, delta);

    }

}