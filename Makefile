CFLAGS=gcc -Wall -Wextra -Werror

all: invertir multiplicar mainEc2g

invertir: invertir.c
	$(CFLAGS) -o invertir invertir.c

multiplicar: multiplicar.c
	$(CFLAGS) -o multiplicar multiplicar.c

mainEc2g: mainEc2g.o ec2g.h
	$(CFLAGS) -o mainEc2g mainEc2g.o ec2g.o

mainEc2g: mainEc2g.c ec2g.h
	$(CFLAGS) -c mainEc2g.c

ec2g: ec2g.c ec2g.h
	$(CFLAGS) -c ec2g.c
