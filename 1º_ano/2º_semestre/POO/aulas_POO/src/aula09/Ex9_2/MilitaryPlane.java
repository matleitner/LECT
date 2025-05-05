package aula09.Ex9_2;

public class MilitaryPlane extends Plane {
    private int numeroDeMunicoes;
    MilitaryPlane(String fabricante, String modelo, int anoDeProducao, int numMaxDePassageiros, int velocidadeMaxima, int numeroDeMunicoes){
        super(fabricante, modelo,anoDeProducao,  numMaxDePassageiros, velocidadeMaxima);
        this.numeroDeMunicoes = numeroDeMunicoes;
    }
    public int getNumeroDeMunicoes() {
        return numeroDeMunicoes;
    }
    public void setNumeroDeMunicoes(int numeroDeMunicoes) {
        this.numeroDeMunicoes = numeroDeMunicoes; 
    }

    @Override
    public String toString(){
        return super.toString() + ", Número de munições: " + numeroDeMunicoes;

    }
    @Override 
    public String getPlaneType(){
        return "Militar";

    }

    
    
}
