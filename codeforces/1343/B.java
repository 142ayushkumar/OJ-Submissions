import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Kumar Ayush
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            Scanner read = new Scanner(System.in);
            int t = read.nextInt();
            while (t-- > 0) {
                int n = read.nextInt();
                n /= 2;
                if (n % 2 == 0) {
                    System.out.println("YES");
                    int curr = 2, tot = 0;
                    for (int i = 0; i < n; i++) {
                        tot += curr;
                        System.out.print(curr + " ");
                        curr += 2;
                    }
                    curr = 1;
                    for (int i = 0; i < n - 1; i++) {
                        tot -= curr;
                        System.out.print(curr + " ");
                        curr += 2;
                    }
                    System.out.print(tot + "\n");
                } else {
                    System.out.println("NO");
                }
            }
        }

    }
}

