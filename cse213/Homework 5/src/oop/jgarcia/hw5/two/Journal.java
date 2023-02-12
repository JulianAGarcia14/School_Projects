package oop.jgarcia.hw5.two;

public class Journal extends Citation{
    private String journalName;
    private int volume;
    private int startPage;
    private int endPage;

    public Journal(String authors, String title, int year, String journalName, int volume, int startPage, int endPage) {
        super(authors, title, year);
        this.journalName = journalName;
        this.volume = volume;
        this.startPage = startPage;
        this.endPage = endPage;
    }

    public int getEndPage() {
        return endPage;
    }

    public int getStartPage() {
        return startPage;
    }

    public int getVolume() {
        return volume;
    }

    public String getJournalName() {
        return journalName;
    }

    @Override
    public String toString() {
        int i;
        String[] s = new String[author.length];
        for(i = 0; i < author.length; i++) {
            s[i] = s[i] + author[i].getFirstName() + author[i].getMiddleInitial() + author[i].getLastName();
        }
        String str = String.join(", ", s);
        String str2 = str + ", " + this.title + "., " + Integer.toString(year) + " " + journalName + ", vol. "
                + Integer.toString(volume) + " (pp. " + Integer.toString(startPage) + "-" + Integer.toString(endPage) + ")";
        return str2;
    }

}
