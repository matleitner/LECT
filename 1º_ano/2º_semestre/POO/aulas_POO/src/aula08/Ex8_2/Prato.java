package aula08.Ex8_2;
import java.util.ArrayList;
public class Prato {
    protected String nomeDoPrato;
    protected ArrayList<Alimento> conjuntoAlimentos;
     
    protected static int numeroDeIngredientes;
    Prato(String nomeDoPrato){
        conjuntoAlimentos = new ArrayList<>();
        this.nomeDoPrato = nomeDoPrato;
    }
    


    public boolean addIngrediente(Alimento alimento){
        
        if(this instanceof PratoDieta){
            PratoDieta pratoDieta = (PratoDieta) this;
            if(alimento.getCalorias() <= pratoDieta.getLimiteMaxCalorias()){
                conjuntoAlimentos.add(alimento);
                return true;}
            else{
                return false;
            }
        }
        if(this instanceof PratoVegetariano){
            if(!(alimento instanceof Carne )&& !(alimento instanceof Peixe)){                
                conjuntoAlimentos.add(alimento);
                return true;
            }
            else {
                return false;}
        }
        if(this instanceof Prato){
            conjuntoAlimentos.add(alimento);
            return true;
        }
        return false;
    }
    public ArrayList<Alimento> getIngradientes(){
        return conjuntoAlimentos;
    }
    public String toString(){
        return  nomeDoPrato + " composto por " + conjuntoAlimentos.size() + " ingredientes" ;
    }
}
