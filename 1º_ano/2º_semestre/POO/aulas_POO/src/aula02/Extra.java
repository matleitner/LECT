package aula02;
import java.util.Scanner;
public class Extra {
    public static void main(String[] args){
        System.out.println(isPrime(123));
    }        
    
        
    public static int Verificador(){
        
        Scanner sc = new Scanner(System.in);
            int numeroInteiro = sc.nextInt();
        
            while (numeroInteiro<0)
            {
                System.out.println("Insira um número válido por favor: ");
                numeroInteiro = sc.nextInt();  
            }
        
        sc.close();
        return numeroInteiro;
            }

    public static boolean isPrime(int num){
        for(int i= num-1; i>=2; i-- )
         {
            if (num%i==0) { return false;}
        }
        
        return true; 
    }
}


