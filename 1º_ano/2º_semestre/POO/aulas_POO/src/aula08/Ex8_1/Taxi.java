package aula08.Ex8_1;

public class Taxi extends AutomoveisLigeiros {
    private int numeroDaLicenca;


    Taxi(String matricula, String marca, String modelo, int potencia, int numeroDoQuadro, int capacidadeDaBagageira, int numeroDaLicenca){
        super(matricula, marca, modelo, potencia, numeroDoQuadro, capacidadeDaBagageira);
        this.numeroDaLicenca = numeroDaLicenca;
    }
    
}
