#!/usr/bin/env python
# coding: utf-8

# In[57]:


def erase(s, idx):
    return s[:idx] + s[idx + 1:]

def min_del(num, k):
	if(k == 0):
		return num
	snum = str(num)
	l = len(snum)
	min = int(erase(snum, 0))
	for i in range(1, l):
		if int(erase(snum, i)) < min:
			min = int(erase(snum,i))
	res = min_del(min, k-1)	
	return res;


# In[ ]:


nk = list(map(int, input().split()))
n = nk[0]
k = nk[1]
num = int(input())
print(min_del(num, k))

