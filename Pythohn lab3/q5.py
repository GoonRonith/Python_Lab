def reverse_list(l):
    ans=[]
    for i in range(len(l),0,-1):
        ans.append(i)
    return ans

l=[1,2,3,4,5]
print(reverse_list(l))