package aula07.Ex7_3;

public class Escultura extends Obra {
        private String tipoDeMadeira;
        private boolean unicaPeca;
        private int exemplaresDaPeca;
    Escultura(String nomeObra, String autor, double precoBase, String tipoDeMadeira, boolean unicaPeca, int exemplaresDaPeca){
        super(nomeObra,autor,precoBase);
        this.tipoDeMadeira = tipoDeMadeira;
        this.unicaPeca = unicaPeca;
        this.exemplaresDaPeca = exemplaresDaPeca;
    }
    public String getTipoDeMadeira(){return tipoDeMadeira;}
    public void setTipoDeMadeira(String tipoDeMadeira){this.tipoDeMadeira = tipoDeMadeira;}
    
    public boolean getUnicaPeca(){return unicaPeca;}
    public void setUnicaPeca(boolean unicaPeca){this.unicaPeca = unicaPeca;}

    public int getExemplaresDaPeca(){return exemplaresDaPeca;}
    public void setExemplaresDaPeca(int exemplaresDaPeca){this.exemplaresDaPeca = exemplaresDaPeca;}

    
    @Override
    public String toString(){
        if(unicaPeca)
        return "Este Quadro (id "+ identificador +"): "+ nomeObra + ", de " + autor + " custa: " + precoBase +" euros. Foi usada a madeira de:" + tipoDeMadeira + " Esta peça é única";
        
        
        return "Este Quadro (id "+ identificador +"): "+ nomeObra + ", de " + autor + " custa: " + precoBase +" euros. Foi usada a madeira de:" + tipoDeMadeira + " Esta peça tem " + exemplaresDaPeca + " exemplares";}
       
    }   
