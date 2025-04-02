package aula05.Ex5_1;

public abstract class Date{
    protected int day;
    protected int month;
    protected int year;
    public abstract void increment(int increment);
    
    public Date(int day,int month, int year){
        this.day = day;
        this.month = month;
        this.year = year;
    }
    
    
    public static boolean validMonth(int month){
        if (1 <= month && month <= 12 ) return true;
            return false;
        }

    public static int monthDays(int month, int year){
        if(month == 2){
            if(year%4== 0 &&  year%100==0){
                return 29;
            }
            return 28;
        }
        else if( month == 4 || month == 6 || month == 9|| month == 11 ) return 30;
        return 31;
    }
    public static boolean leapYear( int year ){
        if(year%400==0 || (year%4== 0 &&  year%100!=0)){
            return true;
        }
        return false;
    }


    public static boolean valid(int day, int month, int year){
        if(year > 0 && validMonth(month) && 0<= day && day <= monthDays(month, year)) return true; 
        
        return false;
    }



    }
