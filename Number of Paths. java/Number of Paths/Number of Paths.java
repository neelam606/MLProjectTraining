import java.io.*;
import java.util.*;

public class Main {

  public static void main (String [] args) throws Exception {
    int MOD = 1000000007;
    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = br.readLine();
    StringTokenizer st = new StringTokenizer(line);
    int n = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
  
    int nis [] = new int[n+1];
    for (int i = 1; i <= n; ++i){
      nis[i] = Integer.parseInt(br.readLine());
    }

  
    long [] f = new long[200002];
    long [] g = new long[200002];
    f[b] = 1L;
    g[b] = 1L;
    

    for (int i=b-1; i>=1; --i){
      f[i] = g[i+1] - g[i+nis[i]+1];
      f[i] = (f[i] + MOD)%MOD;
      g[i] = g[i+1] + f[i];
      g[i] = (g[i] + MOD)%MOD;
    }
    
    int q = Integer.parseInt(br.readLine());
    for (int i = 0; i < q; ++i){
      System.out.println(f[Integer.parseInt(br.readLine())]);
    }
  }
}


