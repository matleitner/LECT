package aula03;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;
import aula02.Extra;


public class CalendarioForm {
    private int year;
    private int month;
    private int day;
    
    protected CalendarioForm(int year, int month, int day){
        this.year = year;
        this.month = month;
        this.day = day;
    }
    public void  exporMesCalendario(){
        int[] semanaDistribuida = new int[7];
        
        String[] months = {
            "January", "February", "March", "April", "May", "June", 
            "July", "August", "September", "October", "November", "December"
        };
    
            
                System.out.print("---------------------\n         " + year + "\n");          
                
                    if (months[month].length()<=4)
    
                    System.out.printf("\n %10s ", months[month]);          
                    else if(months[month].length() == 6 )
                    System.out.printf("\n %12s ", months[month]);
                            
                    else if(months[month].length() == 5 )
                    System.out.printf("\n %11s ", months[month]);
                    
                    else                          
                    System.out.printf("\n %13s ", months[month]);          
                    
                    
                    System.out.println("\nSu Mo Tu We Th Fr Sa");
                    for (int d= 1; d<= Extra.monthDays(month,year); d++){
                        semanaDistribuida[getDayNumberOld(d, month    , year)-1] = d;
                        if(semanaDistribuida[6] != 0 || Extra.esteArrayTem(semanaDistribuida, Extra.monthDays(month, year))){
                            for (int a : semanaDistribuida){
                                if(a !=0 ){
                                        if(a/10 == 0 ){
                                            System.out.print(" "+a+" ");
                                        }
                                        
                                        else {
                                            System.out.print( a + " ");
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
    
    
    public void showCalendar(){         
        int[] semanaDistribuida = new int[7];
        
        String[] months = {
            "January", "February", "March", "April", "May", "June", 
            "July", "August", "September", "October", "November", "December"
        };
    
            
                System.out.print("---------------------\n         " + year + "\n");          
                for (int mes = 0; mes<=11 ; mes ++){
                    if (months[mes].length()<=4)
    
                    System.out.printf("\n %10s ", months[mes]);          
                    else if(months[mes].length() == 6 )
                    System.out.printf("\n %12s ", months[mes]);
                            
                    else if(months[mes].length() == 5 )
                    System.out.printf("\n %11s ", months[mes]);
                    
                    else                          
                    System.out.printf("\n %13s ", months[mes]);          
                    
                    
                    System.out.println("\nSu Mo Tu We Th Fr Sa");
                    for (int d= 1; d<= Extra.monthDays(mes,year); d++){

                        semanaDistribuida[getDayNumberOld(d, mes, year)-1] = d;
                        if(semanaDistribuida[6] != 0 || Extra.esteArrayTem(semanaDistribuida, Extra.monthDays(mes, year))){
                            for (int a : semanaDistribuida){
                                if(a !=0 ){
                                        if(a/10 == 0 ){
                                            System.out.print(" "+a+" ");
                                        }
                                        
                                        else {
                                            System.out.print( a + " ");
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
    
        public int getDayNumberOld(int dia, int mes, int ano)
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




class CalendarioEx3_6 {
    public static void main(String[] args){
        // String[] daysOfTheWeek = {"Sunday", "Monday","Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        // Calendario cacalendario = new Calendario(2025 ,1 ,12);
        CalendarioForm cal1 = new CalendarioForm(1921, 1, 12);
        // cacalendario.exporMesCalendario();
        cal1.exporMesCalendario();
        // cal1.showCalendar();
        
    }
}
