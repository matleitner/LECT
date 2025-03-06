package aula04.Ex4_1;

public class Retangulo {
    double comprimento;
    double altura;

    public Retangulo(double al, double comprimento){
            this.comprimento = comprimento;
            this.altura = al;
    }
    double AreaRetangulo(){
        return comprimento* altura;
    }
}
