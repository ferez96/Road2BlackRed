
import java.util.*;

public class TaskCS {

    static class Pair<T> {
        T x;
        T y;

        Pair(T x, T y) {
            this.x = x;
            this.y = y;
        }

    }

    static int gcd(int a, int b) {
        if (a > b) return gcd(b, a);
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    static Pair<Integer> split(int num) {
        for (int i = 2; i <= Math.sqrt(num); ++i) {
            if (num % i == 0) return new Pair<>(i, num / i);
        }
        return new Pair<>(1, num);
    }

    static int c[] = new int[102];
    static int p[] = new int[102];
    static HashMap<Integer, Character> dictionary = new HashMap<>();
    static SortedSet<Integer> nums = new TreeSet<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        for (int test = 1; test <= TC; test++) {
            dictionary.clear();
            nums.clear();
            StringBuilder ans = new StringBuilder();

            int n = sc.nextInt();
            int l = sc.nextInt();
            for (int i = 0; i < l; ++i) {
                c[i] = sc.nextInt();
            }

            int firstDiff = -1;
            for (int i = 0; i < l - 1; ++i) {
                if (c[i] != c[i + 1]) {
                    firstDiff = i;
                    break;
                }
            }

            if (firstDiff == -1) {
                int x = (int) Math.sqrt(c[0]);
                if (x * x == c[0]) {
                    for (int i = 0; i < l + 1; ++i) ans.append("A");
                } else {
                    for (; ans.length() + 2 <= l + 1; ) ans.append("AB");
                    if (ans.length() == l) ans.append("A");
                }
            } else {
                p[firstDiff] = c[firstDiff]/gcd(c[firstDiff],c[firstDiff+1]);
                for(int i=firstDiff+1;i<l+1;++i) p[i] = c[i-1]/p[i-1];
                for(int i=firstDiff-1;i>=0;--i) p[i] = c[i]/p[i+1];

                for (int i = 0; i < l + 1; ++i) nums.add(p[i]);
                char v = 'A';
                for (int k : nums) dictionary.put(k, v++);
                for(int i=0;i<l+1;++i) ans.append(dictionary.get(p[i]));
            }
            System.out.printf("Case #%d: %s\n", test, ans);
        }
    }
}
