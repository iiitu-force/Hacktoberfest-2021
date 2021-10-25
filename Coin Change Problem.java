//Coin Change Problem

import java.util.Arrays;

public class Main {

    static class CoinChange{

        static void coinChangeProblem(int[] arr,int N) {
            Arrays.sort(arr);
            int index = arr.length - 1;

            while (true) {
                int coinValue = arr[index];
                index--;

                int maxAmount=coinValue * (N/coinValue);
                if (maxAmount > 0) {
                    System.out.println("Coin with value "+coinValue+" and count "+N/coinValue);
                    N = N - maxAmount;
                }

                if (N == 0) {
                    break;
                }

            }
        }


    }


    public static void main(String[] args) {

            int[] coins={1,2,5,10,20,50,100,500,1000};
            int amount=2045;
        System.out.println("Coins available "+Arrays.toString(coins));
        System.out.println("Target amount "+amount);

        CoinChange.coinChangeProblem(coins,amount);

    }
}