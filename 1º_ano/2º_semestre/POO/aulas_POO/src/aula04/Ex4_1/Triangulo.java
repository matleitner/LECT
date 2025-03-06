package aula04.Ex4_1;

public class Triangulo {
    private double l1;
    private double l2;
    private double l3;

    public Triangulo(double l1, double l2, double l3) {
        this.l1 = l1;
        this.l2 = l2;
        this.l3 = l3;
        
    }
    double AreaTriangulo(){
        double S = (l1 + l2 +l3)/2;
        return Math.sqrt(S*(S-l1)*(S-l2)*(S-l3));
    }
}
