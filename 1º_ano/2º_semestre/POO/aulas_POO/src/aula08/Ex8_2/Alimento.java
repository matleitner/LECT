package aula08.Ex8_2;
import java.lang.Comparable;
public class Alimento implements Comparable<Alimento>{
    protected double calorias;
    protected double proteinas;
    protected double peso;
    Alimento(double calorias, double proteinas, double peso){
        this.calorias=calorias*peso/100;
        this.proteinas=proteinas;
        this.peso=peso;

    }
    public double getCalorias(){return calorias;}
    @Override
    public int compareTo(Alimento other){

        return (int) (this.getCalorias()-other.getCalorias());

    }


}
