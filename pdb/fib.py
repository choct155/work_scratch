def fibRec(n):
    """ Returns the first n selements of the Fibonacci sequence """
    assert (n >= 0) & isinstance(n, int)
    if n == 0:
        return 0
    if (n == 1) | (n == 2):
        return 1
    else:
        return fibRec(n - 2) + fibRec(n - 1)


def fibTail(n, a=0, b=1):
    assert (n >= 0) & isinstance(n, int)
    if n == 0:
        return a
    if n == 1:
        return b
    else:
        return fibTail(n-1, b, a+b)

def fibSeq(n, f):
    fibIdx = list(range(1, n + 1))
    seq = map(lambda x: f(x), fibIdx)
    return seq
