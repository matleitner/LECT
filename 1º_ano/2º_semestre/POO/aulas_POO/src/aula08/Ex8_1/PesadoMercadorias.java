package aula08.Ex8_1;

public class PesadoMercadorias extends AutomoveisPesados {
    private double cargaMaxima;


    PesadoMercadorias(String matricula, String marca, String modelo, int potencia, int numeroDoQuadro, double peso, double cargaMaxima){
        super(matricula, marca, modelo, potencia, numeroDoQuadro, peso);
        this.cargaMaxima = cargaMaxima;
    }
    
}
