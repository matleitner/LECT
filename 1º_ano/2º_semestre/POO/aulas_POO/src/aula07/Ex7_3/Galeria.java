package aula07.Ex7_3;


public class Galeria {
    private Obra[] listaObras;
    private int numOfObras;
    private int counter;
    private double lucroTotal = 0;


    Galeria(int numOfObras){
        this.numOfObras = numOfObras;
        listaObras = new Obra[numOfObras];
        counter = 0;
    }
    
    @Override
    public String toString(){ 
        String result = "";
        for (int i = 0; i < counter; i++) {
            result += listaObras[i].toString() + "\t"; 
        }
        
        return result;
    }
    public void addObra(Obra obj){
        if (counter < numOfObras){
            listaObras[counter] = obj;
            counter++;}
        else
            System.out.println("Não há mais espaço");    
    }
    public void vender(int identificador, double dinheiro){
        for(int i = 0; i<numOfObras; i++){
            if(listaObras[i].getidentificador()== identificador){
                listaObras[i] = null;
                double lucro = dinheiro - listaObras[i].getPrecoBase(); 
                lucroTotal += lucro;
                System.out.println("A " + listaObras[i].getClass() + " " + listaObras[i].getNomeObra() + " foi vendida a " + dinheiro + " lucro: " + lucro);
            }

        }
    }
    public double lucro(){return lucroTotal;}

}
