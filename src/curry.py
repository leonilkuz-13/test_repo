def curry(func, arity):
    if not isinstance(arity, int):
        raise TypeError("arity is not integer")
    if arity < 0:
        raise ValueError("arity must be non-negative")
    if arity > func.__code__.co_argcount:
        raise ValueError("arity exceeds function's actual argument count")

    def curried(*args):
        if len(args) == arity:
            return func(*args)
        elif len(args) > arity:
            raise ValueError("there are more arguments than arity")
        else:

            def inner(*new_args):
                return curried(*(args + new_args))

            return inner

    return curried


def uncurry(curried_func, arity):
    if not isinstance(arity, int):
        raise TypeError("arity is't integer")
    if arity < 0:
        raise ValueError("arity must be non-negative")

    def uncurried(*args):
        if len(args) != arity:
            raise ValueError("there are more arguments than arity")

        result = curried_func
        for arg in args:
            if not callable(result):
                raise TypeError("Curried function returned non-callable intermediate result")
            result = result(arg)
        return result

    return uncurried
