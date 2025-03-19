package aula03;
import java.util.Date;
import java.util.Calendar;
import java.util.GregorianCalendar;
import aula02.Extra;

    public class CalendarioEx3_6 {
    public static int getDayNumberOld(String date) 
    // meter aqui inteiros como argumentos e antes de chamar a funcao no main dividir a string 
    {
        //expected to be dd/mm/yy format
        String data [] = date.split("/");

        Calendar cal = new GregorianCalendar(Integer.parseInt(data[2]), Integer.parseInt(data[1])-1 ,Integer.parseInt(data[0]));
        return cal.get(Calendar.DAY_OF_WEEK);
}
    public static void main(String[] args){
        
        int dayNumber = getDayNumberOld("10/07/2010");
        // System.out.println(dayNumber);
        // System.out.println(date);
        int[] semanaDistribuida = new int[7];
        
        // System.out.println( "      " +  data[1] + " " + data[5] );
        System.out.println("Su Mo Tu We Th Fr Sa");
        for (i= 1, i< Extra.monthDays())
        System.out.println();
        System.out.println(dayNumber);
        // for
    }

    
}