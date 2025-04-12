package aula08.Ex8_2;

public class Carne extends Alimento {
    private Ementa.VariedadeCarne variedadeDeCarne;
    Carne(Ementa.VariedadeCarne variedadeDeCarne  ,double calorias, double proteinas, double peso){
        super(calorias, proteinas, peso);
        this.variedadeDeCarne = variedadeDeCarne;
    }   
    public Ementa.VariedadeCarne getVariedadeCarne(){
        return variedadeDeCarne;
    }
    public double getCalorias(){return calorias;}

    public double getProteinas(){ return proteinas;}

    public double getPeso(){ return peso;}

    public String toString(){
        return "Carne: " +  variedadeDeCarne + " Proteinas: " + proteinas + ", Calorias: " + calorias + ", Peso: " + peso ;
    }
}
