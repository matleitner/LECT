package aula05.Ex5_1;
import aula05.Ex5_1.*;
// import java.util.Scanner;
public class DateYMD extends Date{
    

    public DateYMD(int day, int month, int year){
        super(day, month, year);
    }
    
    
   
    @Override
    public boolean equals(Object obj){
        if (this == obj) return true; 
            if (obj == null || getClass() != obj.getClass()) return false;
        DateYMD data = (DateYMD) obj;
        return this.getDay() == data.getDay() && data.getMonth() == this.getMonth() && data.getYear() == this.getYear(); 
        }
    


    
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

    @Override
    public String toString(){
        return day+ "-"+ month  +"-"+year; 
    }


    
    public static void main(String[] args){
        
                Date data = new DateYMD(1, 1, 2020);

                // System.out.println("Insira uma data: Dia/Mes/Ano");

                // String inputData = "04/2/2025";

                // String diaMesAno [] = inputData.split("/");

                // data.setDay(Integer.parseInt(diaMesAno[0]));

                // data.setMonth(Integer.parseInt(diaMesAno[1]));

                // data.setYear(Integer.parseInt(diaMesAno[2]));

                // System.out.println(monthDays(data.getMonth(), data.getYear()));
                
                System.out.println(data.increment(10));
                
    }



    
}


