#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
DOWN, LEFT, RIGHT, UP = 0, 1, 2, 3


# In[3]:


class cordinate:
    def __init__(self, table, y = 0, x = 0, t =5):
        self.row = y
        self.col = x
        self.n = t
        self.table = table

    def move_up(self):
        if self.row > 0 and self.table[self.row-1][self.col]==0:
            self.row -= 1
            return True
        return False

    def move_down(self):
        if self.row < self.n-1 and self.table[self.row+1][self.col]==0:
            self.row += 1
            return True
        return False
    
    def move_right(self):
        if self.col < self.n-1 and self.table[self.row][self.col+1]==0:
            self.col += 1
            return True
        return False
    
    def move_left(self):
        if self.col > 0 and self.table[self.row][self.col-1]==0:
            self.col -= 1
            return True
        return False


# In[19]:


def move(current, before_side, num_moves):
    m1, m2, m3 = float("inf"), float("inf"), float("inf")
    if current.row == current.n - 1:
        return num_moves
    num_moves += 1
    if current.move_down():
        m1 = move(current, UP, num_moves)	
        current.move_up()
    if before_side != LEFT:
        if current.move_left():
            m2 = move(current, RIGHT, num_moves)
            current.move_right()
    if before_side != RIGHT:
        if current.move_right():
            m3 = move(current, LEFT, num_moves)
            current.move_left()
    return m1 if m1<m2 and m1<m3 else m2 if m2<m3 else m3


# In[25]:


nm = list(map(int, input().split()))
n = nm[0]
m = nm[1]
table = [] 
for i in range(n):
    table.append(list(map(int, input().split())))
table = np.array(table)
start = cordinate(table, 0, m, n);
min = move(start, UP, 0)
print(-1 if min == float("inf") else min)

