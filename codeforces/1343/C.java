import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        CAlternatingSubsequence solver = new CAlternatingSubsequence();
        solver.solve(1, in, out);
        out.close();
    }

    static class CAlternatingSubsequence {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int t = in.nextInt();
            while (t-- > 0) {
                int n = in.nextInt();
                int[] a = new int[n];
                for (int i = 0; i < n; i++)
                    a[i] = in.nextInt();
                long ans = 0;
                int i = 0;
                while (i < n) {
                    long curr = a[i];
                    boolean pos = true;
                    if (a[i] < 0) pos = false;
                    int j = i + 1;
                    while (j < n) {
                        if (pos && a[j] < 0) break;
                        if (!pos && a[j] > 0) break;
                        curr = Math.max(curr, a[j]);
                        j++;
                    }
                    ans += curr;
                    i = j;

                }
                out.println(ans);
            }
        }

    }
}

