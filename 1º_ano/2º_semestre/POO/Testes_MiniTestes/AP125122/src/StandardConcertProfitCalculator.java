public class StandardConcertProfitCalculator implements IConcertProfitCalculator {
    @Override
    public double calculateConcertProfit(Concert c){
        if(c == null) return -1;
        String paisDoConcerto = c.getLocalDoConcerto().split(",")[1].trim(); //c.getLocalDoConcerto retorna Cidade, Pais split retorna um array ["Cidade"," pais"] o trim tira o espaço 
        double minutosDeConcerto = c.getDuracao();
        double lucro = (minutosDeConcerto * 1500)/60; // 60 minutos estao para 1500, x euros, y minutos  estao para x =  (Y * 1500 )/ 60 
        if(!paisDoConcerto.equals("Portugal"))
            lucro *= 2;
        if (!paisDoConcerto.equals("Espanha") || !paisDoConcerto.equals("Portugal") )
            lucro += 800;
        // ou seja se for em portugal é o preço default se nao for em portugal duplica se for na espanha apenas duplica, se nao for nem um nem outro  dublica e acrescenta 800
        return lucro;
    }
}
