package oop.jgarcia;

public abstract class Shape implements Cloneable {
    public abstract double width();
    public abstract double height();
    public abstract double area();
    public abstract double perimeter();
    public abstract boolean inBounds(double x, double y);
}
