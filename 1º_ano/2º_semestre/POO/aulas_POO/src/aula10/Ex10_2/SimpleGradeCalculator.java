package aula10.Ex10_2;
import java.util.List;
public class SimpleGradeCalculator implements IGradeCalculator {
    
    
    public double calculate(List<Double> notas){
        
        return notas.stream().mapToDouble(Double::doubleValue).sum();


    }
}
