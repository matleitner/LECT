package aula10.Ex10_3;
import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;
import java.util.TreeSet;
import java.util.List;
public class EnergyUsageReport {

    public ArrayList<Customer> listaClientes;

    public EnergyUsageReport(){
        this.listaClientes = new ArrayList<>();
    }
    public void load(String filename){
        try(Scanner sc = new Scanner(new File(filename))){
            while(sc.hasNextLine()){
                String[] clients = sc.nextLine().split("\\|");
                List<Double> listaLecture = new ArrayList<>();
                listaLecture.add(Double.parseDouble(clients[1]));
                listaLecture.add(Double.parseDouble(clients[2]));
                listaLecture.add(Double.parseDouble(clients[3]));
                
                
                Customer cliente = new Customer(Integer.parseInt(clients[0]),listaLecture);
                
                
                
                listaClientes.add(cliente);
            
            
            }
        }catch(FileNotFoundException e){
            e.printStackTrace();
        }


    }    

    public void addCustomer(Customer cliente){
        listaClientes.add(cliente);
    }
    public void removeCustomer(int id){
        listaClientes.removeIf(s -> (s.getCustomerId()==id));



    }

    public Customer getCustomer(int id){

        return listaClientes.stream().filter(s -> (s.getCustomerId()==id)).findFirst().orElse(null);
    }

    public double calculateTotalUsage(int id){
        Customer cliente =  listaClientes.stream().filter(s -> (s.getCustomerId()==id)).findFirst().orElse(null);
        if (cliente == null) return 0.0;
        
        double sum =  cliente.getMeterReadings().stream().mapToDouble(Double::doubleValue).sum();
        return sum;
    
    }
    public void generateReport(String filename){
        try(FileWriter writer = new FileWriter(filename,true)){
            TreeSet<Customer> listaCliente = new TreeSet<>(listaClientes);

            writer.write("ID\tEnergia Consumida\n");
            for(Customer s: listaCliente){
                writer.write(s.getCustomerId()+" \t "+calculateTotalUsage(s.getCustomerId())+"\n"); //perguntar este /t 
            }
        }catch (IOException e){
            System.out.println(e.getMessage());
        }
    }
}

