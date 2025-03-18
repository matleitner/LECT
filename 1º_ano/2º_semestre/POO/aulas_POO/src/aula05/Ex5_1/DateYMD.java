package aula05.Ex5_1;
import aula02.Extra;

class DataDiaMesAno{
    int day;
    int month;
    int year;

    public DataDiaMesAno(int day, int month, int year){
        this.day = day;
        this.month = month;
        this.year = year;
    }
    
    
    public void setDay(int day){
        this.day = day;
    }

    public void setMonth(int month){
        this.month = month;
    }

    public void setYear(int year){
        this.year = year;
    }




    public int getDay(){
        return day;
    } 

    public int getMonth(){
        return month;
    } 

    public int getYear(){
        return year;
    } 


    public void increment(int incrementDays){
        while ( incrementDays > 0){
            int daysInMonth = Extra.monthDays(month, year); // Obtém os dias do mês atual
        
            if (day + incrementDays > daysInMonth) {
                // Avança para o próximo mês
                incrementDays -= (daysInMonth - day + 1);
                day = 1; // Reinicia o dia para o próximo mês
                month++;
                
                if (month > 12) { // Se passar de dezembro, avança para o próximo ano
                    month = 1;
                    year++;
                }
            } else {
                day += incrementDays;
                incrementDays = 0; // Finaliza o loop
            }
        }
    }

    @Override
    public String toString(){
        return day+ "-"+ month  +"-"+year; 
    }



    }


public class DateYMD {
    
    public static boolean validMonth(int month){
        if (1 <= month && month <= 12 ) return true;
        return false;
    }

    public static int monthDays(int month, int year){
        if(month == 2){
            if(year%4== 0 &&  year%100==0){
                return 28;
            }
            return 27;
        }
        else if( month == 4 || month == 6 || month == 9|| month == 11 ) return 30;
        return 31;
    }
    public static boolean leapYear( int year ){
        if(year%4== 0 &&  year%100==0){
            return true;
        }
        return false;
    }


    public static boolean valid(int day, int month, int year){
        if(year > 0 && validMonth(month) && 0<= day && day <= monthDays(month, year)) return true; 
        
        return false;
    }
    public static void main(String[] args){
        DataDiaMesAno data = new DataDiaMesAno(23, 1, 2023);
        System.out.println("Ola!" + valid(data.getDay(), data.getMonth(), data.getYear()));
        data.increment(112);
        System.out.println(data);
    
    }
}
