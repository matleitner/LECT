package aula08.Ex8_2;

public class Carne extends Alimento {
    private Ementa.VariedadeCarne variedadeDeCarne;
    Carne(Ementa.VariedadeCarne variedadeDeCarne  ,double calorias, double proteinas, double peso){
        super(calorias, proteinas, peso);
        this.variedadeDeCarne = variedadeDeCarne;
    }   
}
