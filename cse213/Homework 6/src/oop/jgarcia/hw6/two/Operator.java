package oop.jgarcia.hw6.two;

import java.lang.Math;


/**
 * Contains enumerations to track different operators
 * @author Julian Garcia
 * @version HW 6, #2
 */
public enum Operator {

    LPAREN(3,'('),

    RPAREN(3,')'),

    EXPONENT(2,'^'),

    MULTIPLY(1,'*'),

    DIVIDE(1,'/'),

    MODULO(1,'%'),

    ADD(0,'+'),

    SUBTRACT(0,'-');

    private int precedence;

    private char symbol;

    Operator(int precedence,char symbol) {

        this.precedence = precedence;

        this.symbol = symbol;

    }

    public int getPrecedence() {

        return precedence;

    }

    public double eval(double a,double b) {

        switch(this) {

            case LPAREN:

            case RPAREN:

                return Double.NaN;

            case EXPONENT:

                return Math.pow(a, b);

            case MULTIPLY:

                return a*b;

            case DIVIDE:

                return a/b;

            case MODULO:

                return a%b;

            case ADD:

                return a+b;

            case SUBTRACT:

                return a-b;

        }

        return 0;

    }

    public String toString() {

        return String.valueOf(symbol);

    }

}
