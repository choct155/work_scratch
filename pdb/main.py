#! /home/choct155/tools/miniconda3/bin/ipython

from typing import *
from fib import *
from ToyMod import *

def main():
    
    # Let's grab a list of quotients
    td: List[int] = toyDiv()

    # Python supports higher order functions but not currying
    xs: List[int] = list(range(1, 6))
    fs: Dict[Callable[[int, int], int], str] = {
        add: f"The sum of {xs} is ",
        prod: f"The product of {xs} is "
    }
    
    for i,f in enumerate([prod, add]):
        result: int = intMap(xs, i, f)
        print(f"{fs[f]} {result}")

                
if __name__ == "__main__":
    main()
    

