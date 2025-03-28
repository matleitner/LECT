package aula05;
import aula02.Extra.DateYMD;
import java.util.ArrayList;
public class Ex3 {
    static class RealEstate{
        
        ArrayList<Object>[] imoveis;        
        private int id;    
        private double price;
        private int numOfBedrooms;
        private String local;
        private boolean available;
        private DateYMD date;
        public RealEstate(){
            imoveis = new ArrayList<>();

        }

        // class Propriedade{
        //     public
        // }

    
        public void newProperty(String local, int numOfBedrooms, int price){
            id ++;
            imoveis.add(new Object[] {id, local, numOfBedrooms, price})

        }
        public void sell(int id){
            if(available){
                
                System.out.printf("Este imovel % não está disponivel", id);
                available = false;
            }
            System.out.println("Sold!");
            available = true;
        }
        public void setAuction(int id, DateYMD data, int numOfBedrooms){
            if(available == false) System.out.println("Não é possivel colocar em leilão...");

            else if(available == true) {
                System.out.println("O imovel "+ id +" com " + numOfBedrooms + "quartos, que custa" + price + "€ foi leiloado no dia " + data);
            }
            // return dataBeginLeilao;
        }

    }
    public static void main(String[] args) {
        RealEstate imobiliaria = new RealEstate();
        imobiliaria.newProperty("Glória", 2, 30000);
        imobiliaria.newProperty("Vera Cruz", 1, 25000);
        imobiliaria.newProperty("Santa Joana", 3, 32000);
        imobiliaria.newProperty("Aradas", 2, 24000);
        imobiliaria.newProperty("São Bernardo", 2, 20000);

        imobiliaria.sell(1001);
        imobiliaria.setAuction(1002, new DateYMD(21, 3, 2023), 4);
        imobiliaria.setAuction(1003, new DateYMD(1, 4, 2023), 3);
        imobiliaria.setAuction(1001, new DateYMD(1, 4, 2023), 4);
        imobiliaria.setAuction(1010, new DateYMD(1, 4, 2023), 4);

        System.out.println(imobiliaria);

    }
}
