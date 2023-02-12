package oop.jgarcia.hw6.two;

import java.util.*;

/**
 * General purpose calculator which takes reverse Polish notation.
 * Asks for an expression from the user to tokenize and parse through stack operations
 * @author Julian Garcia
 * @version HW 6, #2
 */

public class RPN {

    /**
     * Takes an arrayList of tokens and returns a double after parsing using stack operations
     * @param tokens arrayList of tokens to be parsed
     * @return double
     */
    public static double eval(ArrayList<Token> tokens) throws ArithmeticException{

        Stack<Double> stack = new Stack<Double>();

        for(Token token:tokens) {
            if(token.isOperator() == false) {
                stack.push(token.getNumber());
            }
            else {
                Double b,a;
                if(stack.empty()) {
                    throw new ArithmeticException("Error! Invalid Expression!");
                }
                b = stack.pop();
                if(stack.empty()) {
                    throw new ArithmeticException("Error! Invalid Expression!");
                }
                a = stack.pop();
                double c = token.getOperator().eval(a.doubleValue(), b.doubleValue());
                stack.push(Double.valueOf(c));
            }
        }
        if(stack.empty()) {
            throw new ArithmeticException("Invalid RPN Expression");
        }
        Double d = stack.pop();
        if(!stack.empty()) {
            throw new ArithmeticException("Invalid RPN Expression");
        }
        return d.doubleValue();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true) {
            System.out.println("RPN Expression>");
            String str = sc.nextLine();
            StringTokenizer stringTokenizer = new StringTokenizer(str);
            ArrayList<Token> tokens = new ArrayList<>();
            while(stringTokenizer.hasMoreTokens()) {
                tokens.add(Token.parseToken(stringTokenizer.nextToken()));
            }
            try{
                System.out.println(">>> " + eval(tokens));
            }
            catch(ArithmeticException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
