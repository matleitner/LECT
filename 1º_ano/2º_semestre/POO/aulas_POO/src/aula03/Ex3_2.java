package aula03;
import java.util.Scanner;
import aula02.Extra;
public class Ex3_2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Vamos jogar um jogo, eu vou pensar num numero de 1 a 100 e tu vais tentar adivinha-lo!");
        int guess = sc.nextInt();
        
        int n = 100;
        int numero =(int) (Math.random() * n);
        System.out.println(numero);
        while(true){
            guess = Extra.Verificador();

            if (guess< numero) {
                
                System.out.println("O numero que eu estou a pensar é maior que isso...");
                    guess = sc.nextInt();
            }
            else if (guess> numero){
                System.out.println("O numero que eu estou a pensar é menor que isso...");
                    guess = sc.nextInt();
            }
            else {
                System.out.println("O numero que eu estou a pensar é exatamente esse!\n PARABÉNS!!!!");
                break;
            }
        }
        sc.close();
    }
    
}
