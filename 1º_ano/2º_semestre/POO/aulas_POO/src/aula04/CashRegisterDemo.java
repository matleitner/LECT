package aula04;

import java.util.ArrayList;
import java.util.List;

class Product {
    private String name;
    private double price;
    private int quantity;

    public Product(String name, double price, int quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public double getTotalValue() {
        return price * quantity;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public int  getQuantity() {
        return quantity;
    }
}


class CashRegister {
    List <Product> produtos;
    public CashRegister(){
        produtos = new ArrayList<>();

    }


    public void addProduct(Product b){
            produtos.add(b);
            }
            
public String toString(){
    System.out.println( "Product \t Price \t\t Quantity \t Total");
    double soma = 0; 
    for (Product product : produtos){System.out.printf("%-10s \t %-8.2f \t %-8d \t %.2f\n", 
    product.getName(), 
    product.getPrice(), 
    product.getQuantity(), 
    product.getTotalValue());
    soma += product.getTotalValue();    
}

    return "\nTotal value: "+ soma;
        
}
    
// TODO: completar implementação da classe
}

public class CashRegisterDemo {

    public static void main(String[] args) {

        // Cria e adiciona 5 produtos
        CashRegister cr = new CashRegister();
        cr.addProduct(new Product("Book", 9.99, 3));
        cr.addProduct(new Product("Pen", 1.99, 10));
        cr.addProduct(new Product("Headphones", 29.99, 2));
        cr.addProduct(new Product("Notebook", 19.99, 5));
        cr.addProduct(new Product("Phone case", 5.99, 1));
        
        // TODO: Listar o conteúdo e valor total
        System.out.println(cr);

    }
}
