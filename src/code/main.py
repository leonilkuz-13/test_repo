class Calc:
    def divide(self, x, y):
        if not isinstance(x, (float, int)) and not isinstance(y, (float, int)):
            raise TypeError("float or int")
        if y == 0:
            raise ZeroDivisionError("0")
        return x / y

    def add(self, x, y):
        if not isinstance(x, (float, int)) and not isinstance(y, (float, int)):
            raise TypeError("float or int")
        return x + y
