package aula08.Ex8_1;

public interface IGestaoBateria {
    
    double cargaDisponivel();
    void carregar(double percentagem);
    void limitarCargamaxima(double percentagem);
    
}
