package aula07.Ex7_2;
import aula05.Ex5_1.*;

public class DateND extends Date {
    private long daysDesde2000;


    public DateND(int day, int month, int year){
        super(day, month, year);
    }
    public void setDaysDesde2000( long daysDesde2000){this.daysDesde2000 =daysDesde2000;}
    public long getDaysDesde2000(){return daysDesde2000;}
    @Override
    public Date increment(int incrementDays){
        
        while (incrementDays > 0){
            int daysInMonth = monthDays(this.getMonth(), this.getYear()); 
        
            if (this.getDay() + incrementDays > daysInMonth) {
                
                incrementDays -= (daysInMonth -this.getDay() + 1);
                this.setDay(1); 
                this.setMonth(this.getMonth()+1);
                
                if (this.getMonth() > 12) { 
                    this.setMonth(1);
                    this.setYear(this.getYear()+1);
                }
            } else {
                this.setDay(this.getDay()+incrementDays);
                incrementDays = 0; 
            }
        }
        this.setDay(this.getDay());
        this.setMonth(this.getMonth());
        this.setYear(this.getYear());
        return this;
    }

    

    
    public long numberOfDays(DateND data){
        
        if(data.getDay()> monthDays(data.getMonth(), data.getYear()) || 0 <= data.getDay() || 0 >= data.getMonth() || data.getYear() <= 0 || data.getMonth() > 12)
        return -1; 
        
        
        int counter = 0;
        DateND copy = new DateND(this.getDay(), this.getMonth(), this.getYear());
        
        while (!copy.equals(data)){
            ++counter;

            copy.increment(1);
        }

        
        this.setDaysDesde2000(counter);
        return daysDesde2000;
    }

    
    @Override
    public String toString(){
        return day+ "/" + month + "/" + year;
    }
    
    public static void main(String[] args){
        DateND primeiroDeJaneiro2000 = new DateND(1,1,2000);
        DateND data = new DateND(29, 2, 2000);
        
        
        System.out.println("Dias de: "+ primeiroDeJaneiro2000 +" até "+ primeiroDeJaneiro2000.numberOfDays(data));
    }
    
}
