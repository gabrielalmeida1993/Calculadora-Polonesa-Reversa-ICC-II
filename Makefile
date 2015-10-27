all:
	gcc -o Calculadora main.c implementacao.c -lm
clean:
	rm Calculadora
run:
	./Calculadora