package aula08.Ex8_2;

public class PratoDieta extends Prato {
        private double limiteMaxCalorias;
    PratoDieta(String nomeDoPrato, double limiteMaxCalorias){
        super(nomeDoPrato);
        this.limiteMaxCalorias = limiteMaxCalorias;
    }
    
}
