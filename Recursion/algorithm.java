/* 
 * Well defined input
 * well defined output
 * under the given time complexity
 * algorithm must be simple, understandable, practical, generic
 * 
 * Two types of algorithm:
 * a) Iterative (loop)
 * b) Recursive (recursion)
*/

import java.util.Scanner;

public class algorithm{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n;
        n=sc.nextInt();


        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.println("Diksha");     // time complexity is O(n^2)
            }
        }

        int m;
        m=sc.nextInt();


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                System.out.println("Diksha");     // time complexity is O(mn)
            }
        }


        for(int i=0; i<n; i++){
            System.out.println("Diksha");
        }
        for(int j=0; j<m; j++){
            System.out.println("Diksha");      // O(m+n)    
        }


        
        for(int i=1; i<=n; i=i*2){
            System.out.println("Hello");     // O(log base 2 n)
        }

        for(int i=1; i<=n; i=i*3){
            System.out.println("happy");        // O(log base 3 n)
        }


        for(int i=1; i*i<=n; i++){
            System.out.println("Hello");     // O(root(n))
        }


        // if we have <=n then wo terminate krne k liye bhi chalega!
        // diksha sinha is the best!
    }

}