''' 
| - container2file.py
'''

import pickle
import json

def container2file(container, filename):
    with open(filename, "w") as file:
        file.write(container.toJSON())


if __name__ == "__main__":
    from .. import gather as gather
    container = gather("dataset/vader.png", max_level)
    container2file(container, "dataset/vader_container.bsqdata")