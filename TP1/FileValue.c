#include "FileValue.h"
#include<stdio.h>

void writeValue(char *nameFile, Value *values, size_t values_size){
	FILE *file;
	file = fopen(nameFile, "w");
	if(file != NULL){
		for(int i = 0; i < values_size; i++){
			fprintf(file, "%lf\t%lf\n", values[i].x, values[i].y);
		}
		fclose(file);
	} else printf("Error write file");
}

void writeBinaryValue(char *nameFile, Value *values, size_t values_size){
	FILE *file;
	file = fopen(nameFile, "wb");
	if(file != NULL){
		fwrite(values, sizeof(Value), values_size, file);
		fclose(file);
	} else printf("Error write file");
}


void readValue(char *nameFile, Value *values, size_t values_size){
	FILE *file;
	file = fopen(nameFile, "r");
	if(file != NULL){
		for(int i = 0; i < values_size; i++){
			fscanf(file, "%lf\t%lf\n", &(values[i].x), &(values[i].y));
		}
		fclose(file);
	} else printf("Error read file");
}

void readBinaryValue(char *nameFile, Value *values, size_t values_size){
	FILE *file;
	file = fopen(nameFile, "rb");
	if(file != NULL){
		fread(values, sizeof(Value), values_size, file);
		fclose(file);
	} else printf("Error read file");
}