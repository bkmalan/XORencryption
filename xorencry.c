#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char* cipher(char* msg,char* key);
char* decipher(char* bk,char* key);

int main()
{
	
	char msg[100],key[100];
	int c;
	printf("0 for Encryption\t1 for Decryption\n");
	scanf("%d",&c);
	if(!c)	{
		printf("Enter message\n");
		scanf("%s",msg);
		printf("Enter key\n");
		scanf("%s",key);
		printf("Encrypted: %s\n",cipher(msg,key));
	}	
	else	{	
		printf("Enter Encrypted message\n");
		scanf("%s",msg);		
		printf("Enter key\n");
		scanf("%s",key);	
		printf("Decrypted: %s\n",decipher(msg,key));
	}	
  return 0;
}	

char* cipher(char* msg,char* key)	{
	
	int n,m,index = 0;
	static char encrypt[400];
	n = strlen(msg);
	m = strlen(key);
	char* cipher = (char*)malloc(n * sizeof(char));
	for(int i = 0; i < n; i++)	{			
		*(cipher + i) = msg[i] ^ key[i % m];
		if(*(cipher + i) < 16)	
	 		index += sprintf(&encrypt[index], "0%x", *(cipher+i));
		else	
  		index += sprintf(&encrypt[index], "%x", *(cipher+i));
	}	
	free(cipher);
	return encrypt;
}

char* decipher(char* bk,char* key)	{
	
	int n,m,j = 0,index = 0;
	n = strlen(bk);	
	m = strlen(key);
	int* x = (int*)malloc(n * sizeof(int));
	int* dec = (int*)malloc((n/2) * sizeof(int));
	char static decrypt[1000];
	for(int i = 0; i < n; i++)	{		
		x[i] = *(bk+i) - '0';
		x[i+1] = *(bk+i+1) - '0';
		if(x[i+1] >= 49)	
			x[i+1] -= 39;
		if(x[i])
			dec[j] = pow(16,x[i]) + x[i+1];
		else
			dec[j] += x[i+1];
		j++;
		i++;
	}
	for(int i = 0; i < n/2; i++)	{			
		dec[i] = dec[i] ^ key[i%m];
 		index += sprintf(&decrypt[index], "%c", *(dec+i));
	}
	free(dec);
	return decrypt;
}





