import java.time.LocalDateTime;

public class StandardChargeCostCalculator implements IChargeCostCalculator {
    
    @Override
    public double calculateChargeCost(Charge c){
        double unidade = c.getUnidade();
        double custo = unidade * 0.15;
        LocalDateTime data = c.getData();
        int hora = data.getHour();
        if(12<hora && hora<14 || 19<hora && hora<24) 
            custo += 5;
        if(22< hora && hora <24 || 0< hora && hora<6)
            custo*=0.5;
        
        return custo;
    }
    
}
