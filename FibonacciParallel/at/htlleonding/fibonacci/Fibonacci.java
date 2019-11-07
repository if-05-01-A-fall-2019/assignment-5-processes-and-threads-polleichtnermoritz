/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package at.htlleonding.fibonacci;

/**
 *
 * @author moritz
 */
public class Fibonacci {
    static int number = 1;
    static int getNumberSingle(int n) {
        if (n < 2)
            return 1;
        else
            return getNumberSingle(n - 1) + getNumberSingle(n - 2);
    }
    
    static int getNumberParallel(int n) {
        Thread t1 = new Thread(new Runnable() {
            
            @Override
            public void run() {
                number++;
            }
        });
        if(n < 2){
            t1.start();
        }
        else{   
            return getNumberParallel(n-1) + getNumberParallel(n-2);  
        }  
        return 1;
    }
    
}
