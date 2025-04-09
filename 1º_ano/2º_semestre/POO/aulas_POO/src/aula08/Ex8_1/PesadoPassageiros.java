package aula08.Ex8_1;

public class PesadoPassageiros extends AutomoveisPesados {
    private int numeroMaximoDePassageiros;


    PesadoPassageiros(String matricula, String marca, String modelo, int potencia, int numeroDoQuadro, double peso, int numeroMaximoDePassageiros){
        super(matricula, marca, modelo, potencia, numeroDoQuadro, peso);
        this.numeroMaximoDePassageiros = numeroMaximoDePassageiros;
    }
    
}
