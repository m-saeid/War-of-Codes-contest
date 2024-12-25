def max_subarray_sum_circular(arr):
    def kadane(arr):
        max_current = max_global = arr[0]
        for num in arr[1:]:
            max_current = max(num, max_current + num)
            if max_current > max_global:
                max_global = max_current
        return max_global

    max_kadane = kadane(arr)

    # Case 2: Now find the max sum that includes corner elements.
    max_wrap = 0
    for i in range(len(arr)):
        max_wrap += arr[i]
        arr[i] = -arr[i]

    max_wrap = max_wrap + kadane(arr)

    if max_wrap == 0:
        return max_kadane

    return max(max_kadane, max_wrap)

# دریافت ورودی
arr = list(map(int, input("ورودی را وارد کنید: ").split()))

# محاسبه حداکثر مجموع زیرآرایه غیرخالی در آرایه دایره‌ای
result = max_subarray_sum_circular(arr)

# چاپ نتیجه
print(result)
