public class TarefaCostCalculator implements ITarefaCostCalculator {
    
    @Override
    public double calculate(Tarefa t){
        int prioridade = t.getPrioridade();
        switch(prioridade){
            case 1:
                return 1.00;
            case 2:
                return 1.00;
            case 3:
                return 2.50;
            case 4:
                return 2.50;
            case 5: 
                return 5.00;
            default:
                return 0.00;
        }
        

    }
}
