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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            Scanner read = new Scanner(System.in);
            int t = read.nextInt();
            while (t-- > 0) {
                int a = read.nextInt();
                int b = read.nextInt();
                int c = read.nextInt();
                int d = read.nextInt();
                System.out.println(b + " " + c + " " + c);
            }
        }

    }
}

