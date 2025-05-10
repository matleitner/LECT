package aula10.Ex10_3;
import java.util.List;

public class Customer implements Comparable<Customer>{
    private int customerId;
    private List<Double> meterReadings;

    public Customer(int customerId, List<Double> meterReadings) {
        this.customerId = customerId;
        this.meterReadings = meterReadings;
    }

    public int getCustomerId() {
        return customerId;
    }

    public void setCustomerId(int customerId) {
        this.customerId = customerId;
    }

    public List<Double> getMeterReadings() {
        return meterReadings;
    }

    public void setMeterReadings(List<Double> meterReadings) {
        this.meterReadings = meterReadings;
    }
    @Override
    public int compareTo(Customer obj){
        return Integer.compare(this.getCustomerId(),obj.getCustomerId());
    }
}
