#include<stdio.h>
#include<stdlib.h>

void decsort();

typedef struct jobs {
	int profit;
	int deadline;
	int id;
}jobs;

typedef struct resultarr {
	int space;
	int id;
}result;

jobs job[5];
result res[3]; /*ASSUMING HIGHEST DEADLINE TO BE 3*/



int main() {
	int i;
	printf("Enter job in order: profit , deadline , id(character)\n");
	for(i=0;i<5;i++) {
		printf("Job %d\n",i+1);
		scanf("%d%d%d",&job[i].profit,&job[i].deadline,&job[i].id);
	}

// for(int k=0;k<5;k++)
//     printf("%d ",job[k].profit);

printf("%d",job[4].profit);

// for(int k=0;k<5;k++)
//     printf("%d ",job[k].profit);

//Jobs are sorted in decreasing order
	decsort();

// for(int k=0;k<5;k++)
//     printf("%d ",job[k].profit);

	/*initializing results array to 0*/
	for(i=0;i<3;i++) {
		res[i].space=0;
	}

int p;
p=job[0].deadline-1;
res[p].id=job[0].id;
res[p].space=1;

for(i=1;i<5;i++) {
	p=job[i].deadline-1;
	if(res[p].space==0) {
		res[p].id=job[i].id;
		res[p].space=1;
	}
	else {
		while(--p>=0) {
			if(res[p].space==0) {
			res[p].id=job[i].id;
			res[p].space=1;
	}
		}
	}
}


// printf("\nJob sequencing finished:\n");
// for(i=0;i<3;i++) {
// 	printf("%d\t --> \t",res[i].id);
// }

return 0;
}

void decsort() {

int i,j;
jobs temp;

for(i = 0; i < 5; i++)
{
  for(j = i + 1; j < 5; j++)
  {
    if(job[i].profit < job[j].profit)
    {
      /* Exchange two elements */
      job[i]=temp;
      job[i]=job[j];
      job[j]=temp;
    }
  }
}
}
