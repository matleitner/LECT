package aula02;
import java.util.Scanner;
public class Ex2_6 {
    public static void main(String[] args ){
            Scanner sc = new Scanner(System.in);

            String s = sc.nextLine();

            int caracteresNumericos = countDigits(s);

            int caracteresEspacos = countEspacos(s);



            System.out.println("Caracteres numericos: "+caracteresNumericos); 
            System.out.println("Caracteres especiais: " + caracteresEspacos);
            System.out.println("Sem espaços: " + tirarDoubleOuMaisEspacos(s));                
            
            
            sc.close();
    }
    public static int countDigits(String s){
        int counter = 0;
        for (int i = 0; i<s.length(); i++){
            if (Character.isDigit(s.charAt(i)))
            counter += 1;
        }
        return counter;
    }
    public static int countEspacos(String s){
        int counter = 0;
        for (int i = 0; i<s.length(); i++){
            if (s.charAt(i)==' '){
                counter+=1;
            };
        }
        return counter;
    }
    public static void muitosEspacos(String s){
        for (int i = 0; i<s.length()-1;i++ ){
            if(s.charAt(i) == ' ' && s.charAt(+1)== ' '){
                
            }
        }
    }
    public static String tirarDoubleOuMaisEspacos(String s){

        while (s.contains("  ")){
            s = s.replace("  ", " ");
            }
        return s;
    }
}
