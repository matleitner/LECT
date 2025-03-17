package aula03;
import java.util.Scanner;
public class Testarcoisas {
    public static void main(String[] args )
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Austria");
        String mensagem = sc.nextLine();

        while(mensagem.equals("Sim")){

            System.out.println("Portugal");

            int guess = sc.nextInt();
            System.out.println(guess + "Olá");
        }
    sc.close();
    }
}
