package aula12;

public class StandardCostCalculator implements IContactCostCalculator{
    

    @Override
    public double calculateCost(double unit, ContactType contactType){
        if(contactType.equals(ContactType.EMAIL)){
            
        }
        switch(contactType){
            case EMAIL:
                return 0.0;

            case CELLNUMBER:
                return Math.round((unit*0.10)*1000.0)/1000.0;

            default:
                return 0.0;

        }
    }
    
}