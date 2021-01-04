''' 
| - file2container.py
'''
import pickle

def file2container(filename):
    with open(filename, "rb") as mypicklefile:
        container = pickle.load( mypicklefile)

    return container

if __name__ == "__main__":
    pass