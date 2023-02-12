package oop.jgarcia.hw3.two;

public class Website extends Citation{
    private String url;
    private String month;
    private int day;

    public Website(String s, String t, int u, String url, String month, int day) {
        super(s, t, u);
        this.url = url;
        this.month = month;
        this.day = day;
    }

    public int getDay() {
        return day;
    }

    public String getMonth() {
        return month;
    }

    public String getUrl() {
        return url;
    }

    @Override
    public String toString() {
        int i;
        String[] s = new String[author.length];
        for(i = 0; i < author.length; i++) {
            s[i] = s[i] + author[i].getFirstName() + author[i].getMiddleInitial() + author[i].getLastName();
        }
        String str = String.join(", ", s);
        String str2 = str + ", " + this.title + "., " + Integer.toString(year) + " " + url + ", "
                + month + " " + Integer.toString(day);
        return str2;
    }
}
