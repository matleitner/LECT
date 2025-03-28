package aula02;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;
public class Extra {
    public static void main(String[] args){
        System.out.println(isPrime(123));
    }        
    
        
    public static int Verificador(){
        
        Scanner sc = new Scanner(System.in);
            int numeroInteiro = sc.nextInt();
        
            while (numeroInteiro<0)
            {
                System.out.println("Insira um número válido por favor: ");
                numeroInteiro = sc.nextInt();  
            }
        
        sc.close();
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
        if(month == 1){
            if(year%400==0 || (year%4== 0 &&  year%100!=0)){
                return 29;
            }
            return 28;
        }
        else if( month == 3 || month == 5 || month == 8|| month == 10 ) return 30;
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


