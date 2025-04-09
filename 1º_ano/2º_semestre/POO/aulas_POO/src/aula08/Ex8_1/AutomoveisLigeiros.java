package aula08.Ex8_1;

public abstract class AutomoveisLigeiros extends Veiculos {
    protected int numeroDoQuadro;
    protected int capacidadeDaBagageira; 
    
    
    
    AutomoveisLigeiros(String matricula, String marca, String modelo, int potencia, int numeroDoQuadro, int capacidadeDaBagageira){
        super(matricula, marca, modelo, potencia);
        this.potencia = potencia;
        this.numeroDoQuadro = numeroDoQuadro;
        this.capacidadeDaBagageira = capacidadeDaBagageira;
    }

    
}