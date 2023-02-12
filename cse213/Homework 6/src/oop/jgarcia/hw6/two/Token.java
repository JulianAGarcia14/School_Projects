package oop.jgarcia.hw6.two;


/**
 * Used to parse tokens from main function
 * @author Julian Garcia
 * @version HW 6, #2
 */
public class Token {

    private Double number;

    private Operator operator;

    /**
     * Sets up token as a number and NOT an operator
     * @param n number to be stored
     */
    Token(Double n) {
        number = n;
        operator = null;
    }

    /**
     * Sets up token as an operator and NOT a number
     * @param o operator to be stored
     */
    Token(Operator o) {
        operator = o;
        number = null;
    }

    /**
     * Simply returns the number
     * @return number
     */
    public Double getNumber() {
        return number;
    }

    /**
     * Simply returns the operator
     * @return operator
     */
    public Operator getOperator() {
        return operator;
    }

    /**
     * Finds if token is an operator
     * @return true if an operator, false if not
     */
    public boolean isOperator() {
        if(operator == null) {
            return false;
        } else {
            return true;
        }

    }

    /**
     * Parses string to return token version
     * @param s string to be parsed
     * @return token resultant token of string
     */
    public static Token parseToken(String s) {

        if(s.equals("(")) return new Token(Operator.LPAREN);

        else if(s.equals(")")) return new Token(Operator.RPAREN);

        else if(s.equals("^")) return new Token(Operator.EXPONENT);

        else if(s.equals("*")) return new Token(Operator.MULTIPLY);

        else if(s.equals("/")) return new Token(Operator.DIVIDE);

        else if(s.equals("%")) return new Token(Operator.MODULO);

        else if(s.equals("+")) return new Token(Operator.ADD);

        else if(s.equals("-")) return new Token(Operator.SUBTRACT);

        else {
            try {
                return new Token(Double.parseDouble(s));
            }
            catch(NumberFormatException e) {
                return null;
            }
        }
    }
}