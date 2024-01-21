s = input()
print(max(69 - ord(s[0]), 0) + 0 if s[1:] == "0" else float(s[1:] + "0.3"))
