public class IPv4 extends Trama {
    private String origemIP;
    private String destinoIP;
    private String mensagem;

    public IPv4(String source, String destino, String origemIP, String destinoIP, String mensagem) {
        super(source, destino);
        this.origemIP = origemIP;
        this.destinoIP = destinoIP;
        this.mensagem = mensagem;
    }

    @Override
    public String toString() {
        return "IPv4{" +
                "source='" + getSource() + '\'' +
                ", destino='" + getDestino() + '\'' +
                ", origemIP='" + origemIP + '\'' +
                ", destinoIP='" + destinoIP + '\'' +
                ", mensagem='" + mensagem + '\'' +
                '}';
    }
}
