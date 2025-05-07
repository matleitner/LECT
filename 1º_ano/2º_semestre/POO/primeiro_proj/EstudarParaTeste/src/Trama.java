public abstract class Trama {
    private String source;
    private String destino;
    private String mensagem;


    public Trama(String source, String destino) {
        this.source = source;
        this.destino = destino;
        this.mensagem = mensagem;
    }

    public String getSource() {
        return source;
    }

    public String getDestino() {
        return destino;
    }

    public String getMensagem() {
        return mensagem;
    }
    @Override
    public abstract String toString();
}
