def Counting_Sort(data):
    n = max(data) + 1
    count = [0] * n
    for item in data:
        count[item] += 1
    k = 0
    for i in range(n):
        for j in range(count[i]):
            data[k] = i
            k += 1