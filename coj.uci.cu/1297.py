lista=[]
Num=int(raw_input())
for b in range(Num):
    a=int(raw_input())
    lista.append(a)
for i in lista:
    b=i%495
    if b==0:
        print('YES')
    else:
        print('NO')
