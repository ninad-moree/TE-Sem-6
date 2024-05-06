public class Calculator {
    public void add(integer x, integer y) {
        integer sum = x + y;
        system.debug('Sum=' + sum);
    }
    
    public void subtract(integer x, integer y) {
        integer diff = x - y;
        system.debug('Diff=' + diff);
    }
    
    public void multiply(integer x, integer y) {
        integer multi = x * y;
        system.debug('Multi=' + multi);
    }
    
    public void divide(integer x, integer y) {
        double div = (Double)x / y;
        integer mod = x / y;
        system.debug('Divide=' + div);
        system.debug('Mod='+ mod);
    }
    
    public void root(integer x) {
       	Double ans = Math.sqrt(x);
        system.debug('Sqaure root=' + ans);
    }
}