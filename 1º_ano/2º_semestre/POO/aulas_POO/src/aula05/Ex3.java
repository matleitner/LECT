package aula05;
import aula02.Extra.DateYMD;
import aula05.Ex3.Property;

import java.util.ArrayList;
public class Ex3 {

    static  class Property{
        
        private static int  idCounter = 1000;   
        private int id;

        private double price;
        private int numOfBedrooms;
        private String local;
        private boolean available = true;
        private DateYMD date;

        Property( String local, int numOfBedrooms, double price){
            this.local = local;
            this.numOfBedrooms = numOfBedrooms;
            this.price = price;
            this.id = idCounter++;
        }

        public int getId(){return id;}
        public int getNumOfBedrooms(){return numOfBedrooms;}

        public boolean getAvailable(){return available;}

        public String getLocal(){return local;}

        public DateYMD getDate(){return date;}

        public double getPrice(){return price;}
        @Override
        public  String toString(){
            return "Id "+id +" Local: "+ local+" Preço: " + price +"$\n" + "Numero de quartos:"+ numOfBedrooms +"\nDisponivel: " + available + "\n";
        }
        
        public boolean compare(int num){
            if(id == num) return true;
            else return false;
        }
        public void sellProperty(int num){available = false;}

            public String setAuction(DateYMD date){
                   
                if (!available) {
                     return "O imóvel " + id + " não está disponível para leilão.";
                    
                }
                this.date = date;
                return "O imóvel " + id + " foi colocado em leilão na data: " + date;
            
            }
        }
    }
    

    class RealEstate{
        
        private ArrayList<Property> imoveis;        

        public RealEstate(){
            imoveis = new ArrayList<>();
        }
       
    
        public void newProperty(String local, int numOfBedrooms, int price){
            imoveis.add(new Property(local, numOfBedrooms, price));

        }
        public String sell(int id){
            for (Property propriedade : imoveis){
                if(propriedade.getId()== id)
                    {
                        if(!propriedade.getAvailable()){
                        
                        return "Este imovel"+ id +"não está disponivel" ;
                    }
                    propriedade.sellProperty(id);
                    return "Sold! " + propriedade;
                     
                }
            }
            return "Não existe";
        }
        public String setAuction(int id, DateYMD data){
            for (Property propriedade : imoveis)
            {
                if(propriedade.getId() == id )
                    {System.out.println (propriedade.setAuction(data));
                     return "";}
            }
            System.out.println("Imóvel com ID " + id + " não encontrado.");
            return "";
        }
            
        
    

        @Override 
        public String toString(){
            for(Property a : imoveis)
                System.out.println(a);
            return ""; 

        }

    

    public static void main(String[] args) {
        RealEstate imobiliaria = new RealEstate();
        imobiliaria.newProperty("Glória", 2, 30000);
        imobiliaria.newProperty("Vera Cruz", 1, 25000);
        imobiliaria.newProperty("Santa Joana", 3, 32000);
        imobiliaria.newProperty("Aradas", 2, 24000);
        imobiliaria.newProperty("São Bernardo", 2, 20000);
        
        System.out.println("putas");
        System.out.println(imobiliaria);
        System.out.println("putas");
        
        imobiliaria.sell(1001);
        imobiliaria.sell(1004);
        imobiliaria.setAuction(1002, new DateYMD(21, 3, 2023));
        imobiliaria.setAuction(1003, new DateYMD(1, 4, 2023) );
        imobiliaria.setAuction(1001, new DateYMD(1, 4, 2023));
        imobiliaria.setAuction(1010, new DateYMD(1, 4, 2023));
        System.out.println("\n");
        System.out.println(imobiliaria);

    }
}

