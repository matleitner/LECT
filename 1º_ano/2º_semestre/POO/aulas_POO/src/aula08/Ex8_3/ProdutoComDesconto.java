package aula08.Ex8_3;

public class ProdutoComDesconto implements Produto {
    private double discount;
    private String name;
    private int quantidade;
    private double price;

    ProdutoComDesconto(String name, int quantidade, double price, double discount){
        this.name = name;
        this.quantidade = quantidade;
        this.price = price;
        this.discount = discount;
    }
    @Override
    public String getNome(){return name;}


    @Override
    public double getPreco(){ return price- price*discount/100;}
    
    @Override
    public int getQuantidade(){return quantidade;}
    
    @Override
    public void removerQuantidade(int quantidade){
        this.quantidade -=quantidade;
        if(quantidade<=0){this.quantidade = 0;}

    }
    
    @Override
    public void adicionarQuantidade(int quantidade) {
        this.quantidade+=quantidade;
    }
    
    @Override
    public String toString() {
        return name + " Quantidade: " + quantidade + " Preço: " + price + "€ Desconto: " + discount + "%";
    }
}
