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

    Obra[] getArrayObras(){return listaObras;}
    @Override
    public String toString(){ 
        String result = "";
        for (int i = 0; i < counter; i++) {
            if(listaObras[i].identificador!= 0) 
            result += listaObras[i].getidentificador() + ": " + listaObras[i].toString() + "\n"; 
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
        int  i = 0;
        while(i<=numOfObras){
            
            if(listaObras[i].getidentificador()== identificador){
                double lucro = dinheiro - listaObras[i].getPrecoBase(); 
                lucroTotal += lucro;
                System.out.println("A " + listaObras[i].getClass() + " " + listaObras[i].getNomeObra() + " foi vendida a " + dinheiro + " lucro: " + lucro);
                listaObras[i] = new ObraVendida();
                break;
            }
            i++;
            System.out.println("Essa obra não existe");
        }
    }
    public double lucro(){return lucroTotal;}

}
