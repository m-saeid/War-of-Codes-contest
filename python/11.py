from itertools import combinations
hasan = int(input())
tedad = int(input())
data = input()
zamin = [int(i) for i in data.split()]
maxcard = ()
maxcount= 0
for i in range(1, tedad+1):
    comb = list(combinations(zamin, i))
    for j in comb:
        if sum(j)==(11-hasan):
            if len(j)>maxcount:
                maxcoutn = len(j)
                maxcard = j
#     print([j if sum(j)==(11-hasan) else -1 for j in comb])
print(len(maxcard))