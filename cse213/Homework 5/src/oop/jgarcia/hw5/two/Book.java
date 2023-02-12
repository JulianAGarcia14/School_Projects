package oop.jgarcia.hw5.two;

public class Book extends Citation {
    protected String publisher;

    public Book(String s, String t, int u, String publisher) {
        super(s, t, u);
        this.publisher = publisher;
    }

    public String getPublisher() {
        return publisher;
    }

    @Override
    public String toString() {
        int i;
        String[] s = new String[author.length];
        for(i = 0; i < author.length; i++) {
            s[i] = s[i] + author[i].getFirstName() + author[i].getMiddleInitial() + author[i].getLastName();
        }
        String str = String.join(", ", s);
        String str2 = str + ", " + this.title + "., " + Integer.toString(this.year) + ", " + publisher;
        return str2;
    }
}
