def can_partition(nums, target):
    dp = [False] * (target + 1)
    dp[0] = True

    for num in nums:
        for i in range(target, num - 1, -1):
            dp[i] = dp[i] or dp[i - num]

    return dp[target]

# دریافت تعداد هندوانه‌ها
n = int(input("تعداد هندوانه‌ها را وارد کنید: "))
watermelon_seeds = list(map(int, input("تعداد دانه‌های هر هندوانه را وارد کنید: ").split()))

# دریافت عدد هدف
target = int(input("عدد هدف را وارد کنید: "))

# بررسی اینکه آیا ترکیبی از دانه‌های هندوانه‌ها وجود دارد که مجموع دانه‌ها به عدد هدف برسد
result = can_partition(watermelon_seeds, target)

# چاپ نتیجه
print("yes" if result else "no")