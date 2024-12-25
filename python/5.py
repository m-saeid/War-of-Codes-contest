tedad = int(input())
sen = []
for i in range(tedad):
    sentence = input()
    sen.append(sentence.split())
key = input()
for i in sen:
    print(i.count(key)+i.count(key+",")+i.count(key+"."))

