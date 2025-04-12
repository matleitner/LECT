package aula08.Ex8_2;

public class PratoVegetariano extends Prato {
    
    PratoVegetariano(String nomeDoPrato){
        super(nomeDoPrato);

    }
    @Override
    public String toString(){
        return  nomeDoPrato + " composto por " + conjuntoAlimentos.size() +" ingredientes - Vegetariano";
    }
    
}
