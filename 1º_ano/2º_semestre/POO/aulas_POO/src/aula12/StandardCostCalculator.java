package aula12;

public class StandardCostCalculator implements IContactCostCalculator{
    


    public double calculateCost(double unit, ContactType contactType){
        if(contactType.equals(ContactType.EMAIL)){
            return 0;
        }
        
        double result = unit*0.10;
        
        return Math.round(result*100.0)/100.0;
        

    }
    
}