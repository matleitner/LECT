package aula09.Ex9_1;
import java.util.TreeSet;
import java.util.Set;
import aula07.Ex7_2.Date;
import aula07.Ex7_2.DateND;;


// Crie uma nova coleção (c4) que use um TreeSet de datas (classe Date, Exercício 7.2).
// Set<Date> c4 = new TreeSet<>();
// ...
// Insira 5 elementos distintos e verifique a ordem da listagem relativamente à ordem de
// inserção.
// Teste com as diferentes representações de data criadas na aula 7


// Comparable na class Date, é necessário para que o TreeSet saiba como comparar os elementos.


public class Exemplo_c {
    public static void main(String[] args){
        Set<Date> c4 = new TreeSet<>(); 
        Date d1 = new DateND(12,12,2020);
        Date d2 = new DateND(12, 02, 1999);
        Date d3 = new DateND(1, 8, 2005);
        Date d4 = new DateND(04, 10, 2006);
        Date d5 = new DateND(9, 11, 2006);
        c4.add(d1);
        c4.add(d5);
        c4.add(d2);
        c4.add(d3);
        c4.add(d4);

        System.out.println(c4);
    }  
    
}
