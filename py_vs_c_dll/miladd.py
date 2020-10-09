import ctypes
from datetime import datetime

libc = ctypes.CDLL("./libclib1.so")

print("---for c : 10 in outer loop, 1 million inner loop--\n");
now = datetime.now()
print("Current time=", now.strftime("%H:%M:%S.%f"))
counter = libc.tenmillion_add_function()
now = datetime.now()
print("Current time=", now.strftime("%H:%M:%S.%f"))

print("---for python : 10 in outer loop, 1 million inner loop--\n");
now = datetime.now()
print("Current time=", now.strftime("%H:%M:%S.%f"))
for j in range(100):
    sum = 0
    for i in range(1000000):
        sum += i
now = datetime.now()
print("Current time=", now.strftime("%H:%M:%S.%f"))
