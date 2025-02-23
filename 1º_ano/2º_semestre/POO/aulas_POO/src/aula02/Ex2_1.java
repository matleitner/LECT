package aula02;
import java.util.Scanner;



public class Ex2_1 {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Insira um tempo em segundos:");
        int seg = sc.nextInt();
        int hora = seg /3600;
        int minutos = (seg %3600)/60;
        int s = (seg%3600%60);
        System.out.println(hora+":"+minutos+":"+s);
        sc.close();
        
    }
}
