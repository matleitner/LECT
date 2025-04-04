package aula07.Ex7_3;

public class Quadro extends Obra {
    private String tipoDeTinta;
    private boolean emoldurado;
    private String tamanho;

    public Quadro(String nomeObra, String autor, int precoBase, String tipoDeTinta, boolean emoldurado, String tamanho){
        super(nomeObra,autor ,precoBase);
        this.tipoDeTinta = tipoDeTinta;
        this.emoldurado = emoldurado;
        this.tamanho = tamanho;
    }
    public String gettipoDeTinta(){return tipoDeTinta;}
    public void settipoDeTinta(String tipoDeTinta){this.tipoDeTinta = tipoDeTinta;}
    
    public String getTamanho(){return tamanho;}
    public void setTamanho(String tamanho){this.tamanho = tamanho;}

    public boolean getEmoldurado(){return emoldurado;}
    public void setEmoldurado(boolean emoldurado){this.emoldurado = emoldurado;}

    @Override
    public String toString(){return "Este Quadro (id "+ identificador +"): "+ nomeObra + ", de " + autor + " custa: " + precoBase +" euros. Foi feito com tinta: "+ tipoDeTinta + " Está emoldurada? "+ emoldurado + " Tamanho da tela: " + tamanho;}
}
