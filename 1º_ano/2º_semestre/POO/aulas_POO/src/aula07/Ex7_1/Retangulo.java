package aula07.Ex7_1;

public class Retangulo extends Figuras {
    private double largura;
    private double altura;

    Retangulo(double largura, double altura, String color){
        this.color = color;
        this.altura = altura;
        this.largura = largura;
    }
    
    public void setColor(String color){
        this.color = color;
    }

    public String getColor(){
        return color;
    }

    public double getAltura(){
        return altura;
    }
    public void setAltura(double altura) {
        this.altura= altura;
    }

    public double getLargura(){
        return largura;
    }
    public void setLargura(double largura) {
        this.largura = largura;
    }



    @Override
    public boolean equals(Object forma){
        if (this == forma) return true; 
    if (forma == null || getClass() != forma.getClass()) return false;
    Retangulo retangulo = (Retangulo) forma;
    return this.getAltura() == retangulo.getAltura() && this.getLargura() == retangulo.getLargura() && retangulo.getColor() == this.getColor(); 
    }
    




    @Override
    public double calcularPerimetro(){
        return 2*altura + 2*largura;
    }
    @Override
    public double calcularArea(){
        return altura*largura;
    }
}
