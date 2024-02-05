public class Calculator {
	public void createAccount(String Name, String Phone) {
    	account acc = new account();
    	acc.Name = Name;
    	acc.Phone = Phone;
    	insert acc;
    	System.debug('Account has been created:' + acc.Name);
	}
    
	public void updateAccount(String NewName) {
    	List<Account> oldAccount = new List<Account>();
    	for(Account acc : [select name from Account where Phone='6969696969']){
        	acc.Name = NewName;
        	oldAccount.add(acc);
        	System.debug('Account has been updated:' + acc.Name);
    	}
    	update oldAccount;
	}
    
	public void deleteAccount() {
    	List<Account> accounts = new List<Account>();
    	for(Account acc : [select Name,Phone from Account where Phone='6969696969']) {
        	delete acc;
        	System.debug('Account deleted:' + acc.Name);
    	}
    	update accounts;
	}
}
