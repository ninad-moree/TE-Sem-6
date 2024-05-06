public class MarkSheet {
    public void calcGrade(integer lp2, integer wtl, integer dsbdal) {
        integer total = lp2 + wtl + dsbdal;

        if(total >= 270)
            system.debug('A grade');
        else if (total >= 240 && total < 270)
            system.debug('B garde');
        else if (total >= 200 && total < 240)  
            system.debug('C grade');
        else
            system.debug('Pass');
    }
}