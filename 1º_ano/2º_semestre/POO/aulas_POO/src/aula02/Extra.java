package aula02;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;
// import java.time.LocalDate;
// import java.time.Month;

import java.util.ArrayList;
public class Extra {
    public static void main(String[] args){
        // System.out.println(isPrime(123));
        // int ola = LocalDate.now().getYear();
        // System.out.println(ola);
        // Calendar ola = new GregorianCalendar(2025,0,31);
        ArrayList<String[]> aaa = new ArrayList<>();
        System.out.println(aaa);
        String var = "Leitnermmartim@ua.pt.pt";

        System.out.println(var.split("@"));
        System.out.println(var.split("."));

        for(String a : var.split("\\."))System.out.println(a);
        // System.out.println(ola.get(Calendar.DAY_OF_WEEK));
    }        
    
        
    public static int Verificador(){
        
        Scanner scan = new Scanner(System.in);
        int numeroInteiro = scan.nextInt();
        while (numeroInteiro<0)
        {
            System.out.println("Insira um número válido por favor: ");
            numeroInteiro = scan.nextInt();  
        }
        //isto tem de estar comentado para o 3_2 funcionar... 
        //scan.close();
        return numeroInteiro;
    }

    public static boolean isPrime(int num){
        for(int i= num-1; i>=2; i-- )
         {
            if (num%i==0) { return false;}
        }
        
        return true; 
    }


    // ano bisexto 



    
    public boolean leapYear( int year ){
        if(year%4== 0 &&  year%100==0){
            return true;
        }
        return false;
    }

    // dia de cada mes 
    public static int monthDays(int month, int year){
        month = month--;
        if(month == 2){
            if(year%400==0 || (year%4== 0 &&  year%100!=0)){
                return 29;
            }
            return 28;
        }
        else if( month == 4 || month == 6 || month == 9|| month == 11 ) return 30;
        return 31;
    }

    public static boolean esteArrayTem(int[] numbers, int target){
        for (int num : numbers) {
            if (num == target) {
                return true;
                
            }
        }
        return false;
    }


        public static  int getDayNumberOld(int dia, int mes, int ano)
        // meter aqui inteiros como argumentos e antes de chamar a funcao no main dividir a string 
        {
            Calendar cal = new GregorianCalendar(ano ,mes , dia);
            return cal.get(Calendar.DAY_OF_WEEK);
        }

        public static boolean allZero(int[] array){
            for(int a: array){
                if(a==0) return false;
            }
            return true;
        }

        
        
            }

