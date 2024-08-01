
def insertion_sort(l):
    for i in range(1,len(l)):
        j=i-1
        temp=l[i]
        while(j >= 0):
            if(l[j] > temp):
                l[j+1]=l[j]
            else:
                break
            j-=1
        l[j+1]=temp
    print(l)

l = [10, 6, 2, 4]
insertion_sort(l)
# def insertion_sort(l):
#     for i in range(1, len(l)):
#         temp = l[i]
#         j = i - 1
#         while j >= 0 and l[j] > temp:
#             l[j + 1] = l[j]
#             j -= 1
#         l[j + 1] = temp
#     print(l)

# l = [10, 6, 2, 4]
# insertion_sort(l)






























