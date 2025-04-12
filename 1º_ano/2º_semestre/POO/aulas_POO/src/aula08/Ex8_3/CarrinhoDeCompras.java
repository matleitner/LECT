package aula08.Ex8_3;

import java.util.ArrayList;

public class CarrinhoDeCompras implements Compra {
    protected ArrayList<Produto> compras;
    CarrinhoDeCompras(){
        compras = new ArrayList<>();
    }
    public void adicionarProduto(Produto produto, int quantidade){
        produto.adicionarQuantidade(quantidade);
        compras.add(produto);

    }
    public void listarProdutos(){
        for(Object produto : compras){
            System.out.println(produto); 
        }
    }
    public double calcularTotal(){
        double total = 0;
        for(Produto produto : compras){
            
            total+= produto.getQuantidade() * produto.getPreco(); }
            
            
        return total;
    }
    
}
