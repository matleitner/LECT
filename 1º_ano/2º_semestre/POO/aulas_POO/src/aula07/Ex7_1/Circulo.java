package aula07.Ex7_1;

public class Circulo extends Figuras {
    private double raio;
    

    public Circulo(double raio, String color){
        this.raio = raio;
        this.color = color;
    }


    public void setColor(String color){
        this.color = color;
    }

    public String getColor(){
        return color;
    }

    public double getRaio(){
        return raio;
    }
    public void setRaio(double raio) {
        this.raio = raio;
    }


    @Override
    public boolean equals(Object forma){
        if (this == forma) return true; 
    if (forma == null || getClass() != forma.getClass()) return false;
    Circulo circulo = (Circulo) forma;
    return this.getRaio() == circulo.getRaio() && circulo.getColor() == this.getColor(); 
    }

    @Override
    public double calcularPerimetro(){
        return 2*raio*Math.PI;
    }
    @Override
    public double calcularArea(){
        return Math.PI*Math.pow(raio, 2);
    }
}
