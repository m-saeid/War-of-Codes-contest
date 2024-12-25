from itertools import combinations

def target_sum(nums, target):
    for r in range(1, len(nums) + 1):
        for subset in combinations(nums, r):
            if sum(subset) == target:
                return "yes"
    return "no"

tedad = int(input())
nums = list(map(int, input().split()))
target = int(input())
result = target_sum(nums, target)
print(result)





