package aula08.Ex8_2;

public class Ementa {
    private String nome;
    private String local;
    private Prato[] listaPratos;

    Ementa(String nome, String local){
        this.nome = nome;
        this.local = local;
    }
    public enum DiaSemana{
            SEGUNDA,
            TERCA,
            QUARTA,
            QUINTA,
            SEXTA,
            SABADO,
            DOMINGO
    }
    public enum VariedadeCarne{
        VACA,PERU,FRANGO,OUTRA
    }
    public enum TipoPeixe{
        CONGELADO,FRESCO
    }
   
}
