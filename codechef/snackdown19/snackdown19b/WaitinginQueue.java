import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class QUEUE2 {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0){
            String sssss[] = br.readLine().split(" ");
            
            int n =  Integer.parseInt(sssss[0]);
            int m =  Integer.parseInt(sssss[1]);
            int k =  Integer.parseInt(sssss[2]);
            int l =  Integer.parseInt(sssss[3]);
            
            int array1[] = new int[n+1];
            int array2[] = new int[n+1];
            int waiting[] = new int[n+1];
            
            String st[] = br.readLine().split(" ");
            for(int i = 0; i < n; i++){
                array1[i] = Integer.parseInt(st[i]);
            }
            Arrays.sort(array1,0,n);
            
            int in = 0;
            for(int i = n-1; i>=0;i++){
                if(array1[i] < k){
                    in = i;
                    break;
                }
            }
            
            if(array1[in+1] > k || array1[in+1] == 0)
                array1[in+1] = k;
            
            for(int i = in+1; i > 0; i--){
                array2[i] = array1[i] - array1[i-1];
            }
            array2[0] = array1[0];
            
            int wt = m*l;
            int min = Integer.MAX_VALUE;
            int ii=0;
            
            for(int i = 0; i <= in+1 ; i++){
                waiting[i] = wt - array2[i] + l;
                wt = waiting[i];
                if(min > waiting[i]){
                    ii = i;
                    min = waiting[i];
                }
            }
            System.out.println(min<0?0:min);
        }
    }
}