import java.util.*;

public class Comutador {
    private String nome;
    private Set<String> enderecosMAC;
    private Queue<Trama> filaTramas;
    private Trama ultimaTramaEnviada;


    public Comutador(String nome) {
        if (nome.length() > 100) {
            throw new IllegalArgumentException("Nome não pode ter mais de 100 caracteres.");
        }
        this.nome = nome;
        this.enderecosMAC = new HashSet<>();
        this.filaTramas = new LinkedList<>();
        this.ultimaTramaEnviada = null;
    }


    public void adicionarEnderecoMAC(String enderecoMAC) {
        if (validarEnderecoMAC(enderecoMAC)) {
            enderecosMAC.add(enderecoMAC);
        } else {
            throw new IllegalArgumentException("Endereço MAC inválido.");
        }
    }

    
    private boolean validarEnderecoMAC(String enderecoMAC) {
        String[] partes = enderecoMAC.split(":");
        if (partes.length != 6) return false;
        for (String parte : partes) {
            if (parte.length() != 2) return false;
            for (char c : parte.toCharArray()) {
                if (!Character.isDigit(c) && (c < 'a' || c > 'f')) return false;
            }
        }
        return true;
    }

    
    public void addTrama(Trama trama) {
        filaTramas.add(trama);
        String macOrigem = trama.getSource();
        if (validarEnderecoMAC(macOrigem)) {
            enderecosMAC.add(macOrigem);}
        } 

    
    public void removeTrama(Trama trama) {
        filaTramas.remove(trama);
    }

    
    public boolean hasTramas() {
        return !filaTramas.isEmpty();
    }

    
    public void enviaTrama() {
        if (hasTramas()) {
            Trama trama = filaTramas.peek();
            if (trama.equals(ultimaTramaEnviada)) {
                System.out.println("A próxima trama é igual à última enviada. Ignorando...");
                filaTramas.poll();
                return; 
            }
            String macDestino = trama.getDestino();
    

            if (enderecosMAC.contains(macDestino)) {
                System.out.println("OK");
            }
    

            String mensagem = trama.getMensagem();
            if ("ARP".equalsIgnoreCase(mensagem)) {
                System.out.println("DISCOVER");
            } else if ("IPv4".equalsIgnoreCase(mensagem)) {
                System.out.println("OK");
            }
    

            System.out.println("Conteúdo da Trama: " + trama);
    
            ultimaTramaEnviada = trama;

            filaTramas.poll();
        }
    }

    public int getCustoDaFila() {
        int custoTotal = 0;
    
        for (Trama trama : filaTramas) {
            String macDestino = trama.getDestino();
            int p = enderecosMAC.contains(macDestino) ? 1 : 5;
    

            String mensagem = trama.getMensagem();
            int tamanho = (mensagem != null) ? mensagem.length() : 0;
    
            custoTotal += p * tamanho;
        }
    
        return custoTotal;
    }
    

    
    @Override
    public String toString() {
        return "Comutador: " + nome + "\nEndereços MAC conhecidos: " + enderecosMAC + "\nNúmero de tramas na fila: " + filaTramas.size() + "\nCusto total da fila: " + getCustoDaFila();
    }
}

