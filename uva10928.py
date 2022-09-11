#Autor: Vicente Esteban Silva Vera
#10928 My Dear Neighbours
#Usuario: Didozenny ID: 1209597
#Autoría propia

def main():
	T=int(input())
	t=0
	while t<T:
		t+=1
		P=int(input())
		minN=P+1
		houses=[]
		for x in range(P):
			s=input()
			s=s.split()
			if len(s)<minN:
				minN=len(s)
				houses.clear()
				houses.append(x+1)
			elif len(s)==minN:
				houses.append(x+1)
		for x in range(len(houses)-1):
			print(houses[x],end=' ')
		print(houses[len(houses)-1])
		if t<T:
			input()

if __name__ == "__main__":
    main()