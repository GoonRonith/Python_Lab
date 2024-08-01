def selection_sort(l):
    for i in range(len(l)):
        min_elm=l[i]
        min_pos=i
        for j in range(i+1,len(l)):
            if(min_elm > l[j]):
                min_elm=l[j]
                min_pos=j
        temp=l[i]
        l[i]=min_elm
        l[min_pos]=temp
    print(l)
            

    
     

l = [4,5,9,3]
selection_sort(l)