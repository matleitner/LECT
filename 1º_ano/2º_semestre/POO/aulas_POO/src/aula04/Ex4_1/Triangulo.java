package aula04.Ex4_1;
import java.util.Arrays;

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

     public double getL1(){
        return l1;
    }
     
    public double getL2(){
        return l2;
    }
    
    public double getL3(){
        return l3;
    }

    @Override
    public boolean equals(Triangulo t) {
        double[] ladosTriangulos = {t.getL1(), t.getL2(), t.getL3()};
        double[] ladosTriangulos1 = {this.getL1(), this.getL2(), this.getL3()};
        Arrays.sort(ladosTriangulos);
        Arrays.sort(ladosTriangulos1);
        for (int i=0; i< 2; i++){
            if(ladosTriangulos[i] != ladosTriangulos1[i]){
                return false;

            }
        }
        return true;

    }
}
