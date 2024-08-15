func lemonadeChange(bills []int) bool {
    var five int
    var ten int

    for _, bill := range bills {
        if bill == 10 {
            ten++
        } else if bill == 5 {
            five++
        }

        charge := bill-5
        for charge > 0 {
            if ten > 0 && charge >= 10 {
                ten--;
                charge-=10
            } else if five > 0 && charge >= 5 {
                five--;
                charge-=5
            } else { return false }
        }
    }

    return true
}