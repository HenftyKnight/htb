#!/usr/bin/python3
from sys import argv

_,file_1,file_2 = argv

with open(file_1,"rb") as f:
    file1 = f.read()

with open(file_2,"rb") as f:
    file2 = f.read()

print("\t\t\t", file_1,"-----", file_2)
for i in range(min(len(file1), len(file2))):
    if file1[i] != file2[i]:
        print(f"Byte Difference at {hex(i)} : {hex(file1[i])} ----- {hex(file2[i])}")
