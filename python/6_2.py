def decrypt_message(encrypted_message, shift):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    decrypted_message = ''
    for char in encrypted_message:
        if char in alphabet:
            char_index = alphabet.index(char)
            decrypted_index = (char_index - shift) % len(alphabet)
            decrypted_message += alphabet[decrypted_index]
        else:
            decrypted_message += char
    return decrypted_message

# دریافت پیام رمزگذاری شده و مقدار شیفت
shift = int(input("مقدار شیفت را وارد کنید: "))
encrypted_message = input("پیام رمزگذاری شده را وارد کنید: ")

# رمزگشایی پیام
decrypted_message = decrypt_message(encrypted_message, shift)

# چاپ پیام رمزگشایی شده
print(decrypted_message)
