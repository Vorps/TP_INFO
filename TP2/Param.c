#include "Param.h"
#include <stdio.h>
long hachage(char *key){
	Hash hash;
	for(int i = 0; i < sizeof(long); i++) hash.data[i] = '\0';
	for(int i = 0; key[i] != '\0' && i < sizeof(long); i++) hash.data[i] = key[i];
	return hash.hash;
}

void setParam(char **argv, size_t args_size, ApplyParam applyParam, void * setup){
	for(int j = 1, i =0; j < args_size; j++, i++){
		if(*argv[j] == '-'){
			applyParam(argv[j], argv[j+1], setup);
			if(*(argv[j]+1) != '-') j++;
		}
	}
}