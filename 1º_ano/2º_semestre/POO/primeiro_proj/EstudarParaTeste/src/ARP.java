public class ARP extends Trama {
    public enum Tipo { REQUEST, REPLY }

    private Tipo tipo;
    private String mensagem;

    public ARP(String source, String destino, Tipo tipo, String mensagem) {
        super(source, destino);
        this.tipo = tipo;
        this.mensagem = mensagem;
    }

    @Override
    public String toString() {
        return "ARP{" +
                "source='" + getSource() + '\'' +
                ", destino='" + getDestino() + '\'' +
                ", tipo=" + tipo +
                ", mensagem='" + mensagem + '\'' +
                '}';
    }
}



