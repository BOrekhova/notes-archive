cnt = 0
for i in range(int(input())):
    nums = input()
    if nums == "1 0 1" or nums == "1 1 0" or nums == "0 1 1" or nums == "1 1 1":
        cnt += 1
print(cnt)
