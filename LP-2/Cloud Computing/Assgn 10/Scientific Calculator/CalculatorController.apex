public class CalculatorController {
    public Integer num1 { get; set; }
    public Integer num2 { get; set; }
    public Integer result { get; set; }

    public void add() {
        result = num1 + num2;
    }

    public void subtract() {
        result = num1 - num2;
    }

    public void multiply() {
        result = num1 * num2;
    }

    public void divide() {
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            ApexPages.addMessage(new ApexPages.Message(ApexPages.Severity.ERROR, 'Cannot divide by zero'));
        }
    }
}
