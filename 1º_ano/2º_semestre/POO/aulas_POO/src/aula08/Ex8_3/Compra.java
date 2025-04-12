package aula08.Ex8_3;

interface Compra {
    void adicionarProduto (Produto produto, int quantidade);
    void listarProdutos();
    double calcularTotal();
}