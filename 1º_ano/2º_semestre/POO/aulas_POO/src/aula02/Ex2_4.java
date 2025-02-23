package aula02;
import java.util.Scanner;
import java.util.ArrayList;

public class Ex2_4 {
    public static void main(String[] args){
        ArrayList<Integer> numeros = new ArrayList<Integer>();
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Instoduza uma número:");
        int primeironum = sc.nextInt();
        numeros.add(primeironum);
        
        int sum = 0; 
        
        
        
        while(true){
            System.out.println("Instoduza uma número:");
            int num = sc.nextInt();                        
            if (num==primeironum){
                break;
            } 
            numeros.add(num);
        }
        for (int i = 0;i<numeros.size(); i++){
            sum += numeros.get(i);
        }
        double media =(double) sum/numeros.size();

        int minimo = Minimo(numeros);
        int maximo = Maximo(numeros);
        
        System.out.println( numeros);
        System.out.printf("%.1f%n", media);
        System.out.println(minimo);
        System.out.println(maximo);
        
        
        sc.close();
        
    }
    public static int Minimo(ArrayList<Integer> nums ){
        int minimo = nums.get(0);
        for (int i = 1; i<nums.size(); i++){
            if (minimo>nums.get(i)){
                minimo = nums.get(i);
            }
        }
        return minimo;
    }

    public static int Maximo(ArrayList<Integer> nums ){
        int maximo = nums.get(0);
        for (int i = 1; i<nums.size(); i++){
            if (maximo<nums.get(i)){
                maximo = nums.get(i);
            }
        }
        return maximo;
    }
}
