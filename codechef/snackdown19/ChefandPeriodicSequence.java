import java.util.Scanner;

class aaaa {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int tcc = sc.nextInt();
        while(tcc-- > 0){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i = 0; i< n; i++)
                arr[i] = sc.nextInt();
            int j = 0,i=0,c =0 ;            
            boolean fll = false;
            
            for(i=0; i<n ; i++){
                if(arr[i]  != -1){
                    j = i;
                    break;
                }
            }
            if(i==n){
                System.out.println("inf");
                continue;
            }
            
            for(i = j; i<n-1 ;i++){
                if(arr[i+1] == -1 || arr[i+1] == 1){
                    j=i;
                    break;
                }
                if(arr[i+1]-arr[i] != 1){
                    fll = true;
                    System.out.println("impossible");
                    break;
                }
            }
            
            if(fll)
                continue;
            
            int max = arr[j],vl =0;
            j++;
            c=0;
            boolean flag = true,flag22 = false,flag33 = false,flag44=false;
            
            for(i=j ; i< n;i++){
                if(flag){
                    if(arr[i] == -1){
                        c++;
                    }else if(arr[i]!=-1 && arr[i] == max+c+1){
                        max +=c+1;
                        c=0;
                    }else if(arr[i] != -1){
                        int cc = max + c - arr[i] + 1;
                        if(cc >= max)
                            max = cc;
                        else if(cc<max){
                            flag22 = true;
                            System.out.println("impossible");
                            break;
                        }
                        vl = arr[i]-1;
                        i--;
                        flag = false;
                        c=0;
                    }
                }else{
                    flag44 = true;
                    if(arr[i] != -1 && arr[i] != (vl%max  + 1)){
                        flag33 = true;
                        System.out.println("impossible");
                        break;
                    }
                    vl++;
                }
            }
            
            if(flag22 || flag33)
                continue;
            if(!flag44){
                System.out.println("inf");
                continue;
            }
            System.out.println(max);
        }
    }
    
}