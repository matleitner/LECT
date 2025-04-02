package aula07.Ex7_2;
import aula05.Ex5_1.Date;
public class DateND extends Date {
    private long daysDesde2000;

    public DateND(int day, int month, int year, long daysDesde2000){

        super(day, month, year);
        this.daysDesde2000= daysDesde2000;
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
    public static void main(String[] args){
        DateND ola = new DateND(12,12,12,0);
        System.out.println(ola);
    }
    
}
