#Autor: Vicente Esteban Silva Vera
#10670 - Work Reduction
#Usuario: Didozenny ID: 1209597
#Autoría propia

import math
def main():
	c=int(input());
	for x in range(c):
		N,M,L = map(int,(input().split()))
		result=[]
		for y in range(L):
			line=input()
			line=line.split(":")
			name=line[0]
			costs=line[1].split(",")
			costs=[int(x) for x in costs]
			val=N
			prize=0
			while(val!=M):
				if(math.floor(val/2)>=M and costs[1]<(val-math.floor(val/2))*costs[0]):
					val=math.floor(val/2)
					prize+=costs[1]
				else:
					prize+=costs[0]*(val-M)
					val=M
			result.append((prize,name))
		result.sort()
		print("Case",x+1)
		for y in range(L):
			print(result[y][1],result[y][0])
			

if __name__ == "__main__":
    main()
