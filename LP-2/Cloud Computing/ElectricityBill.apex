public class ElectricityBill {
    public void bill(integer unitUsed, integer unitRate) {
        integer bill;
        
        bill = unitUsed * unitRate;
        
        system.debug('Your bill = ' + bill);
    }
}