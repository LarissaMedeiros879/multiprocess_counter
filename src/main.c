#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <signal.h>

#define MAX 1000

void limpabuffer(char buffer[MAX]) {
	int i = 0;
	for (i = 0; i < MAX; i++) {
		buffer[i] = '\0';
	}
}

int eprimo(char* p) {
	int i = atoi(p);
	int j = i;
	int divisor = 0;
	if (i == 0 || i == 1) {
		return 0;
	}
	else {
		do {
			if (i%j == 0) {
				divisor = divisor + 1;
			}
			j--;
		}
		while (j != 0);
		if (divisor == 2) {
			//printf("primo %d\n", i);
			return 1;
		}
		else 
			return 0;
}
}

void sigquit() {
  //printf("Recebi sinalizacao para terminar!\n");
  sleep(1);
  exit(0);
} 

int main() {
	char c;
	int i = 0;
	char buffer[MAX];
	limpabuffer(buffer);
	
	int protection = PROT_READ | PROT_WRITE;
  	int visibility = MAP_SHARED | MAP_ANON;
  	
  	int *contador;
  	contador = (int*) mmap(NULL, sizeof(int)*100, protection, visibility, 0, 0);
  	if ((int)contador==-1) printf("Erro de alocacao!\n");
  	(*contador)=0;
  	
  	int *k;
  	k = (int*) mmap(NULL, sizeof(int)*100, protection, visibility, 0, 0);
  	if ((int)k==-1) printf("Erro de alocacao!\n");
  	(*k)=0; 
	
	do {
		c = getchar();
		buffer[i] = c;
		i++;
	}
	while (c != '\n');
	//printf("%d\n", i);
		
	char numero[MAX];
	limpabuffer(numero);
	int j = 0;
	
	pid_t f1;
	pid_t f2, f3, f4;
	
	f1 = fork();
	
	if (f1 == 0) {
		signal(SIGQUIT, sigquit);
		while (1) {	
			//printf("to aqui e k e %d\n", ((*k)));
		while (buffer[(*k)] != '\0' && buffer[(*k)] != '\n') {
			do {
				numero[j] = buffer[(*k)];
				(*k)++;	
				j++;	
			}
			while (buffer[(*k)] != ' ' && buffer[(*k)] != '\n');
			//printf ("numero em 1 %s e k = %d\n", numero, (*k));
			if (eprimo(numero)) {
				(*contador)++;
			}
			limpabuffer(numero);
			j = 0;
			(*k)++;
	}
			sleep(1);
	}
	exit(EXIT_SUCCESS);
}

	f2 = fork();
		
		if (f2 == 0) {
			signal(SIGQUIT, sigquit);
			
			while (1) {	
			while (buffer[(*k)] != '\0' && buffer[(*k)] != '\n') {
				do {
					numero[j] = buffer[(*k)];
					(*k)++;	
					j++;	
				}
				while (buffer[(*k)] != ' ' && buffer[(*k)] != '\n');
				//printf ("numero em 2 %s e k = %d\n", numero, (*k));
				if (eprimo(numero)) {
					(*contador)++;
				}
				limpabuffer(numero);
				j = 0;
				(*k) = (*k) + 1;
				
		}
			sleep(1);
		
		}
		exit(EXIT_SUCCESS);
	}

	f3 = fork();
	
	if (f3 == 0) {
		signal(SIGQUIT, sigquit);
		
		while (1) {	
		while (buffer[(*k)] != '\0' && buffer[(*k)] != '\n') {
			do {
				numero[j] = buffer[(*k)];
				(*k)++;	
				j++;	
			}
			while (buffer[(*k)] != ' ' && buffer[(*k)] != '\n');
			//printf ("numero em 3 %s e k = %d\n", numero, (*k));
			if (eprimo(numero)) {
				(*contador)++;
			}
			limpabuffer(numero);
			j = 0;
			(*k) = (*k) + 1;
			
	}
			sleep(1);
		
	}
	exit(EXIT_SUCCESS);
}

	f4 = fork();
	
	if (f4 == 0) {
		signal(SIGQUIT, sigquit);
		
		while (1) {	
		while (buffer[(*k)] != '\0' && buffer[(*k)] != '\n') {
			do {
				numero[j] = buffer[(*k)];
				(*k)++;	
				j++;	
			}
			while (buffer[(*k)] != ' ' && buffer[(*k)] != '\n');
			//printf ("numero em 4 %s e k = %d\n", numero, (*k));
			if (eprimo(numero)) {
				(*contador)++;
			}
			limpabuffer(numero);
			j = 0;
			(*k) = (*k) + 1;	
	}
			sleep(1);	
	}
	exit(EXIT_SUCCESS);
}	
	do {
		sleep(1);
	}
	while ((*k) < i);
	if ((*k) > i) {
		kill(f1, SIGQUIT);
		kill(f2, SIGQUIT);
		kill(f3, SIGQUIT);
		kill(f4, SIGQUIT);
	}

	printf("%d\n", (*contador));
	
	return 0;

}
