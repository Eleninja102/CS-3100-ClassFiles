#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	int p[2];
	int id = pipe(p);
	
	if(id < 0){
	printf("\n Pipe creation error");
	return -1;
	}
	
	int pid = fork();
	
	if(pid == 0){
		int x;
		printf("Enter the value of x: ");
		scanf("%d", &x);
		
		close(p[0]);
		write(p[1], &x, sizeof(int));
		close(p[1]);
		
		
		
	}else {
		int y;
		read(p[0], &y, sizeof(int));
		
		printf("\n I am PARENT ... I read the data from the child %d", y);
		
		close(p[0]);
	}
	printf("\n");
	
}