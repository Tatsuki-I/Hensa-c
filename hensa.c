#include<stdio.h>
#include<math.h>
#define N 8
#define M 0.675
int main(void){
	int i=0;
	double a[N], b[N], ave=0, hensa=0, gosa;
	FILE *fp;
	fp=fopen("data.txt","r");
	for(i=0; i<N; i++){
		fscanf(fp, "%lf", &(a[i]) );
	}
	fclose(fp);
	for(i=0; i<N; i++) {
		printf("%f\n", a[i]);
   　　 }

	for(i=0;i<N;i++){
		ave+=a[i];
	}
	ave/=N;

	printf("%f\n", ave);
	for(i=0;i<N;i++){
		b[i]=a[i]-ave;
		b[i]*=b[i];
		hensa+=b[i];
	}
	hensa/=(N-1);
	hensa=sqrt(hensa);
	gosa=hensa*M;

	fp=fopen("resno1.txt", "w");
	fprintf(fp,"最確値=%f\n標準偏差=%f\n確率誤差=%f\n",ave,hensa,gosa);
	fclose(fp);
	return 0;
}
