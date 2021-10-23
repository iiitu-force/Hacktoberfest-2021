package com.sharmaumang;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Bitonic {

    void compAndSwap(int a[], int i, int j, int dir)
    {
        if ( (a[i] > a[j] && dir == 1) ||
                (a[i] < a[j] && dir == 0))
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }


    void bitonicMerge(int a[], int low, int cnt, int dir)
    {
        if (cnt>1)
        {
            int k = cnt/2;
            for (int i=low; i<low+k; i++)
                compAndSwap(a,i, i+k, dir);
            bitonicMerge(a,low, k, dir);
            bitonicMerge(a,low+k, k, dir);
        }
    }


    void bitonicSort(int a[], int low, int cnt, int dir)
    {
        if (cnt>1)
        {
            int k = cnt/2;

            bitonicSort(a, low, k, 1);

            bitonicSort(a,low+k, k, 0);


            bitonicMerge(a, low, cnt, dir);
        }
    }

    void sort(int a[], int N, int up)
    {
        bitonicSort(a, 0, N, up);
    }

    /* A utility function to print array of size n */
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    // Driver method
    public static void main(String args[])
    {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        int[] a = new int[t];
        for (int i = 0; i < t; i++) {
            a[i]=sc.nextInt();
        }
        int up = 1;
        Bitonic ob = new Bitonic();
        ob.sort(a, a.length,up);
        System.out.println("\nSorted array");
        printArray(a);
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


