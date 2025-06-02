import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Reserva {
    private static int counter =1;
    private int codigo;
    private Clients cliente;
    private LocalDate dataEntrada;
    private LocalDate dataSaida;
    private Rooms quarto;
    private double valorTotal;

    
    
    public Reserva( Clients cliente, LocalDate dataEntrada, LocalDate dataSaida){
        this.codigo = counter++;
        this.cliente = cliente;
        this.dataEntrada = dataEntrada;
        this.dataSaida = dataSaida;
        long dias = ChronoUnit.DAYS.between(dataEntrada,dataSaida);
        this.valorTotal = dias * quarto.getPriceForNight();

    }
    @Override
    public String toString() {
        return "A reserva nº"+ codigo +" ficara marcada para dias"+ dataEntrada +" e "+ dataSaida + ", ficará um total de: " + valorTotal +" euros.";

    }

}
