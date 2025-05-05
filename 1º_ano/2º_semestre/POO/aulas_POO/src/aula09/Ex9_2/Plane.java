package aula09.Ex9_2;

public class Plane {
    protected int id;
    protected String fabricante;
    protected String modelo;
    protected int anoDeProducao;
    protected int numMaxDePassageiros;
    protected int velocidadeMaxima;
    protected static int contador = 0;

    public Plane(String fabricante, String modelo, int anoDeProducao, int numMaxDePassageiros, int velocidadeMaxima){
        this.anoDeProducao = anoDeProducao;
        this.fabricante = fabricante;
        this.modelo = modelo;
        this.numMaxDePassageiros = numMaxDePassageiros;
        this.velocidadeMaxima = velocidadeMaxima;
        this.id = ++contador; 
    }
    
    public int getAnoDeProducao() {
        return anoDeProducao;
    }
    public String getFabricante() {
        return fabricante;
    }
    public int getId() {
        return id;
    }
    public String getModelo() {
        return modelo;
    }
    public int getNumMaxDePassageiros() {
        return numMaxDePassageiros;
    }
    public int getVelocidadeMaxima() {
        return velocidadeMaxima;
    }
    public void setAnoDeProducao(int anoDeProducao) {
        this.anoDeProducao = anoDeProducao;
    }
    public void setFabricante(String fabricante) {
        this.fabricante = fabricante;
    }
    
    public void setModelo(String modelo) {
        this.modelo = modelo;
    }
    public void setNumMaxDePassageiros(int numMaxDePassageiros) {
        this.numMaxDePassageiros = numMaxDePassageiros;
    }
    public void setVelocidadeMaxima(int velocidadeMaxima) {
        this.velocidadeMaxima = velocidadeMaxima;
    }
    @Override
    public String toString() {
        return "ID: " + id + ", Fabricante: " + fabricante + ", Modelo: " + modelo + ", Ano de produção: " + anoDeProducao + ", Número máximo de passageiros: " + numMaxDePassageiros + ", Velocidade máxima: " + velocidadeMaxima;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) return false;
        if(this == obj)  return true;
        if (getClass() != obj.getClass()) return false;
        Plane objeto = (Plane) obj;
        return  objeto.getAnoDeProducao() == this.anoDeProducao &&
                objeto.getFabricante() == getFabricante() && 
                objeto.getId() == getId() &&
                objeto.getModelo() == getModelo() &&
                objeto.getNumMaxDePassageiros() == getNumMaxDePassageiros() &&
                objeto.getVelocidadeMaxima() == getVelocidadeMaxima();
            }
    public String getPlaneType(){
        return "Plane";
    }
}
