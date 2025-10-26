def curry(func, arrity):
    def curring(*args):
        if len(args) == arrity:
            return func(*args)
        elif len(args) > arrity:
            raise Exception("incorrect arrity")
        else:

            def insert(*new_args):
                return curring(*(args + new_args))

        return insert

    return curring


def uncurry(func_curry, arrity):
    def uncurring(*args):
        if len(args) != arrity:
            raise Exception("incorrect arrity")
        current = func_curry
        for i in args:
            current = current(i)
        return current

    return uncurring


def sum3(x, y, z):
    return x + y + z


ss = curry(sum3, 3)
unc = uncurry(ss, 3)

print(ss(1, 2)(3))
print(unc(1, 2, 3))
