import java.time.LocalDate;
import java.util.Comparator;
import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;
import java.io.File;
import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;
import java.util.TreeSet;
import java.util.Set;


public class ListaDeTarefas {
    private List<Tarefa> listaDeTarefas;
    

    public ListaDeTarefas() {
        this.listaDeTarefas = new ArrayList<>() ;
    }
    public void addTarefa(Tarefa t){
        if(!listaDeTarefas.contains(t))
            listaDeTarefas.add(t);
        else{ System.out.println("Erro"); }
        }
    public void removeTarefa(int id){
        listaDeTarefas.removeIf(n -> n.getId()==id);
    }
    public Tarefa getTarefa(int id){
        return listaDeTarefas.stream().filter(n -> n.getId() ==id).findFirst().orElse(null);

    }
    public void updateStatus(int id, String newStatus){
        Tarefa t = this.getTarefa(id);
        t.setEstado(newStatus);
    }
    public Set<Tarefa> getTasksByPriority(int priority){
        Set<Tarefa> listaOrganizada = new TreeSet<>(Comparator.comparingInt(p -> p.getPrioridade()));
        
        for(Tarefa t: listaDeTarefas){
            listaOrganizada.add(t);    
        }
        
        return listaOrganizada;
    }

    public List<Tarefa> getTarefasDueAfter(LocalDate date){
        List<Tarefa> listaDeTarefasDepoisDaData = new ArrayList<>(); 
        listaDeTarefasDepoisDaData.addAll(listaDeTarefas.stream().filter(n->n.getDataLimite().isAfter(date)).collect(Collectors.toList()));
        return listaDeTarefasDepoisDaData;
    }
    public void printAllTarefas(){
        listaDeTarefas.forEach(System.out::println);
    }
    public void readFile(String filename){
        try(Scanner sc = new Scanner(new File(filename))){
            while(sc.hasNextLine()){
                String[] splitado = sc.nextLine().split(";");
                String[] data = splitado[2].split("-");
                Tarefa t = new Tarefa(splitado[0],splitado[1], LocalDate.of(Integer.parseInt(data[0]),Integer.parseInt( data[1]),Integer.parseInt(data[2])), Integer.parseInt(splitado[3]), splitado[4]);   //int id, String tituloDaTarefa, String descricao, LocalDate dataLimite, int prioridade,String estado
                addTarefa(t);
            }
        }catch(IOException e){
            e.printStackTrace();

        }
    }
    public void writeFile(String filename){
        try(FileWriter fw = new FileWriter(filename)){
            for(Tarefa t : listaDeTarefas){
                fw.write(t.getTituloDaTarefa()+ ";"+ t.getDescricao()+ ";"+ t.getDataLimite() + ";" + t.getPrioridade() + ";" + t.getEstado() + "\n");
            }

        }catch(IOException e){
            e.printStackTrace();
        }

    }

}
