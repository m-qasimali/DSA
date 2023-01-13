# print decreasing using recursion
# from string import digits


# def decrease(n):
#     if n < 0:
#         return
#     print(n)
#     decrease(n-1)

# # fibonacci numbers
# def fib(n):
#     nmbrs = [0,1]
#     if n==1:
#         print(nmbrs[0])
#     elif n==2:
#         print(nmbrs[0],nmbrs[1],sep="\n")
#     else:
#         print(nmbrs[0],nmbrs[1],sep="\n")
#         for i in range(2,n):
#             nmbrs.append(nmbrs[i-1] + nmbrs[i-2])
#             print(nmbrs[i])

# def getDigit(n):
#     digits = -1
#     t = n
#     while t!=0:
#         digits += 1
#         t //= 10
#     divisor = pow(10,digits)
#     while n!= 0:
#         print(n//divisor)
#         n %= divisor
#         divisor //= 10

# Bar graph

# def barGraph(data):
#     Max = max(data)
#     for i in range(Max,0,-1):
#         for j in data:
#             if j<i:
#                 print(" ",end="     ")
#             else:
#                 print("0",end="     ")
#         print()


# largest area histogram
def largestRectangleArea(heights) -> int:
        lb = [-1]
        s1 = [0]
        for i in range(1,len(heights)):
            while len(s1)>0 and heights[len(s1)-1] >= heights[i]:
                s1.pop()
            if len(s1) == 0:
                lb.append(-1)
            else:
                lb.append(s1[len(s1)-1])
            s1.append(i)
        print(lb)

def findCelebrity(data):
    strength = len(data)
    s = []
    for i in range(strength):
        s.append(i)
    while len(s)!=1:
        i=s.pop()
        j=s.pop()
        if data[i][j] == 1:
            #if i knows j then j is celebrity
            s.append(j)
        else:
            #if j knows i then i is celebrity
            s.append(i)
    pot = s.pop()
    
    for i in range(strength):
        if i!=pot:
            if data[pot][i] == 1 or data[i][pot] == 0:
                return None
    return pot

# if __name__ == "__main__":
#     print(findCelebrity([[0,0,1,0],[0,0,1,0],[0,0,0,0],[0,0,1,0]]))

a = [4]
if a:
    print("k")
