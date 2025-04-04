package aula07.Ex7_3;

public class ObraDigital extends Obra {
    private String blockChain;
    private String endereceDeContratoNFT;   
    
    
    public ObraDigital(String nomeObra, String autor, double precoBase, String blockchain, String endereceDeContratoNFT){
        super(nomeObra, autor, precoBase);
        this.blockChain = blockchain;
        this.endereceDeContratoNFT = endereceDeContratoNFT;
    }
    public String getBlockChain(){return blockChain;}
    public void setBlockChain(String blockChain){this.blockChain = blockChain;}


    public String getEndereceDeContratoNFT(){return endereceDeContratoNFT;}
    public void setEndereceDeContratoNFT(String endereceDeContratoNFT){this.endereceDeContratoNFT = endereceDeContratoNFT;}

    @Override
    public String toString(){return "Este Quadro (id "+ identificador +"): "+ nomeObra + ", de " + autor + " custa: " + precoBase +" euros. BlockChain:" + blockChain + "Contrato: "+ endereceDeContratoNFT ;}
}
