package aula08.Ex8_1;

public class Motociclo extends Veiculos{
    private String tipoMotociclo;


    Motociclo(String matricula, String marca, String modelo, int potencia, String tipoMotociclo ){
        super(matricula, marca, modelo, potencia);
        this.tipoMotociclo = tipoMotociclo;
    }
    

}
