import java.util.Comparator;

class SortByCost implements Comparator<Concert>{
    StandardConcertProfitCalculator calculadora = new StandardConcertProfitCalculator();
    @Override
    public int compare(Concert c1, Concert c2) {
        double profit1 = calculadora.calculateConcertProfit(c1);
        double profit2 = calculadora.calculateConcertProfit(c2);

        return Double.compare(profit2, profit1);
        

               
    }

}