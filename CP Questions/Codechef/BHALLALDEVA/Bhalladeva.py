# CODECHEF -PRACTICE -BHALLALADEVA(AMR15D)
n=input()
l=map(int,raw_input().split())
l.sort()
l2=[l[0]]
for i in range(1,len(l)):
    l2.append(l[i]+l2[i-1])
for t in range(input()):
    k=input()
    s=0
    i=0
    cnt=len(l)
    if k==0:
        h=len(l)
    elif cnt%(k+1)==0:
        h=cnt//(k+1)
    else:
        h=cnt//(k+1)+1
    s=l2[h-1]
    print s