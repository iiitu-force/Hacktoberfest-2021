package com.sharmaumang;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


class Pancake {

    static void flip(int arr[], int i) {
        int temp, start = 0;
        while (start < i)
        {
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
            start++;
            i--;
        }
    }

    static int findMax(int arr[], int n) {
        int mi, i;
        for (mi = 0, i = 0; i < n; ++i)
            if (arr[i] > arr[mi])
                mi = i;
        return mi;
    }

    static int pancakeSort(int arr[], int n) {

        for (int curr_size = n; curr_size > 1; --curr_size) {

            int mi = findMax(arr, curr_size);

            if (mi != curr_size-1) {

                flip(arr, mi);

                flip(arr, curr_size-1);
            }
        }
        return 0;
    }

    static void printArray(int arr[], int arr_size)
    {
        for (int i = 0; i < arr_size; i++)
            System.out.print(arr[i] + " ");
        System.out.println("");
    }

    public static void main (String[] args) {

        FastReader sc = new FastReader();
        int t = sc.nextInt();
        int[] arr = new int[t];
        for (int i = 0; i < t; i++) {
            arr[i]=sc.nextInt();
        }
        int n = arr.length;

        pancakeSort(arr, n);

    }


    //Fast Reader Class
    static class FastReader {
        BufferedReader reader;
        StringTokenizer mStringTokenizer;

        public FastReader() {
            reader = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (mStringTokenizer == null || !mStringTokenizer.hasMoreElements()) {
                try {
                    mStringTokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return mStringTokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}


