package aula08.Ex8_3;

public class ProdutoGenerico implements Produto {
    private String name;
    private int quantidade;
    private double price;  
    ProdutoGenerico(String name, int quantidade, double price ){
        this.name = name;
        this.quantidade = quantidade;
        this.price = price;
    }


    @Override
    public String getNome(){return name;}


    @Override
    public double getPreco(){ return price;}
    
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
        return name + " Quantidade: " + quantidade +" Preço: " + price +"€";
    }
}
