import java.io.*;
import java.util.*;

public class Sliding_Window {

      public static void main(String[] args) throws Exception {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(br.readLine());
            int[] a = new int[n];  // declaring array a
            for (int i = 0; i < n; i++) {
                  a[i] = Integer.parseInt(br.readLine());  //Taking input if array element
            }
            int k = Integer.parseInt(br.readLine());  //Taking input of element k

            System.out.println("Answer is: ");
            Stack<Integer> stack = new Stack<>(); 
            int[] ans = new int[a.length];
            stack.push(a.length - 1);
            ans[a.length - 1] = a.length;

            // finding next greater element in the array..
            for(int i = a.length - 2; i >= 0; i--) {
                  while(stack.size() > 0  && a[i] >= a[stack.peek()]){
                        stack.pop();
                  }

                  if(stack.size() == 0){
                        ans[i] = a.length;
                  } else{
                        ans[i] = stack.peek();
                  }

                  stack.push(i);
            }



            // finding the maximum element in the sliding window
            int j = 0;
            for(int i=0; i <= a.length - k; i++){
                  if(j<i){
                        j = i;
                  }
                  while(ans[j] < i + k){
                        j = ans[j];
                  }

                  System.out.println(a[j]);
            }
      }
}
