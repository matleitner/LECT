package aula02;
import java.util.Scanner;
public class Ex2_3 {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Insira valor cateto A:");
    int cateto_a = sc.nextInt();
    System.out.println("Insira valor cateto B:");
    int cateto_b = sc.nextInt();

    double hipotenusa_c = Math.sqrt(Math.pow(cateto_a,2)+Math.pow(cateto_b,2));
    double angulo_A_C = (Math.asin(cateto_b/hipotenusa_c));
    System.out.print("O valor da hipotenusa do trinângulo é: " + hipotenusa_c);
    System.out.print("O valor do ângulo A^C é: "+ Math.round( Math.toDegrees(angulo_A_C))+"º");

    }
}
