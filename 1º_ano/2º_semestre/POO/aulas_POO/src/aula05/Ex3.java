package aula05;
import aula02.Extra.DateYMD;
import java.util.ArrayList;
public class Ex3 {

    static  class Property{
        private int id=1000;
        private double price;
        private int numOfBedrooms;
        private String local;
        private boolean available = true;
        private DateYMD date;

        Property( String local, int numOfBedrooms, double price){
            this.local = local;
            this.numOfBedrooms = numOfBedrooms;
            this.price = price;
            id++;
        }

        public int getId(){return id;}
        public int getNumOfBedrooms(){return numOfBedrooms;}

        public boolean getAvailable(){return available;}

        public String getLocal(){return local;}

        public DateYMD getDate(){return date;}

        public double getPrice(){return price;}
        @Override
        public  String toString(){
            return "Id "+id +" Local: "+ local+" Preço: " + price +"€ Disponivel: " + available;
        }
        
        public boolean compare(int num){
            if(id == num) return true;
            else return false;
        }
        
    }
    static class RealEstate{
        
        ArrayList<Object> imoveis;        
        private double price;
        private int numOfBedrooms;
        private String local;
        private boolean available;
        private DateYMD date;

        public RealEstate(){
            imoveis = new ArrayList<>();
        }
       
    
        public void newProperty(String local, int numOfBedrooms, int price){
            imoveis.add(new Property(local, numOfBedrooms, price));

        }
        public void sell(int id){
            for (Object imovel : imoveis){
                Property propriedade = (Property) imovel;
                if(propriedade.getId()== id)
                    {
                        if(!propriedade.getAvailable()){
                        
                        System.out.printf("Este imovel % não está disponivel", id);
                    }
                    System.out.println("Sold! " + propriedade.getId() +" " + propriedade.getLocal());
                    available = false; 
                }
                else {System.out.println("Não existe");}
            }
        }
        public void setAuction(int id, DateYMD data, int numOfBedrooms){
            if(available == false) System.out.println("Não é possivel colocar em leilão...");

            else if(available == true) {
                System.out.println("O imovel "+ id +" com " + numOfBedrooms + " quartos, que custa " + price + "€ foi leiloado no dia " + data);
            }
        }

        @Override 
        public String toString(){
            for(Object a : imoveis)
                System.out.println(a);
            return ""; 

        }

    }
    
    public static void main(String[] args) {
        RealEstate imobiliaria = new RealEstate();
        imobiliaria.newProperty("Glória", 2, 30000);
        imobiliaria.newProperty("Vera Cruz", 1, 25000);
        imobiliaria.newProperty("Santa Joana", 3, 32000);
        imobiliaria.newProperty("Aradas", 2, 24000);
        imobiliaria.newProperty("São Bernardo", 2, 20000);

        System.out.println(imobiliaria);

        imobiliaria.sell(1001);
        imobiliaria.setAuction(1002, new DateYMD(21, 3, 2023), 4);
        imobiliaria.setAuction(1003, new DateYMD(1, 4, 2023), 3);
        imobiliaria.setAuction(1001, new DateYMD(1, 4, 2023), 4);
        imobiliaria.setAuction(1010, new DateYMD(1, 4, 2023), 4);

        System.out.println(imobiliaria);

    }
}
