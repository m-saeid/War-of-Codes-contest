#!/usr/bin/env python
# coding: utf-8

# In[ ]:


max_name=""
max_avg = -1
t = int(input())
for i in range(t):
    name_avg = list(input().split())
    name = name_avg[0]
    avg = float(name_avg[1])
    if avg > max_avg:
        max_avg = avg
        max_name = name
print(max_name)

