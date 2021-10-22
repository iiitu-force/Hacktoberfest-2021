import java.util.Scanner;

class YoungerAgeException extends RuntimeException 
{
      YoungerAgeException(String message)
      {
            super(message);
      }
}

class main{
      public static void main(String[] args){
            Scanner s = new  Scanner(System.in);
            System.out.println("Enter your age");
            int age = s.nextInt();
            try
            {
                  if(age < 18){
                        throw new YoungerAgeException("");
                  }
                  else{
                        System.out.println("You can vote successfully");
                  }
            }
            catch(YoungerAgeException e)
            {
                  System.out.println("You are not eligble for vote");
            }
            System.out.println("Program terminated successfully");
      }
}
