import java.util.*;
import java.lang.*;
import java.io.*;

public class TreeInMaking
{     
    public static void main (String[] args)
    {
        // your code goes here  
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        int i,j;
        while(t-->0){
                int n=sc.nextInt();
                int d=sc.nextInt();
                int l=sc.nextInt();
                if(n<d+1){
                System.out.println(-1);
                }
                else if(n-d-1<(l-2))
                System.out.println(-1);
                else{
                    int half=d/2;
                    int node=1;
                    while(half>0){
                        System.out.println(node+" "+(node+1));
                        node++;
                        half--;
                    }
                    half=d-d/2;
                    node++;
                    int prev=1;
                    while(half>0){
                        System.out.println(prev+" "+node);
                        prev=node;
                        node++;
                        half--;
                    }
                    int temp=l-2;
                    while(temp>0){
                        System.out.println(1+" "+node);
                        node++;
                        temp--;
                    }
                }
        }
    }
}