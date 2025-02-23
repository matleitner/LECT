package aula02;
import java.util.Scanner;
public class Ex2_5 {
    public static void main(String[] args){
        System.out.printf("Insira coisas bonitas!%n");
        Scanner sc = new Scanner(System.in);
        String coisas = sc.nextLine();
        coisas = coisas.toLowerCase(); 
        System.out.println(coisas);
        System.out.println(coisas.charAt(coisas.length()-1));
        System.out.println(coisas.substring(coisas.length()-3));
        sc.close();


    }
}
