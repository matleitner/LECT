package aula03;
import java.util.Calendar;
import java.util.GregorianCalendar;
import aula02.Extra;



    public class CalendarioEx3_6 {
    public static int getDayNumberOld(int dia, int mes, int ano)
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
    
    public static void main(String[] args){
        
        int[] semanaDistribuida = new int[7];
    
        String[] months = {
            "January", "February", "March", "April", "May", "June", 
            "July", "August", "September", "October", "November", "December"
        };
        for (int y = 2000; y<=2023; y ++){
            System.out.print("---------------------\n         " + y + "\n");          
            for (int m = 0; m<=11 ; m ++){
                if (months[m].length()<=4)
 
                System.out.printf("\n %10s ", months[m]);          
                else if(months[m].length() == 6 )
                System.out.printf("\n %12s ", months[m]);
                          
                else if(months[m].length() == 5 )
                System.out.printf("\n %11s ", months[m]);
                
                else                          
                System.out.printf("\n %13s ", months[m]);          
                
                
                System.out.println("\nSu Mo Tu We Th Fr Sa");
                for (int d= 1; d<= Extra.monthDays(m,y); d++){

                    semanaDistribuida[getDayNumberOld(d, m, y)-1] = d;
                    
                    if(semanaDistribuida[6] != 0 || Extra.esteArrayTem(semanaDistribuida, Extra.monthDays(m, y))){
                        for (int a = 0; a < semanaDistribuida.length; a++){
                            if(semanaDistribuida[a] !=0 ){
                                    if(semanaDistribuida[a]/10 == 0 ){
                                        System.out.print(" "+semanaDistribuida[a]+" ");
                                    }
                                    
                                    else {
                                        System.out.print( semanaDistribuida[a] + " ");
                                    }

                            }
                            else{
                                    System.out.print("   ");
                            }
                        }
                    
                        System.out.println();
                        semanaDistribuida = new int[7];
                    }
                }
            }
        } 
        System.out.println("\n");

                                        
    }
} 
