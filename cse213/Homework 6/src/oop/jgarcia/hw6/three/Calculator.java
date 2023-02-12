package oop.jgarcia.hw6.three;

import oop.jgarcia.hw6.two.Operator;
import oop.jgarcia.hw6.two.Token;
import oop.jgarcia.hw6.two.RPN;

import java.util.*;

/**
 * General purpose calculator which translates normal (infix notation) expressions into reverse Polish notation.
 * Implements Dijkstra’s shunting-yard algorithm to accomplish this
 * Asks for an expression from the user to tokenize and parse through stack operations
 * @author Julian Garcia
 * @version HW 6, #3
 * Note: The pdf example had parenthesis without spaces (e.g "(3 + 5)") this REQUIRES spaces between every character (e.g "( 3 + 5 )")
 */

public class Calculator {

    public static ArrayList<Token> toRPN(ArrayList<Token> list) {
        ArrayList<Token> mainList = new ArrayList();
        Stack<Operator> stack = new Stack();
        for(int i = 0; i < list.size(); i++) {

            if(list.get(i).isOperator() == false) {

                mainList.add(list.get(i));

            }

            else if (list.get(i).getOperator() != Operator.LPAREN & list.get(i).getOperator() != Operator.RPAREN){

                while(stack.isEmpty() != true) {
                    if( list.get(i).getOperator().getPrecedence() > stack.peek().getPrecedence() & (stack.peek() != Operator.LPAREN) & (stack.peek() != Operator.RPAREN) )
                    {
                        Operator a = stack.pop();
                        Token b = Token.parseToken(a.toString());
                        mainList.add(b);
                    } else if( list.get(i).getOperator() == Operator.EXPONENT & stack.peek() == Operator.EXPONENT )
                    {
                        Operator c = stack.pop();
                        Token d = Token.parseToken(c.toString());
                        mainList.add(d);
                    } else {
                        break;
                    }

                }
                stack.push(list.get(i).getOperator());

            }

            else if (list.get(i).getOperator() == Operator.LPAREN){
                stack.push(list.get(i).getOperator());

            }
            else if (list.get(i).getOperator() == Operator.RPAREN){
                while((stack.peek() != Operator.LPAREN)) {
                    Operator e = stack.pop();
                    Token f = Token.parseToken(e.toString());
                    mainList.add(f);

                    if (stack.isEmpty() == true) {
                        throw new ArithmeticException("Mismatched Parenthesis");
                    }
                }
                stack.pop();
            }

        }
        while((stack.isEmpty() != true)) {
            Operator g = stack.pop();
            Token h = Token.parseToken(g.toString());
            mainList.add(h);
        }

        return mainList;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        while(true) {

            System.out.println("Expression>");

            String str = sc.nextLine();

            StringTokenizer stringTokenizer = new StringTokenizer(str);

            ArrayList<Token> tokens = new ArrayList<>();

            while(stringTokenizer.hasMoreTokens()) {

                tokens.add(Token.parseToken(stringTokenizer.nextToken()));

            }

            ArrayList<Token> tokens2 = toRPN(tokens);
            try{

                System.out.println(">>> " + RPN.eval(tokens2));

            }

            catch(ArithmeticException e) {

                System.out.println(e.getMessage());

            }

        }

    }



}
