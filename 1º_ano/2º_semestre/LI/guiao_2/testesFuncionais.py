import pytest
import sys
from subprocess import Popen
from subprocess import PIPE


proc = Popen("ls -la "+ sys.argv[1], stdout=PIPE, shell=True)
return_code = proc.wait()
for line in proc.stdout:
    if sys.argv[2] in line.decode("utf-8"):
        pass
    
    print(line.decode("utf-8"), end="")