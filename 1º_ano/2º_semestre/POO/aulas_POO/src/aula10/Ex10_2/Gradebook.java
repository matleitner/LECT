package aula10.Ex10_2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
public class Gradebook {
    
    // public Student estudante;
    public ArrayList<Student> listaStudents;
    public Gradebook(){
        this.listaStudents = new ArrayList<>();
    }
    public void load(String filename){
        try(Scanner sc = new Scanner(new File(filename))){
            while(sc.hasNextLine()){
                Student estudante = new Student(null, null);
                String[] infoAluno = sc.nextLine().split("\\|");
                List<Double> grades = new ArrayList<>();
                estudante.setName(infoAluno[0]);
                grades.add(Double.parseDouble(infoAluno[1]));
                grades.add(Double.parseDouble(infoAluno[2]));
                grades.add(Double.parseDouble(infoAluno[3]));
                estudante.setGrades(grades);
                listaStudents.add(estudante);
            
            }
        
        }
         catch (FileNotFoundException e) {
            e.printStackTrace();

        }
    }   
    public void addStudent(Student student){
        listaStudents.add(student);
    }
    public void removeStudent(String nomeStudent) {
        listaStudents.removeIf(student -> student.getName().equals(nomeStudent));
    }
    public Student getStudent(String nomeStudent){
        for(Student student2 : listaStudents){
            if(nomeStudent.equals(student2.getName())){
                return student2;
            }
        }
        return null;
    }

    public double calculateAverageGrade(String nomeStudent){
        
        Student estudante = listaStudents.stream().filter(n-> n.getName().equals(nomeStudent)).findFirst().orElse(null);
        return (estudante.getGrades().stream().mapToDouble(Double::doubleValue).sum())/3;
        
        
    }

    public void printAllStudents(){
        listaStudents.forEach(s -> System.out.printf("Nome: %s, Média: %.2f%n", s.getName(), calculateAverageGrade(s.getName())));
    }
}
