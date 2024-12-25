
key = int(input())
w1 = input()
w2 = ""
for i in range(len(w1)):
    w2 += chr(ord(w1[i]) - key) if ord('a')<=ord(w1[i]) - key<=ord('z') else \
    (chr(ord(w1[i]) - key+ (ord('z')-ord('a')+1)) if ord(w1[i]) - key<ord('a') \
    else chr(ord(w1[i]) - key - (ord('z')-ord('a')+1)))
print(w2)

