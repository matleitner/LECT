# Example: Listing directories and using file paths and metadata.

import os
import sys

# Ask the user for a directory name, and validate it.
def getDir(prompt):
    while True:
        name = input(prompt)
        if os.path.isdir(name): break
        print("{} não é diretório".format(name), file=sys.stderr)
    return name

# Print a list of files (and their sizes) in the given directory.
def listDirSizes(dname):
    lst = os.listdir(dname)
    for name in lst:
        # path = dir + "/" + name   	# not ideal...
        path = os.path.join(dname, name)	# this is better
        st = os.stat(path)		# get metadata about this path
        print(name, path, st.st_size)

def main():
    dname = getDir("Dir? ")
    print("Listing:", dname)
    listDirSizes(dname)


main()

