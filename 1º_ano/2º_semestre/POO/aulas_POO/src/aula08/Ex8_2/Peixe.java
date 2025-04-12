package aula08.Ex8_2;

public class Peixe extends Alimento {
    private Ementa.TipoPeixe tipoPeixe;
    Peixe(Ementa.TipoPeixe tipoPeixe, double calorias, double proteinas, double peso){
        super(calorias, proteinas, peso);
        this.tipoPeixe = tipoPeixe;
    }
}
