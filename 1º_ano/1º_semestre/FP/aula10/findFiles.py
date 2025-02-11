import os

def printDirFiles(d):
    lst = os.listdir(d)
    for fname in lst:
        path = os.path.join(d, fname)
        if os.path.isfile(path):
            ftype = "FILE"
        elif os.path.isdir(path):
            ftype = "DIR"
        else:
            ftype = "?"
        print(ftype, path)
    return


def findFiles(d, ext):
    # Complete...
    lst = os.listdir(d)
    match_files = []
    for fname in lst:
        path = os.path.join(d, fname)
        if os.path.isfile(path):
            filename, file_ext = os.path.splitext(path)
            if file_ext == ext:
                match_files.append(filename)
        elif os.path.isdir(path):
            findFiles(path,ext)
        else:
            
    return match_files



def main():
    print("Testing printDirFiles('..'):")
    printDirFiles("..")

    print("\nTesting findFiles('.', '.py'):")
    lst = findFiles(".", ".py")
    print(lst)
    assert isinstance(lst, list)

    print("\nTesting findFiles('..', '.csv'):")
    lst = findFiles("..", ".csv")
    print(lst)

if __name__ == "__main__":
    main()

