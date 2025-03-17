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

    @Override
    public String toString(){
        return make + " " + model + ", " + year + ", kms: " + kms;

    }


    public void drive(int distance) {
        //TODO: acumular distância percorrida
        kms += distance; 
    }
}

public class SimpleCarDemo {

    static Scanner sc = new Scanner(System.in);
    

    static void listCars(Car[] cars) {
        System.out.println("Lista de carros registados");

        for (int i = 0; i<cars.length; i++) {
            
            System.out.println(cars[i].toString());
        
        }
        // TODO: lista todos os carros registados
        // Exemplo de resultado
        // Carros registados: 
        // Renault Megane Sport Tourer, 2015, kms: 35356
        // Toyota Camry, 2010, kms: 32456
        // Mercedes Vito, 2008, kms: 273891
    }

    public static void main(String[] args) {

        Car[] cars = new Car[3];// TODO: completar
        cars[0] = new Car("Renault", "Megane Sport ", 2015, 35356);// TODO: completar
        cars[1] = new Car("Toyota", "Camry", 2010,  32456); // TODO: completar
        cars[2] = new Car("Mercedes" ,"Vito", 2008, 273891); // TODO: completar

        listCars(cars);

        // Adicionar 10 viagens geradas aleatoriament
        for (int i=0; i<10; i++) {
            int j = (int)Math.round(Math.random()*2); // escolhe um dos 3 carros
            int kms = (int)Math.round(Math.random()*1000); // viagem até 1000 kms
            System.out.printf("Carro %d viajou %d quilómetros.\n", j, kms);
            
            // TODO: adicionar viagem ao carro j
            cars[j].drive(kms);
        }

        listCars(cars);

        sc.close();

    }
}