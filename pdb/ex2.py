#! /home/choct155/tools/miniconda3/bin/ipython

import os
import pdb

def get_path(filename):
    """ Returns file path in front of the actual file name """
    head, tail = os.path.split(filename)
    pdb.set_trace()
    return head
    


filename = __file__
print(f'path = {get_path(filename)}')
