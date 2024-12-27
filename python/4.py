#!/usr/bin/env python
# coding: utf-8

# In[ ]:


def sum_digits(n):
    s = 0
    while n!=0:
        s += n % 10
        n //= 10
    return s

c = 0
m = int(input())
n = int(input())
for i in range (m, n+1):
    if i % sum_digits(i) == 0:
        c += 1
print(c)

