import java.util.Scanner;

public class TaskA {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int TC = scanner.nextInt();
        scanner.skip("\n");
        for(int T = 1;T<=TC;++T) {
            String n = scanner.nextLine();
            StringBuilder a = new StringBuilder();
            StringBuilder b = new StringBuilder();
            for (int i = 0; i < n.length(); ++i) {
                char c = n.charAt(i);
                a.append(c == '4' ? '2' : c);
                b.append(c == '4' ? '2' : '0');
            }

            int k = b.indexOf("2");
            b.delete(0, k);
            System.out.printf("Case #%d: %s %s\n",T, a, b);
        }
    }
}
