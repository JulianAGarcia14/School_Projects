package oop.jgarcia.hw3.two;

public class Bibliography {
    public static void main(String[] args) {

        Citation[] cite = {
                new Book("Henry David Thoreau", "Walden", 1854, "Ticknor and Fields Publishing Co."),
                new Chapter("J R Tolkein", "The Fellowship of the Ring", 1954, "", "A Short Cut to Mushrooms",
                        4, 58, 65),
                new Journal("A M Turing", "Computing Machinery and Intelligence", 1950, "Mind", 59, 433, 460),
                new Newspaper("J J Herbers", "NIXON RESIGNS", 1974, "New York Times", "August", 8),
                new Book("Henry David Thoreau", "Walden", 1854, "Ticknor and Fields Publishing Co."),
        };

        Citation cite0 = cite[0];
        Citation cite1 = cite[1];
        Citation cite2 = cite[2];
        Citation cite3 = cite[3];
        Citation cite4 = cite[4];

        int i;
        for(i = 0; i < cite.length ; i++) {
            System.out.println(cite[i].toString());
        }

    }
}
