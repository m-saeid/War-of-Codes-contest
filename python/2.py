def count_pairs_with_sum(arr, target):
    count = 0
    seen = {}
    for num in arr:
        if target - num in seen:
            count += seen[target - num]
        if num in seen:
            seen[num] += 1
        else:
            seen[num] = 1
    return count

# دریافت تعداد انارها
n = int(input("تعداد انارها را وارد کنید: "))

# دریافت تعداد دانه‌های هر انار
pomegranate_seeds = list(map(int, input("تعداد دانه‌های هر انار را وارد کنید: ").split()))

# دریافت عدد هدف
target = int(input("عدد هدف را وارد کنید: "))

# شمارش جفت‌های انار با مجموع دانه‌ها برابر با عدد هدف
result = count_pairs_with_sum(pomegranate_seeds, target)

# چاپ نتیجه
print(result)