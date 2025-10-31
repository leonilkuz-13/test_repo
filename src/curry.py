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
        func = func_curry
        for i in args:
            func = func(i)
        return func

    return uncurring
