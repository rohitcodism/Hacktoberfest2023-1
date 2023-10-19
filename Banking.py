class Account:
  def __init__(self, name, balance):
    self.name = name
    self.balance = balance

  def deposit(self, amount):
    self.balance += amount

  def withdraw(self, amount):
    if amount > self.balance:
      raise ValueError("Insufficient funds")
    self.balance -= amount

  def get_balance(self):
    return self.balance

class Bank:
  def __init__(self):
    self.accounts = {}

  def create_account(self, name, balance):
    account = Account(name, balance)
    self.accounts[name] = account

  def get_account(self, name):
    return self.accounts[name]

  def deposit(self, name, amount):
    account = self.get_account(name)
    account.deposit(amount)

  def withdraw(self, name, amount):
    account = self.get_account(name)
    account.withdraw(amount)

  def get_balance(self, name):
    account = self.get_account(name)
    return account.get_balance()


if __name__ == "__main__":
  bank = Bank()

  # Create a new account
  bank.create_account("Alice", 100)

  # Deposit money into the account
  bank.deposit("Alice", 50)

  # Withdraw money from the account
  bank.withdraw("Alice", 25)

  # Get the account balance
  balance = bank.get_balance("Alice")

  print(f"Alice's balance is: {balance}")
