package aula09.Ex9_2;

public class ComercialPlane extends Plane {
    private int numeroDeTripulantes;

    ComercialPlane(String fabricante, String modelo, int anoDeProducao, int numMaxDePassageiros, int velocidadeMaxima, int numeroDeTripulantes){
        super(fabricante, modelo, anoDeProducao, numMaxDePassageiros, velocidadeMaxima);
        this.numeroDeTripulantes = numeroDeTripulantes;
    }

    public int getNumeroDeTripulantes() {
        return numeroDeTripulantes;
    }
    public void setNumeroDeTripulantes(int numeroDeTripulantes) {
        this.numeroDeTripulantes = numeroDeTripulantes;
    }
    @Override
    public String toString() {
        return super.toString() + ", Número de tripulantes: " + numeroDeTripulantes;
    }
    @Override
    public String getPlaneType() {
        return "Comercial";
    }

}
