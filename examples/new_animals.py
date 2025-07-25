from pets import Animal, call_go

class Cat(Animal):
    def go(self, n_times):
        return "meow! " * n_times
    
c = Cat()
print(call_go(c))
