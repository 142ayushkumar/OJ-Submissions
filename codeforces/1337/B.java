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
                int x = read.nextInt();
                int n = read.nextInt();
                int m = read.nextInt();
                while (x > 20 && n > 0) {
                    x = x / 2 + 10;
                    n--;
                }
                x -= 10 * m;
                if (x > 0) System.out.println("NO");
                else System.out.println("YES");
            }
        }

    }
}

