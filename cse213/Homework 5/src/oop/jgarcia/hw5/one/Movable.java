package oop.jgarcia.hw5.one;

public interface Movable {

    public void setPosition(double x, double y);
    public void setPolar(double radius, double angle);
    public void move(double dx, double dy);
    public void movePolar(double radius, double angle);
}
