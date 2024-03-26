import random
with open('data.txt', 'w') as f:
    f.write("1000")
    for i in range(1,1001):
        f.write("\n")
        f.write(str(random.randint(1,10000)))
