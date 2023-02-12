package oop.jgarcia.hw3.two;

public class Newspaper extends Citation{
    private String newsPaper;
    private String month;
    private int day;

    public Newspaper(String authors, String title, int year, String newsPaper, String month, int day) {
        super(authors, title, year);
        this.newsPaper = newsPaper;
        this.month = month;
        this.day = day;
    }

    public String getMonth() {
        return month;
    }

    public int getDay() {
        return day;
    }

    public String getNewsPaper() {
        return newsPaper;
    }

    @Override
    public String toString() {
        int i;
        String[] s = new String[author.length];
        for(i = 0; i < author.length; i++) {
            s[i] = s[i] + author[i].getFirstName() + author[i].getMiddleInitial() + author[i].getLastName();
        }
        String str = String.join(", ", s);
        String str2 = str + ", " + this.title + "., " + Integer.toString(year) + " " + newsPaper + ", "
                + month + " " + Integer.toString(day);
        return str2;
    }
}
