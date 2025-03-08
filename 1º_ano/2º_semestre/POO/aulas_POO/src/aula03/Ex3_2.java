package aula03;
import java.util.Scanner;
import aula02.Extra;
public class Ex3_2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Vamos jogar um jogo, eu vou pensar num numero de 1 a 100 e tu vais tentar adivinha-lo!");
        System.out.println("Deseja jogar?");

        String resposta = sc.next();
        int numero =(int) (Math.random() * 100 +1);
        int guess;
        System.out.println(resposta);
        System.out.println(numero);
       
        while(true)
        {
            if(!(resposta.toUpperCase().equals("SIM") || resposta.toUpperCase().equals("S"))){
                
            System.out.println("Obrigado"); 
            break;}
            
            System.out.print("Insira um numero 0 a 100: ");
            do {guess = sc.nextInt();
            guess = Extra.Verificador(guess);
            if (guess < numero)System.out.println("O numero que eu estou a pensar é maior que isso...");
                
                
            else if (guess > numero)
                System.out.println("O numero que eu estou a pensar é menor que isso...");                

                
            else {
                System.out.println("O numero que eu estou a pensar é exatamente esse!\n PARABÉNS!!!!");

                }
            }
            while(guess != numero);


            System.out.println("Deseja continuar?");
            
            resposta = sc.next();
        }


        sc.close();
    }
    
}
