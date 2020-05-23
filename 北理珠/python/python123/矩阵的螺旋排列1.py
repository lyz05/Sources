def SpiralOrder(matrix):
    ans=[]
    Size=len(matrix)
    i=0
    while i<Size:
        j1=i
        while j1<Size-i:
            ans.append(matrix[i][j1])
            j1+=1
        j2=i+1
        while j2<Size-i:
            ans.append(matrix[j2][Size-i-1])
            j2+=1
        j3=Size-i-2
        while j3>=i:
            ans.append(matrix[Size-i-1][j3])
            j3-=1
        j4=Size-i-2
        while j4>i:
            ans.append(matrix[j4][i])
            j4-=1
        i+=1
    return ans
matrix = eval(input())
res=SpiralOrder(matrix)
print(res)