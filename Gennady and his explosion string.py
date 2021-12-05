s = input()
exp = input()


prev = s
while True:
    s = s.replace(exp, '')
    if s == prev:
        break
    prev = s
    
if s == '':
	print("FRULA")
else:
    print(s)