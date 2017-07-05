/* 7/5/2017
 * Problem: http://codeforces.com/problemset/problem/522/A
 * Others: Suddenly want to try JAVA - -AC on first attempt.. wow 
 */
import java.io.*;
import java.util.*;

public class test {

    public static Map<String, Set<String>> mp = new HashMap();
    public static int max = 0;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 1; i <= n; i++) {
            String s1, s2, s3;
            s1 = in.next();
            s2 = in.next();
            s3 = in.next();
            // System.out.println(s1);
            if (!mp.containsKey(s3.toLowerCase())) {
                Set<String> tmp = new HashSet();
                mp.put(s3.toLowerCase(), tmp);
            }
            mp.get(s3.toLowerCase()).add(s1.toLowerCase());
            //System.out.println(mp.get(s3));
        }
        // System.out.println(mp.get("tourist"));
        dfs("polycarp", 2);
        System.out.println(max);
    }

    public static void dfs(String s, int depth) {
        if (mp.get(s) != null) {
            // System.out.println(mp.get(s));
            for (String r: mp.get(s)) {
                // System.out.println(r);
                if (depth > max) {
                    max = depth;
                }
                dfs(r, depth + 1);
            }
        }
    }

}
