package aula08.Ex8_2;

public class Cereal extends Alimento implements Vegetariano{
    private String nome;
    Cereal(String nome, double calorias, double proteinas, double peso){
        super(calorias, proteinas, peso);
        this.nome = nome;
    }
    
}
