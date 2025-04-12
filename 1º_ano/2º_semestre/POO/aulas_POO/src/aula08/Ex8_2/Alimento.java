package aula08.Ex8_2;

public class Alimento {
    protected double calorias;
    protected double proteinas;
    protected double peso;
    Alimento(double calorias, double proteinas, double peso){
        this.calorias=calorias;
        this.proteinas=proteinas;
        this.peso=peso;

    }
    public double getCalorias(){return calorias;}
}
