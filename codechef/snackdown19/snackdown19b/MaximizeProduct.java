import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class MAXPRODU {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0){
            String sssss[] = br.readLine().split(" ");
            int n =  Integer.parseInt(sssss[0]);
            int k =  Integer.parseInt(sssss[1]);
            int arr[] = new int[k+1];
            int mi = k*(k+1)/2;
            if(mi  > n){
                System.out.println("-1");
                continue;
            }
            
            int dif = n-mi;
            int q = dif/k;
            int r = dif%k;
            
            for(int i=1;i<=k;i++){
                arr[i] = i;
            }
            for(int i = k ; i >=1 ; i--){
                if(r>0){
                    arr[i] += 1;
                    r--;
                }
                arr[i] +=q;
            }
            
            long a = (long) Math.pow(arr[1] , 2) - arr[1];
            long answer = 1;
            long mod = 1000000007;
            a = a%mod;
            for(int i = 1; i<=k ; i++){
                a = ((long) Math.pow(arr[i] , 2) - arr[i])%mod;
                answer = (answer*a) % mod;
            }
            System.out.println(answer);
        }
    }
}