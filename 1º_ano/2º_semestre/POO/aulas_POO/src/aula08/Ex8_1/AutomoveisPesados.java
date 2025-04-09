package aula08.Ex8_1;

public abstract class AutomoveisPesados extends Veiculos {
    protected double peso;
    protected int numeroDoQuadro;
    AutomoveisPesados(String matricula, String marca, String modelo, int potencia, int numeroDoQuadro, double peso){
        super(matricula, marca, modelo, potencia);
        this.peso = peso;
        this.numeroDoQuadro = numeroDoQuadro;
    
    }
}
