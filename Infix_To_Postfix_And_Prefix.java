import java.io.*;
import java.util.*;

public class Infix_To_Postfix_And_Prefix {

      public static void main(String[] args) throws Exception {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String exp = br.readLine();

            Stack<Character> operators = new Stack<>();
            Stack<String> postfix = new Stack<>();
            Stack<String> prefix = new Stack<>();

            for(int i = 0; i < exp.length(); i++){
                  char ch = exp.charAt(i);
                  if(ch == '('){
                        operators.push(ch);
                  } else if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <='z') || (ch >= 'A' && ch <='Z')){
                        prefix.push(ch + "");
                        postfix.push(ch + "");
                  } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
                        while(operators.size() > 0 && operators.peek() != '(' && precedence(ch) <= precedence(operators.peek())){
                              char optor = operators.pop();

                              String postv2 = postfix.pop();
                              String postv1 = postfix.pop();
                              String postv = postv1 + postv2 + optor;
                              postfix.push(postv);

                              
                              String prev2 = prefix.pop();
                              String prev1 = prefix.pop();
                              String prev = optor + prev1 + prev2;
                              prefix.push(prev);
                        }
                        operators.push(ch);
                  } else if(ch == ')'){
                        while(operators.peek() != '('){
                              char optor = operators.pop();

                              String postv2 = postfix.pop();
                              String postv1 = postfix.pop();
                              String postv = postv1 + postv2 + optor;
                              postfix.push(postv);

                              
                              String prev2 = prefix.pop();
                              String prev1 = prefix.pop();
                              String prev = optor + prev1 + prev2;
                              prefix.push(prev);
                        }
                        operators.pop();
                  }
            }

            while(operators.size() > 0){
                  char optor = operators.pop();

                  String postv2 = postfix.pop();
                  String postv1 = postfix.pop();
                  String postv = postv1 + postv2 + optor;
                  postfix.push(postv);

                  
                  String prev2 = prefix.pop();
                  String prev1 = prefix.pop();
                  String prev = optor + prev1 + prev2;
                  prefix.push(prev);
            }


            System.out.println(prefix.pop());
            System.out.println(postfix.pop());
      }

      public static int precedence(char optor){
            if(optor == '+'){
                  return 1;
            } else if(optor == '-'){
                  return 1;
            } else if(optor == '*'){
                  return 2;
            } else if(optor == '/'){
                  return 2;
            } else{
                  return 3;
            }
      }
}
