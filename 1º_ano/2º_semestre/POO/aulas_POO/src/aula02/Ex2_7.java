package aula02;
import java.util.Scanner;
public class Ex2_7 {
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Introduza uma frase:");
        String[] palavras = sc.nextLine().split(" ");
        String acronimo = "";
       
        for (String word : palavras){
            
            if (word.length()>=3){
                acronimo+=word.charAt(0);
            }
        }

        System.out.println("Acrónimo: "+ acronimo.toUpperCase());
        
        sc.close();
    }
    
}
