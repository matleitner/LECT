public class IPv4 extends Trama {
    private String mensagem;
    private String enderecoIPv4source;
    private String enderecoIPv4destino;
    private int numSequencia;
    static int contadorSeq = 100;

    IPv4(String enderecoMACsource, String enderecoMACdestino, String enderecoIPv4source,String enderecoIPv4destino , String mensagem){
        super(enderecoMACsource, enderecoMACdestino);
        this.enderecoIPv4source = enderecoIPv4source;
        this.enderecoIPv4destino = enderecoIPv4destino;
        this.mensagem = mensagem;
        this.numSequencia = contadorSeq;
        contadorSeq++;
        }   

    public String getMensagem(){ return mensagem;}
    public String getIPv4Source() { return enderecoIPv4source;}
    public String getIPv4Destino(){ return enderecoIPv4destino;}


    
    @Override
    public String toString() {
        return "IPv4 (source_mac=" + enderecoMACsource + ", destination_mac=" + enderecoMACdestino + " source_ipv4: " + enderecoIPv4source + ", destination_source:  " + enderecoIPv4destino + " seq:" + numSequencia + " msg: " + mensagem;  
    }
}
