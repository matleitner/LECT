package aula05;
import aula03.CalendarioForm;
import java.util.ArrayList;
import java.util.Arrays;
import aula02.Extra;


public class Ex5_2 {
    static class  Calendario extends CalendarioForm  {
        private int year;
        private int month;
        private int day;
        private ArrayList<int[]> events = new ArrayList<>();

        public Calendario(int year, int month, int day){
            super(year,month,day);
            this.year = year;
            this.month = month;
            this.day = day;
        }

        public void setYear(int year){
            this.year = year;
        }
        public void setMonth(int month){
            this.month = month;
        }
        public void setDay(int day){
            this.day = day;
        }


        public int getYear(){
            return year;
        }

        public int getMonth(){
            return month;
        }

        
        public int getDay(){
            return day;
        }
        
        
        public void addEvent(int dia, int mes, int ano){
            events.add(new int[]{dia,mes,ano});
        }
        public void removeEvent(int dia, int mes, int ano){
            int [] toRemove = new int[]{dia,mes,ano};
            events.removeIf(array -> Arrays.equals(array, toRemove));
        }
        public boolean hasEvent(int dia, int mes, int ano) {
            for (int[] event : events) {
                if (Arrays.equals(event, new int[]{dia, mes, ano})) {
                    return true;
                }
            }
            return false;
        }

        public void printEvents() {
            for (int[] event : events) {
                System.out.println("Event: " + event[0] + "/" + (event[1]+1) + "/" + event[2] + "\t");
                
            }
        }
        
        public int firstWeekOfTheDay(){
            return Extra.getDayNumberOld(1,0,year)-1;
            
        }
        
        public int firstWeekdayOfMonth(int mes){
            return Extra.getDayNumberOld(1, mes, year)-1;
        }

        @Override
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
                            if(hasEvent(d, month, year))semanaDistribuida[getDayNumberOld(d, month    , year)-1] = -d;
                            else{semanaDistribuida[getDayNumberOld(d, month    , year)-1] = d;}
                            if(semanaDistribuida[6] != 0 || Extra.esteArrayTem(semanaDistribuida, Extra.monthDays(month, year))){
                                for (int a : semanaDistribuida){
                                    if(a !=0 ){
                                        if(a<0)
                                            if(a/10 == 0 ){
                                                System.out.print("*"+-a+" ");
                                            }
                                            
                                            else {
                                                System.out.print("*"+ -a + " ");
                                            }
                                        else{
                                            if(a/10 == 0 ){
                                                System.out.print(" "+a+" ");
                                            }
                                            
                                            else {
                                                System.out.print( a + " ");
                                            }

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
        
        @Override
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
                            if(hasEvent(d, mes, year))semanaDistribuida[getDayNumberOld(d, mes, year)-1] = -d;
                            
                            else semanaDistribuida[getDayNumberOld(d, mes, year)-1] = d;
                            
                            if(semanaDistribuida[6] != 0 || Extra.esteArrayTem(semanaDistribuida, Extra.monthDays(mes, year))){
                                for (int a : semanaDistribuida){
                                    if(a !=0 ){
                                        if(a<0)
                                            if(a/10 == 0 ){
                                                System.out.print("*"+-a+" ");
                                            }
                                            
                                            else {
                                                System.out.print("*"+ -a + " ");
                                            }
                                        else{
                                            if(a/10 == 0 ){
                                                System.out.print(" "+a+" ");
                                            }
                                            
                                            else {
                                                System.out.print( a + " ");
                                            }
    
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

        
}
    public static void main(String[] args){
        String[] daysOfTheWeek = {"Sunday", "Monday","Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        // String[] monhtOfYear = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Julh", "Ago", "Set", "Out", "Nov", "Dez"};
        Calendario calendar = new Calendario(2025, 1, 12);
        System.out.println(calendar+ " and the first day of the year is a " + daysOfTheWeek[calendar.firstWeekOfTheDay()] );
        calendar.addEvent(2, 1, 2024);
        // calendar.addEvent(2, 1, 1234);
        // calendar.addEvent(30, 1, 1234);
        calendar.addEvent(3, 1, 2024);
        calendar.addEvent(1, 7, 2025);
        
        calendar.printEvents();
        // calendar.removeEvent(1, 1, 1234);
        // calendar.printEvents();
        calendar.setMonth(1);
        
        // System.out.println(daysOfTheWeek[calendar.firstWeekdayOfMonth(1)]);
        // System.out.println(calendar);
        calendar.exporMesCalendario();
        calendar.removeEvent(1, 7, 2025);
        calendar.exporMesCalendario();
        calendar.showCalendar();    
        
    }
    
}


