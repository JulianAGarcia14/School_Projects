package oop.jgarcia.hw4.one;
import oop.projects.tone.Tone;

import java.util.*;
import java.io.*;
import java.util.ArrayList;


/**
 * Parses Song.txt to Notes and plays them using Tone.java
 * Implements Array Lists to store separate notes
 * @author Julian Garcia
 * @version HW 4, #1
 */
public class PlaySong {
    /**
     * Takes Notes and plays a song using Tone.java
     * @param notes An arraylist of the given notes
     * @param tempo given tempo for song
     */
    public static void playSong(ArrayList<Note> notes, int tempo) {

        double duration;
        double frequency;

        for (Note member : notes) {
            if(member != null) {
                Beat b = member.getLength();
                duration = b.getDuration(tempo);
                frequency = member.getFrequency();
                Tone.playTone(frequency, duration);
            }
        }

    }

    public static void main(String[] args) throws IOException {
        ArrayList<Note> list = new ArrayList<Note>();
        ArrayList<String> str = new ArrayList<String>();

        Scanner s = new Scanner(new File("song.txt"));

        while (s.hasNext()){

            str.add(s.next());

        }

        int i = 0;
        String s1 = "C4";
        String s2;

        for (String member : str) {
            if((i % 2) != 0) {
                s2 = member;
                for (Beat p : Beat.values()) {
                    if (p.toString().equals(s2)) {
                        Note n = new Note(s1, p);
                        list.add(n);
                    }
                }

            } else {
                s1 = member;
            }
            i++;
        }
        s.close();

        playSong(list, 120);

    }

}
