package aula08.Ex8_2;

public class Legume extends Alimento implements Vegetariano{
    private String nome;
    Legume(String nome, double calorias, double proteinas, double peso){
        super(calorias, proteinas, peso);
        this.nome=nome;
    }
    public String toString(){
        return "Legume: " +  nome  + " Proteinas: " + proteinas + ", Calorias: " + calorias + ", Peso: " + peso ;
    }
}
