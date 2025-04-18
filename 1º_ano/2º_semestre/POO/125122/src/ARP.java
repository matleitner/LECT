public class ARP extends Trama {
    private Tipo tipo;
    private String mensagem;


    ARP(String enderecoMACsource, String enderecoMACdestino, Tipo tipo, String mensagem){
        super(enderecoMACsource, enderecoMACdestino);
        this.tipo= tipo;
        this.mensagem = mensagem;
        
        }   
    
    public enum Tipo{
        REQUEST,
        REPLY
    }
    public String getMensagem(){ return mensagem;}
    public Tipo getTipo() {
        return tipo;
    }
    @Override
    public String toString() {
        return "ARP (source_mac=" + this.getMACSource() + ", destination_mac=" + this.getMACdestino() + " tipo: " + this.getTipo() + ") msg: " + mensagem;  
    }
}
