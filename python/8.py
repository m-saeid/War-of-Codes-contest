from itertools import combinations

def basket(anar, limit, r, t):
    if r > len(anar):
        return t
    if sum(anar)<limit:
        return t
    
    comb = list(combinations(anar, r))
    min = float("inf")
    min_idx = 0
    for i in range(len(comb)):
        if limit <= sum(comb[i]) < min:
            min = sum(comb[i])
            min_idx = i
    if min != float("inf"):
        # print(comb[min_idx])
        t += 1
        for i in comb[min_idx]:
            anar.remove(i)
        t = basket(anar, limit, r, t)
    t= basket(anar, limit, r+1, t)
    return t

tedad = int(input())
data = input()
anar = [int(i) for i in data.split()]
limit = int(input())
print(basket(anar, limit, 1, 0))
