import random
size=4
fa=open("matrixA"+str(size)+".txt","w")
fb=open("matrixB"+str(size)+".txt","w")
fI=open("matrixI"+str(size)+".txt","w") #an identity matrix
for i in range(size):
    for j in range(size): 
        fa.write(str(random.randint(-20,20))+' ')
        fb.write(str(random.randint(-20,20))+' ')
    fa.write("\n")
    fb.write("\n")
fa.close()
fb.close()
for i in range(size):
    for j in range(size):
        if i==j:
            fI.write("1")
        else:
            fI.write("0")
        fI.write(" ")
    fI.write("\n")