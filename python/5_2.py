# دریافت تعداد کتاب‌ها
n = int(input("تعداد کتاب‌ها را وارد کنید: "))

# دریافت متن هر کتاب
books = [input("کتاب " + str(i+1) + ": ") for i in range(n)]

# دریافت جمله هدف
target_sentence = input("جمله هدف را وارد کنید: ")

# شمارش تعداد تکرار جمله هدف در هر کتاب
counts = [book.count(target_sentence) for book in books]

# چاپ نتایج
for count in counts:
    print(count)
