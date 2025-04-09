package aula08.Ex8_1;


public abstract class Veiculos implements IKmPercorridos {
    protected String matricula, marca, modelo;
    protected int potencia, kmTotal, viagemMaisRecente;
    protected boolean alugado;
    protected double preco;

    Veiculos(String matricula, String marca, String modelo, int potencia){
        this.matricula = matricula;
        this.marca= marca;
        this.modelo = modelo;
        this.potencia = potencia;
        this.viagemMaisRecente = 0;
        this.alugado = false;
        this.kmTotal = 0;
    }

    public void trajeto(int quilometros){
        this.kmTotal+= quilometros;
        viagemMaisRecente = quilometros;
    }
    
    
    public void setPreco(double preco){ this.preco = preco;}

    
    public int getKms(){return kmTotal;}


    public int ultimoTrajeto(){
        return viagemMaisRecente;
    }


    public int distanciaTotal(){
        return kmTotal;
    }


    @Override
    public boolean equals(Object obj){
        if(this!= obj)
            return false;
        if(obj ==null)
            return false;
        if(getClass() != obj.getClass()) 
            return false;
        Veiculos other = (Veiculos) obj;
        
        if(!matricula.equals(other.matricula))
            return false;
        if(!modelo.equals(other.modelo))
            return false;
        if(potencia != other.potencia)
            return false;
    
        if(!marca.equals(other.marca))
            return false;
        return true; 
        }

    
    @Override
    public String toString(){
        return " Matricula: "+ matricula + "| Marca: "+ marca + "| Modelo: " + modelo + "| Potencia: " + potencia + "| Kms: " + kmTotal; 
    }
    
    
    @Override
    public int hashCode(){
        return potencia + kmTotal +2 * 123;
    }
    
    String getMatricula() {return matricula;}
    
    String getmarca()    {return marca;}
    
    String getmodelo()   {return modelo;}
    
    int getpotencia()    {return potencia;}

    
    void setMatricula(String matricula)    {this.matricula = matricula;}
    
    void setmarca(String marca)            {this.marca = marca;}
    
    void setmodelo(String modelo)          {this.modelo = modelo;}
    
    void setpotencia(int potencia)         {this.potencia = potencia;}
}
