public class GreatestNumber {
    public void greatestNum(integer x, integer y, integer z) {
        integer great;
        
        if (x >= y && x >= z) {
            great = x;
        } else if (y >= x && y >= z) {
            great = y;
        } else {
            great = z;
        }
        
        system.debug('Greatest is = ' + great);
    }
}