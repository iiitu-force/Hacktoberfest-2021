//Longest Palindromic Subsequence

import java.util.Arrays;

public class Main {

   static class Longest_Palindromic_Subsequence{

       static int longest_palindromic_subsequence(String s,int startIndex,int endIndex)
       {
         if(startIndex>endIndex)
         {
             return 0;
         }
         if(startIndex==endIndex) {

              return 1;
         }

         int c1=0;

         if(s.charAt(startIndex)==s.charAt(endIndex)) {
              c1 = 2+ longest_palindromic_subsequence(s, startIndex + 1, endIndex - 1);
           
         }

             int c2 = 0 + longest_palindromic_subsequence(s, startIndex, endIndex - 1);
             int c3 = 0 + longest_palindromic_subsequence(s, startIndex + 1, endIndex);

             return Math.max(c1, Math.max(c2, c3));


       }
   }

    public static void main(String[] args) {

        String str="ELRMENMET";

        System.out.print("Longest Palindromic Subsequence: ");
     
        System.out.println(Longest_Palindromic_Subsequence.longest_palindromic_subsequence(str,0,str.length()-1));
    
    }
}