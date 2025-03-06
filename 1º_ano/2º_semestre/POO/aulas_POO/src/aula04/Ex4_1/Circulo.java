package aula04.Ex4_1;

public class Circulo{
    private double raio;


    public Circulo(double raio) {
        this.raio = raio;
        }
    public double getRaio(){
        return raio;
    }
    public void setRaio(double raio) {
        this.raio = raio;
    }

    public double AreaCirculo(){
        return Math.pow(raio, 2) * Math.PI; 
    
        }
    
}