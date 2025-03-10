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
        System.out.println(resposta);
        int tentativa = 0;
        System.out.println(numero);

        if (resposta.toUpperCase().equals("SIM") || resposta.toUpperCase().equals("S"))
        {while(true)
            {
                tentativa++;
                System.out.println("Insira um numero");
                int guess = Extra.Verificador();
                
                if (guess == numero){System.out.print("BOUA"+ tentativa); break;}

                else if (guess < numero) System.out.println("O numero que estou a pensar é maior que isso");

                else System.out.println("O numero que estou a pensar é menor que isso");

            }
        
        }


        sc.close();
    }
    
}
