package aula04;
import java.util.Scanner;

class Car {
    public String make;
    public String model;
    public int year;
    public int kms;

    public Car(String make, String model, int year, int kms) {
        this.make = make;
        this.model = model;
        this.year = year;
        this.kms = kms;
    }

    public void drive(int distance) {
        kms += distance;
        //TODO: acumular distância percorrida
    }

    @Override
    public String toString(){
        
        return make + " " + model + ", " + year + ", kms: " + kms;
    }
}

public class CarDemo {

    static Scanner sc = new Scanner(System.in);

    static int registerCars(Car[] cars) {
        // TODO: pede dados dos carros ao utilizador e acrescenta ao vetor
        // registo de carros termina quando o utilizador inserir uma linha vazia 
        // devolve número de carros registados
        int i = 0;
        System.out.print("Insira dados do carro (marca modelo ano quilómetros): ");
        while(true){
            
            String carro = sc.nextLine();
            if(carro =="") break;
            
            String[] dadosDosCarros = carro.split(" ");

            String make = dadosDosCarros[0];
            String model = dadosDosCarros[1];
            int year = Integer.parseInt(dadosDosCarros[2]);
            int kms = Integer.parseInt(dadosDosCarros[3]);


            cars[i] = new Car(make, model, year, kms);
            i++;
        }

        return cars.length;
    }

    static void registerTrips(Car[] cars, int numCars) {

        System.out.print("Registe uma viagem no formato \"carro:distância\": ");
        String trip = sc.nextLine();
        String [] tripa = trip.split(":");
        cars[Integer.parseInt(tripa[0])].kms += Integer.parseInt(tripa[1]); 
        // TODO: pede dados das viagens ao utilizador e atualiza informação do carro
        // registo de viagens termina quando o utilizador inserir uma linha vazia 
    }


    static void listCars(Car[] cars) {
        System.out.println("\nCarros registados: ");
        for (int i = 0; i< cars.length; i++ ){
            if( cars[i] != null)
            System.out.println("O carro " + i + " : " +  cars[i]);
        }
        // TODO: lista todos os carros registados
        // Exemplo de resultado
        // Carros registados: 
        // Toyota Camry, 2010, kms: 234346
        // Renault Megane Sport Tourer, 2015, kms: 32536
        
        System.out.println("\n");
    }

    public static void main(String[] args) {

        Car[] cars = new Car[10];

        int numCars = registerCars(cars);

        if (numCars>0) {
            listCars(cars);
            registerTrips(cars, numCars);
            listCars(cars);
        }

        sc.close();

    }
}