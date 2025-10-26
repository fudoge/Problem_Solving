type Bank struct {
    bal []int64 
    n int
}


func Constructor(balance []int64) Bank {
    return Bank{bal: balance, n: len(balance)} 
}

func (this *Bank) validate(acc int) bool {
    return acc >= 1 && acc <= this.n
}

func (this *Bank) Transfer(account1 int, account2 int, money int64) bool {
    if this.validate(account1)  && this.validate(account2) && this.bal[account1-1] >= money {
        this.bal[account1-1] -= money
        this.bal[account2-1] += money
        return true
    }
    return false
}


func (this *Bank) Deposit(account int, money int64) bool {
    if this.validate(account) {
        this.bal[account-1] += money
        return true
    } 
    return false
}


func (this *Bank) Withdraw(account int, money int64) bool {
    if this.validate(account) && this.bal[account-1] >= money {
        this.bal[account-1] -= money
        return true
    }
    return false
}


/**
 * Your Bank object will be instantiated and called as such:
 * obj := Constructor(balance);
 * param_1 := obj.Transfer(account1,account2,money);
 * param_2 := obj.Deposit(account,money);
 * param_3 := obj.Withdraw(account,money);
 */