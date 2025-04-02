package aula05.Ex5_1;
// import java.util.Scanner;
public class DateYMD extends Date{
    

    public DateYMD(int day, int month, int year){
        super(day, month, year);
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
    @Override
    public void increment(int incrementDays){
        while ( incrementDays > 0){
            int daysInMonth = monthDays(month, year); // Obtém os dias do mês atual
        
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


    
    public static void main(String[] args){
        
                DateYMD data = new DateYMD(1, 1, 2020);

                System.out.println("Insira uma data: Dia/Mes/Ano");

                String inputData = "04/2/2025";

                String diaMesAno [] = inputData.split("/");

                data.setDay(Integer.parseInt(diaMesAno[0]));

                data.setMonth(Integer.parseInt(diaMesAno[1]));

                data.setYear(Integer.parseInt(diaMesAno[2]));

                System.out.println(monthDays(data.getMonth(), data.getYear()));
                
    }
}


