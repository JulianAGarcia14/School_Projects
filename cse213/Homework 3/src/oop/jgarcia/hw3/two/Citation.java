package oop.jgarcia.hw3.two;

public class Citation {
    protected String title;
    protected int year;
    protected Author[] author;

    public int getYear() {
        return year;
    }

    public Author[] getAuthor() {
        return author.clone();
    }

    public String getTitle() {
        return title;
    }

    public Citation(String authors, String title, int year){

        this.author = Author.splitAuthors(authors);
        this.title = title;
        this.year = year;

    }

    public String toString() {
        int i;
        String[] s = new String[author.length];
        for(i = 0; i < author.length; i++) {
            s[i] = s[i] + author[i].getFirstName() + author[i].getMiddleInitial() + author[i].getLastName();
        }
        String str = String.join(", ", s);
        String str2 = str + ", " + this.title + "., " + Integer.toString(this.year);
        return str2;
    }

}
