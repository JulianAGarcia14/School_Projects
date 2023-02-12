package oop.jgarcia.hw5.two;

public class Chapter extends Book {
    private String chapterName;
    private int chapterNumber;
    private int startPage;
    private int endPage;

    public Chapter(String s, String t, int u, String publisher, String chapterName, int chapterNumber, int startPage, int endPage) {
        super(s, t, u, publisher);
        this.chapterName = chapterName;
        this.chapterNumber = chapterNumber;
        this.startPage = startPage;
        this.endPage = endPage;
    }

    public int getStartPage() {
        return startPage;
    }

    public int getEndPage() {
        return endPage;
    }

    public int getChapterNumber() {
        return chapterNumber;
    }

    public String getChapterName() {
        return chapterName;
    }
    @Override
    public String toString() {
        int i;
        String[] s = new String[author.length];
        for(i = 0; i < author.length; i++) {
            s[i] = s[i] + author[i].getFirstName() + author[i].getMiddleInitial() + author[i].getLastName();
        }
        String str = String.join(", ", s);
        String str2 = str + ", " + this.title + "., " + Integer.toString(year) + ",  Chapter " + Integer.toString(chapterNumber) + ", "
                + chapterName + " (pp. " + Integer.toString(startPage) + "-" + Integer.toString(endPage) + ")";
        return str2;
    }

}
