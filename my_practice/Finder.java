//import java.util.Scanner;

import java.util.Scanner;
/*
public class Finder {
        public  static int quickSelect ( int[] a, int low, int high, int k){
            int part = partition(a, low, high);
            if (k == part - low + 1) return a[part];
            else if (k >  part - low + 1) return quickSelect
                    (a, part + 1, high, k - part + low - 1);
            else return quickSelect(a, low, part - 1, k);
        }
        public static int partition ( int[] a, int low, int high){
            int key = a[low];
            while (low < high) {
                while (low < high && a[high] <= key) high--;
                a[low] = a[high];
                while (low < high && a[low] > key) low++;
                a[high] = a[low];
            }
            a[low] = key;
            return low;
        }
    public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            int n=sc.nextInt();
            int[] arr = new int[n];
            for(int i=0; i<n; i++){
                arr[i] = sc.nextInt();
            }
        System.out.println(quickSelect(arr,0,n-1,2));
    }
    }

*/
import java.util.Scanner;
public class Finder {
    public  static int quickSelect ( int[] a, int low, int high, int k){
        int part = partition(a, low, high);
        if (k == part - low + 1) return a[part];
        else if (k > part - low + 1) return quickSelect
                (a, part + 1, high, k - part + low - 1);
        else return quickSelect(a, low, part - 1, k);
    }
    public static int partition ( int[] a, int low, int high){
        int key = a[low];
        while (low < high) {
            while (low < high && a[high] <= key) high--;
            a[low] = a[high];
            while (low < high && a[low] > key) low++;
            a[high] = a[low];
        }
        a[low] = key;
        return low;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(quickSelect(arr,0,n-1,2));
    }
}

