power=2
n=0
def calculate_power(power,n,cnt,ans):
    if(power==0): return 1
    if(cnt==power-1): return ans
    ans=ans*n
    return calculate_power(power,n,cnt+1,ans)

print(calculate_power(power,n,0,n))
print("ronith"[::-1])