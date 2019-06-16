import java.util.Scanner;

public class TaskB {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        for (int test = 1; test <= TC; ++test) {
            int n = sc.nextInt();
            String path = sc.next();
            StringBuilder result;
            int col = 1, row = 1;
            boolean[] flag = new boolean[n + 2];
            boolean[] cflag = new boolean[n + 2];
            for (int i = 0; i < 2*(n-1); ++i) {
                char c = path.charAt(i);
                if (c == 'E') {
                    col++;
                    flag[row] = true;
                } else {
                    row++;
                    cflag[col] = true;
                }
//                System.err.printf("(%d %d)\n", row, col);
            }
            result = new StringBuilder();
            int irow = 1;
            while (flag[irow]) irow++;
            int icol = n;
            while (cflag[icol]) icol--;
//            System.err.println(icol);
            for (int i = 2; i <= irow; ++i) result.append('S');
            for (int i = 2; i <= icol; ++i) result.append("E");
            for (int i = irow + 1; i <= n; ++i) result.append('S');
            for (int i = icol + 1; i <= n; ++i) result.append("E");

            System.out.printf("Case #%d: %s\n", test, result);
        }
    }
}
