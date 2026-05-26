// import java.util.*;

// public class EGoodTriples {
//     public static List<int[]> findTriplets(int n) {
//         List<int[]> result = new ArrayList<>();

//         for (int a = 0; a <= n; a++) {
//             for (int b = 0; b <= n - a; b++) {
//                 int c = n - a - b;
//                 // System.out.println(a + " " + b + " " + c);
//                 result.add(new int[] { a, b, c });
//             }
//         }

//         return result;
//     }

//     public static int dig(int n) {
//         int sum = 0;

//         while (n > 0) {
//             sum += n % 10; // last digit
//             n /= 10; // remove last digit
//         }

//         return sum;
//     }

//     static void getthemap(Map<Integer, ArrayList<Integer>> mpp) {
//         for (int i = 0; i <= 1000000; i++) {

//             int val = dig(i);

//             // create list if key not present
//             if (!mpp.containsKey(val)) {
//                 mpp.put(val, new ArrayList<>());
//             }

//             // add i to the list
//             mpp.get(val).add(i);
//         }
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);

//         Map<Integer, ArrayList<Integer>> mpp = new HashMap<>();
//         getthemap(mpp);
//         // for (Map.Entry<Integer, ArrayList<Integer>> entry : mpp.entrySet()) {

//         //     int key = entry.getKey();
//         //     ArrayList<Integer> list = entry.getValue();

//         //     System.out.print(key + " -> ");

//         //     // print only first 10 elements
//         //     for (int i = 0; i < Math.min(10, list.size()); i++) {
//         //         System.out.print(list.get(i) + " ");
//         //     }

//         //     System.out.println("... size = " + list.size());
//         // }
//         int t = sc.nextInt();
//         while (t-- > 0) {
//             int n = sc.nextInt();
//             int d = dig(n);
//             List<int[]> all = findTriplets(d);
//             System.out.println(d);
//             System.out.println(all.size());
//             // int maxi = 0;
//             // int kiki = 0;
//             int ans = 0;
//             for (int[] trip : all) {
//                 int a = trip[0];
//                 int b = trip[1];
//                 int c = trip[2];
//                 ArrayList<Integer> list1 = mpp.get(a);
//                 ArrayList<Integer> list2 = mpp.get(b);
//                 ArrayList<Integer> list3 = mpp.get(c);
//                 for (int x : list1) {
//                     for (int y : list2) {
//                         for (int z : list3) {
//                             if (x + y + z == n) {
//                                 ans++;
//                             }
//                         }
//                     }
//                 }
//             }
//             // System.out.println(maxi);
//             // System.out.println(kiki);
//             System.out.println(ans);

//         }


//         sc.close();
//     }
// }



import java.util.*;

public class EGoodTriples {

    static long ways(int d) {
        return (long)(d + 1) * (d + 2) / 2;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {
            long n = sc.nextLong();
            long ans = 1;
            while (n > 0) {
                int digit = (int)(n % 10);
                ans *= ways(digit);
                n /= 10;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}