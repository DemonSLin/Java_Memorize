package www.lsl.com.july;

import java.util.Scanner;
import java.util.Stack;

public class Parenthesis {
   // public boolean chkParenthesis(String A, int n) {
    public static boolean chkParenthesis(String A, int n) {
        Stack<Character> lefts = new Stack<Character>(); //???开辟栈lefts
        if(A == null || A.length() != n){
            return false;
        }
        for(int i = 0; i < n; i++){
            if(A.charAt(i) == '('){
                lefts.push(A.charAt(i));//???
            }
            else if(A.charAt(i) == ')'){
                if(lefts.empty()){
                    return false;
                }
                else{
                    lefts.pop();//???
                }
            }else{
                return false;
            }
        }
        if(!lefts.empty()){
            return false;
        }
        else{
            return true;
        }
    }

    public static void main(String[] args) {
      //  Parenthesis parenthesis = new Parenthesis();
        Scanner sc=new Scanner(System.in);
        while(sc.hasNext()){
            String str=sc.nextLine();
            //System.out.println(parenthesis.chkParenthesis(str, str.length()));
            System.out.println(chkParenthesis(str,str.length()));
        }
    }
}
