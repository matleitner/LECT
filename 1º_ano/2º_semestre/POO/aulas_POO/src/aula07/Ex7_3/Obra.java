package aula07.Ex7_3;

public class Obra {
    protected String nomeObra;
    protected String autor;
    protected double precoBase;
    protected int identificador;
    static int contadorindetificador = 33;

    public Obra(String nomeObra, String autor, double precoBase){
        this.nomeObra = nomeObra;
        this.autor = autor;
        this.precoBase = precoBase;
        this.identificador = contadorindetificador++;
    }
    
    public String getNomeObra(){return nomeObra;}
    public void setNomeObra(String nomeObra){this.nomeObra = nomeObra;}
    
    public String getAutor(){return autor;}
    public void setAutor(String autor){this.autor = autor;}

    public double getPrecoBase(){return precoBase;}
    public void setPrecoBase(double precoBase){this.precoBase = precoBase;}

    public int getidentificador(){return identificador;}
    
    public static String verificador(boolean a){
        if(a) return "sim";
        return "não";
    }
    
    
    @Override
    public String toString(){return "Esta Obra (id "+ identificador +"): "+ nomeObra + ", de " + autor + " custa: " + precoBase +" euros.";}



    @Override
    public boolean equals(Object obj){
        if(this!= obj)
            return false;
        if(obj ==null)
            return false;
        if(getClass() != obj.getClass()) 
            return false;
        Obra other = (Obra) obj;
        
        if(!nomeObra.equals(other.nomeObra))
            return false;
        if(!autor.equals(other.autor))
            return false;
        if(precoBase != other.precoBase)
            return false;
    
        if(identificador != other.identificador)
            return false;
        return true; 
        }

    @Override
    public int hashCode(){
    
        int hash = (int) ((identificador * 7 ) *(precoBase + identificador));
        return hash; 
    }


}
