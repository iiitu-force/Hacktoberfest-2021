//Longest Palindromic Substring

public class Main {
    
    static class Longest_Palindromic_Substring {

        static int longest_palindromic_substring(String s, int startIndex, int endIndex) {
        
            if (startIndex > endIndex) {
                return 0;
            }
            if (startIndex == endIndex) {

                return 1;
            }

            int c1 = 0;

            if (s.charAt(startIndex) == s.charAt(endIndex)) {

                int remainingLength = endIndex - startIndex - 1;
       
                if (remainingLength == longest_palindromic_substring(s, startIndex + 1, endIndex - 1)) {
                 
                   c1 = remainingLength + 2;
                   
                }
            }

                int c2 = 0 + longest_palindromic_substring(s, startIndex, endIndex - 1);
              
                int c3 = 0 + longest_palindromic_substring(s, startIndex + 1, endIndex);

                return Math.max(c1, Math.max(c2, c3));

            }
        }
    public static void main(String[] args) {

        String str="MAMDRDM";
        String str2="MQADASM";
        System.out.print("Longest Palindromic Substring: ");
        System.out.println(Longest_Palindromic_Substring.longest_palindromic_substring(str,0,str.length()-1));
        System.out.print("Longest Palindromic Substring: ");
        System.out.println(Longest_Palindromic_Substring.longest_palindromic_substring(str2,0,str.length()-1));
    }
}