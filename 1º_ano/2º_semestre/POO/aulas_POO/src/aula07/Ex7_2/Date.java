package aula07.Ex7_2;

public abstract class Date implements Comparable<Date>{
    protected int day;
    protected int month;
    protected int year;
    public abstract Date increment(int increment);
    
    
    
    public Date(int day,int month, int year){
        this.day = day;
        this.month = month;
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
    public void setDay(int day){
        this.day = day;
    }

    public void setMonth(int month){
        this.month = month;
    }

    public void setYear(int year){
        this.year = year;
    }

    @Override
    public boolean equals(Object obj){
        if (this == obj) return true; 
            if (obj == null || getClass() != obj.getClass()) return false;
        Date data = (Date) obj;
        return this.getDay() == data.getDay() && data.getMonth() == this.getMonth() && data.getYear() == this.getYear(); 
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
        if(year > 0 && validMonth(month) && 0< day && day <= monthDays(month, year)) return true; 
        
        return false;
    }
    @Override
    public String toString(){
        return this.getDay()+ "-"+ this.getMonth()  +"-"+this.getYear();
    }
    @Override
    public int compareTo(Date other) {
        if (this.year != other.year)
            return this.year - other.year;
        if (this.month != other.month)
            return this.month - other.month;
        return this.day - other.day;
    }
    }
