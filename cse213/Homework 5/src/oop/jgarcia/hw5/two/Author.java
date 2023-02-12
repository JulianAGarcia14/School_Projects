package oop.jgarcia.hw5.two;


public class Author {
    private String lastName;
    private String firstName;
    private String middleInitial;

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getMiddleInitial() {
        return middleInitial;
    }

    public Author(String first, String middle, String last){
        this.firstName = first;
        this.middleInitial = middle.substring(0, 1);
        this.lastName = last;

    }

    public Author(String name){
        String[] splitStr = name.trim().split("\\s+");

        this.firstName = splitStr[0];

        if(splitStr.length < 2) {
            this.middleInitial = " ";
            this.lastName = splitStr[1];
        } else {
            this.middleInitial = splitStr[1];
            this.lastName = splitStr[2];
        }
    }

    public String getCitation() {
        return firstName + ", " + middleInitial + ". " + lastName + ".";
    }

    public static Author[] splitAuthors(String s){
        String[] splitStr = s.split(",");
        if(splitStr.length > 1) {
            String[] end = splitStr[splitStr.length - 1].split("and");


            int i;
            int len = splitStr.length;
            Author[] author = new Author[len + 1];
            for (i = 0; i < splitStr.length - 1; i++) {
                author[i] = new Author(splitStr[i]);
            }
            author[len] = new Author(end[0]);
            author[len + 1] = new Author(end[2]);


            return author;
        }
        else {
            Author[] author = {new Author (splitStr[0])};
            return author;
        }

    }

}
