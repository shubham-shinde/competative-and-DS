import java.util.*;
import java.io.*;

class STR_PWD {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int testcase = Integer.parseInt(br.readLine());
        while(testcase-- >0){
            String strings = br.readLine();
            
            char arr[] = strings.toCharArray();
            int a = 0,b=0,c=0,d=0;
            for(int i = 0; i< strings.length(); i++){
                if(arr[i]>=65 && arr[i] < 91)
                    a=1;
                else if(arr[i]>=97 && arr[i] < 123)
                    b=1;
                else if(arr[i]>=48 && arr[i] < 58)
                    c=1;
                else if(arr[i]==33 || arr[i]==64 || arr[i]==35 || arr[i]== 36 || arr[i]== 37 || arr[i]==38)//!,@,#,$,%,&
                    d=1;
            }
            System.out.println(a+b+c+d);
        }


    }


}