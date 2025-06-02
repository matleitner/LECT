import java.util.Scanner;


import java.io.File;
import java.io.IOException;





public class App {
    private int id;
    private static int counter = 0;

    public App(){
        this.id = counter++;
    }
    @Override
    public String toString() {
        return Integer.toString(id);
    }


    public static void load(String file){
        try(Scanner flieSCAN = new Scanner(new File(file))){
            
            while (flieSCAN.hasNextLine()) {
                
                App now = new App();
                System.out.println("Lido: " + flieSCAN.nextLine() + " -> Criado App com ID: " + now);

                
            }
        }catch(IOException e){ 
            e.printStackTrace();

        }
    }


    public static void main(String[] args) throws Exception {
        load("out.txt");
    }
}
