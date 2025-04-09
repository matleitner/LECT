package aula08.Ex8_1;

public class AutomovelLigeiroEletrico extends AutomoveisLigeiros implements IGestaoBateria {
    protected double percentagemBateria;
    protected double percentagemBateriaMaxima;

    AutomovelLigeiroEletrico(String matricula, String marca, String modelo, int potencia, int numeroDoQuadro, int capacidadeDaBagageira, double bateria){
        super(matricula,  marca,  modelo,  potencia,  numeroDoQuadro,  capacidadeDaBagageira);
        this.percentagemBateria = bateria;
    }

    @Override
    public double cargaDisponivel() {
        return percentagemBateria;
    }
    @Override
    public void carregar(double percentagem) {
        if(percentagem + percentagemBateria != percentagemBateriaMaxima)
        percentagemBateria += percentagem;
        else percentagemBateria = percentagemBateriaMaxima;
    }

    @Override
    public void limitarCargamaxima(double percentagem) {
        percentagemBateriaMaxima = percentagem;
        
    }
}
