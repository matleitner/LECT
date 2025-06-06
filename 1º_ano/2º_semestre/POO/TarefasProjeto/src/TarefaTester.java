// TarefaTester.java
import java.time.LocalDate;
import java.util.List;

public class TarefaTester {
    public static void main(String[] args) {
        ListaDeTarefas manager = new ListaDeTarefas();

        manager.readFile("tarefas.txt");

        // Adicionar tarefas
        
            Tarefa t1 = new Tarefa("Comprar leite", "Ir ao supermercado", LocalDate.of(2025, 1, 10), 3, "Pendente");
            Tarefa t2 = new Tarefa("Estudar Java", "Revisar Streams", LocalDate.of(2025, 2, 1), 5, "Em Progresso");
            manager.addTarefa(t1);
            manager.addTarefa(t2);
        

        // Editar tarefa
        manager.updateStatus(1, "Concluída");

        // Remover tarefa
        manager.removeTarefa(2);

        // Calcular custo
        Tarefa t = manager.getTarefa(1);
        if (t != null) {
            ITarefaCostCalculator calculator = new TarefaCostCalculator();
            System.out.println("Custo da tarefa: €" + calculator.calculate(t));
        }

        // Listar todas as tarefas
        manager.printAllTarefas();

        // Filtrar por data
        List<Tarefa> futuras = manager.getTarefasDueAfter(LocalDate.of(2025, 1, 1));
        System.out.println("Tarefas com data superior a 01/01/2025:");
        futuras.forEach(System.out::println);

        manager.writeFile("tarefasw.txt");
    }
}