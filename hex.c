#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hex.h"
void hex(char* line1, char* line2, char sim){
	int max=0;
	int min=0;
	int ten3=0;
	if (strlen(line1) > strlen(line2)){
		max=strlen(line1);
		min=strlen(line2);
	}
	else{
		max=strlen(line2);
		min=strlen(line1);
	}
	char helpLine[max];
	const int size=128;
	char* line3=calloc(size,sizeof(char));
	char* line3_1=calloc(size,sizeof(char));
	char* line3_2=calloc(size,sizeof(char));
	for (int i=0; i<=max-min; i++){
			*(helpLine+i)='0';
	}	
	if (strlen(line1)>=strlen(line2)){
		if (sim == '&'){
			for (int i=max-min; i<max;i++){
				*(helpLine+i)=*(line2+(i-(max-min)));
			}
			for (int i=0; i<max; i++){
				if ((*(line1+i) == '1') && (*(helpLine+i) == '1')){
					*(line3+i)='1';
				}
				else{
				*(line3+i)='0';
				}
			}
			int count=0;
			for (int i=0; i<max; i++){
				if (*(line3+i) == '0'){
					count++;
				}
				if (*(line3+i) == '1'){
					break;
				}
			}
			int index=0;
			for (int i=count; i<max; i++){
				*(line3_1+index)=*(line3+i);
				index++;
			}
			int ten3=0;
			for (int i=0; i<max-count;i++){
				if (*(line3_1+i) == '1'){
			    	ten3+=pow(2,max-count-i-1);
				}
			}
			index=0;
			int ten4=ten3;
			while (ten4>0){
				if (ten4%16 == 0){
					*(line3_1+index)='0';
				}
				else{
					if (ten4%16 > 9){
						sprintf(&*(line3_1+index), "%c", ten4%16+87);
					}
					else{
						sprintf(&*(line3_1+index), "%d", ten4%16);
					}
				}
				index++;
	     		ten4=ten4/16;
			}
			for (int i=0; i<strlen(line3_1); i++){
				*(line3_2+i)=*(line3_1+strlen(line3_1)-i-1);
			}
			if (ten3 == 0){
				printf("%s (%i)","0",ten3);
			}
			else{
				printf("0x%s (%i)",line3_2,ten3);
			}
		}
		if (sim == '|'){
			for (int i=max-min; i<max;i++){
				*(helpLine+i)=*(line2+(i-(max-min)));
			}
			for (int i=0; i<max; i++){
				if ((*(line1+i) == '0') && (*(helpLine+i) == '0')){
					*(line3+i)='0';
				}
				else{
				*(line3+i)='1';
				}
			}
			int count=0;
			for (int i=0; i<max; i++){
				if (*(line3+i) == '0'){
					count++;
				}
				if (*(line3+i) == '1'){
					break;
				}
			}
			int index=0;
			for (int i=count; i<max; i++){
				*(line3_1+index)=*(line3+i);
				index++;
			}
			int ten3=0;
			for (int i=0; i<max-count;i++){
				if (*(line3_1+i) == '1'){
			    	ten3+=pow(2,max-count-i-1);
				}
			}
			index=0;
			int ten4=ten3;
			while (ten4>0){
				if (ten4%16 == 0){
					*(line3_1+index)='0';
				}
				else{
					if (ten4%16 > 9){
						sprintf(&*(line3_1+index), "%c", ten4%16+87);
					}
					else{
						sprintf(&*(line3_1+index), "%d", ten4%16);
					}
				}
				index++;
	     		ten4=ten4/16;
			}
			for (int i=0; i<strlen(line3_1); i++){
				*(line3_2+i)=*(line3_1+strlen(line3_1)-i-1);
			}
			if (ten3 == 0){
				printf("%s (%i)","0",ten3);
			}
			else{
				printf("0x%s (%i)",line3_2,ten3);
			}
		}
		if (sim == '^'){
			for (int i=max-min; i<max;i++){
				*(helpLine+i)=*(line2+(i-(max-min)));
			}
			for (int i=0; i<max; i++){
				if (*(line1+i) == (*(helpLine+i))){
					*(line3+i)='0';
				}
				else{
				*(line3+i)='1';
				}
			}
			int count=0;
			for (int i=0; i<max; i++){
				if (*(line3+i) == '0'){
					count++;
				}
				if (*(line3+i) == '1'){
					break;
				}
			}
			int index=0;
			for (int i=count; i<max; i++){
				*(line3_1+index)=*(line3+i);
				index++;
			}
			int ten3=0;
			for (int i=0; i<max-count;i++){
				if (*(line3_1+i) == '1'){
			    	ten3+=pow(2,max-count-i-1);
				}
			}
			index=0;
			int ten4=ten3;
			while (ten4>0){
				if (ten4%16 == 0){
					*(line3_1+index)='0';
				}
				else{
					if (ten4%16 > 9){
						sprintf(&*(line3_1+index), "%c", ten4%16+87);
					}
					else{
						sprintf(&*(line3_1+index), "%d", ten4%16);
					}
				}
				index++;
	     		ten4=ten4/16;
			}
			for (int i=0; i<strlen(line3_1); i++){
				*(line3_2+i)=*(line3_1+strlen(line3_1)-i-1);
			}
			if (ten3 == 0){
				printf("%s (%i)","0",ten3);
			}
			else{
				printf("0x%s (%i)",line3_2,ten3);
			}
		}
	}
	else{
		if (sim == '&'){
			for (int i=max-min; i<max;i++){
				*(helpLine+i)=*(line1+(i-(max-min)));
			}
			for (int i=0; i<max; i++){
				if ((*(line2+i) == '1') && (*(helpLine+i) == '1')){
					*(line3+i)='1';
				}
				else{
				*(line3+i)='0';
				}
			}
			int count=0;
			for (int i=0; i<max; i++){
				if (*(line3+i) == '0'){
					count++;
				}
				if (*(line3+i) == '1'){
					break;
				}
			}
			int index=0;
			for (int i=count; i<max; i++){
				*(line3_1+index)=*(line3+i);
				index++;
			}
			int ten3=0;
			for (int i=0; i<max-count;i++){
				if (*(line3_1+i) == '1'){
			    	ten3+=pow(2,max-count-i-1);
				}
			}
			index=0;
			int ten4=ten3;
			while (ten4>0){
				if (ten4%16 == 0){
					*(line3_1+index)='0';
				}
				else{
					if (ten4%16 > 9){
						sprintf(&*(line3_1+index), "%c", ten4%16+87);
					}
					else{
						sprintf(&*(line3_1+index), "%d", ten4%16);
					}
				}
				index++;
	     		ten4=ten4/16;
			}
			for (int i=0; i<strlen(line3_1); i++){
				*(line3_2+i)=*(line3_1+strlen(line3_1)-i-1);
			}
			if (ten3 == 0){
				printf("%s (%i)","0",ten3);
			}
			else{
				printf("0x%s (%i)",line3_2,ten3);
			}
	   	}
		if (sim == '|'){
			for (int i=max-min; i<max;i++){
				*(helpLine+i)=*(line1+(i-(max-min)));
			}
			for (int i=0; i<max; i++){
				if ((*(line2+i) == '0') && (*(helpLine+i) == '0')){
					*(line3+i)='0';
				}
				else{
				*(line3+i)='1';
				}
			}
			int count=0;
			for (int i=0; i<max; i++){
				if (*(line3+i) == '0'){
					count++;
				}
				if (*(line3+i) == '1'){
					break;
				}
			}
			int index=0;
			for (int i=count; i<max; i++){
				*(line3_1+index)=*(line3+i);
				index++;
			}
			int ten3=0;
			for (int i=0; i<max-count;i++){
				if (*(line3_1+i) == '1'){
			    	ten3+=pow(2,max-count-i-1);
				}
			}
			index=0;
			int ten4=ten3;
			while (ten4>0){
				if (ten4%16 == 0){
					*(line3_1+index)='0';
				}
				else{
					if (ten4%16 > 9){
						sprintf(&*(line3_1+index), "%c", ten4%16+87);
					}
					else{
						sprintf(&*(line3_1+index), "%d", ten4%16);
					}
				}
				index++;
	     		ten4=ten4/16;
			}
			for (int i=0; i<strlen(line3_1); i++){
				*(line3_2+i)=*(line3_1+strlen(line3_1)-i-1);
			}
			if (ten3 == 0){
				printf("%s (%i)","0",ten3);
			}
			else{
				printf("0x%s (%i)",line3_2,ten3);
			}
		}
		if (sim == '^'){
			for (int i=max-min; i<max;i++){
				*(helpLine+i)=*(line1+(i-(max-min)));
			}
			for (int i=0; i<max; i++){
				if (*(line2+i) == (*(helpLine+i))){
					*(line3+i)='0';
				}
				else{
				*(line3+i)='1';
				}
			}
			int count=0;
			for (int i=0; i<max; i++){
				if (*(line3+i) == '0'){
					count++;
				}
				if (*(line3+i) == '1'){
					break;
				}
			}
			int index=0;
			for (int i=count; i<max; i++){
				*(line3_1+index)=*(line3+i);
				index++;
			}
			int ten3=0;
			for (int i=0; i<max-count;i++){
				if (*(line3_1+i) == '1'){
			    	ten3+=pow(2,max-count-i-1);
				}
			}
			index=0;
			int ten4=ten3;
			while (ten4>0){
				if (ten4%16 == 0){
					*(line3_1+index)='0';
				}
				else{
					if (ten4%16 > 9){
						sprintf(&*(line3_1+index), "%c", ten4%16+87);
					}
					else{
						sprintf(&*(line3_1+index), "%d", ten4%16);
					}
				}
				index++;
	     		ten4=ten4/16;
			}
			for (int i=0; i<strlen(line3_1); i++){
				*(line3_2+i)=*(line3_1+strlen(line3_1)-i-1);
			}
			if (ten3 == 0){
				printf("%s (%i)","0",ten3);
			}
			else{
				printf("0x%s (%i)",line3_2,ten3);
			}
		}
	}	
	if (sim == '+'){
		int ten4=0;
		for (int i=0; i<strlen(line1);i++){
			if (*(line1+i) == '1'){
			    ten3+=pow(2,strlen(line1)-i-1);
			}
		}
		for (int i=0; i<strlen(line2);i++){
			if (*(line2+i) == '1'){
			    ten4+=pow(2,strlen(line2)-i-1);
			}
		}
		ten3=ten3+ten4;
		ten4=ten3;
		int index=0;
		while (ten4>0){
				if (ten4%16 == 0){
					*(line3+index)='0';
				}
				else{
					if (ten4%16 > 9){
						sprintf(&*(line3+index), "%c", ten4%16+87);
					}
					else{
						sprintf(&*(line3+index), "%d", ten4%16);
					}
				}
				index++;
	     		ten4=ten4/16;
			}
		for (int i=0; i<strlen(line3); i++){
			*(line3_1+i)=*(line3+strlen(line3)-i-1);
		}
		printf("0x%s (%i)", line3_1,ten3);
	}
	if (sim == '-'){
		int ten4=0;
		for (int i=0; i<strlen(line1);i++){
			if (*(line1+i) == '1'){
			    ten3+=pow(2,strlen(line1)-i-1);
			}
		}
		for (int i=0; i<strlen(line2);i++){
			if (*(line2+i) == '1'){
			    ten4+=pow(2,strlen(line2)-i-1);
			}
		}
		ten3=ten3-ten4;
		ten4=ten3;
		int index=0;
		if (ten3<0){
			ten4=ten4*(-1);
		}
		while (ten4>0){
				if (ten4%16 == 0){
					*(line3+index)='0';
				}
				else{
					if (ten4%16 > 9){
						sprintf(&*(line3+index), "%c", ten4%16+87);
					}
					else{
						sprintf(&*(line3+index), "%d", ten4%16);
					}
				}
				index++;
	     		ten4=ten4/16;
			}
		for (int i=0; i<strlen(line3); i++){
			*(line3_1+i)=*(line3+strlen(line3)-i-1);
		}
		if (ten3<0){
			printf("-0x%s (%i)", line3_1,ten3);
		}
		else{
			printf("0x%s (%i)", line3_1,ten3);
		}
	}
	if (sim == '*'){
		int ten4=0;
		for (int i=0; i<strlen(line1);i++){
			if (*(line1+i) == '1'){
			    ten3+=pow(2,strlen(line1)-i-1);
			}
		}
		for (int i=0; i<strlen(line2);i++){
			if (*(line2+i) == '1'){
			    ten4+=pow(2,strlen(line2)-i-1);
			}
		}
		ten3=ten3*ten4;
		ten4=ten3;
		int index=0;
		while (ten4>0){
				if (ten4%16 == 0){
					*(line3+index)='0';
				}
				else{
					if (ten4%16 > 9){
						sprintf(&*(line3+index), "%c", ten4%16+87);
					}
					else{
						sprintf(&*(line3+index), "%d", ten4%16);
					}
				}
				index++;
	     		ten4=ten4/16;
			}
		for (int i=0; i<strlen(line3); i++){
			*(line3_1+i)=*(line3+strlen(line3)-i-1);
		}
		printf("0x%s (%i)", line3_1,ten3);
	}
	if (sim == '%'){
		int ten4=0;
		for (int i=0; i<strlen(line1);i++){
			if (*(line1+i) == '1'){
			    ten3+=pow(2,strlen(line1)-i-1);
			}
		}
		for (int i=0; i<strlen(line2);i++){
			if (*(line2+i) == '1'){
			    ten4+=pow(2,strlen(line2)-i-1);
			}
		}
		if (ten3<ten4){
			ten3=0;
			printf("%s (%i)","0",ten3);
		}
		else{
			ten3=ten3%ten4;
			ten4=ten3;
			int index=0;
			while (ten4>0){
				if (ten4%16 == 0){
					*(line3+index)='0';
				}
				else{
					if (ten4%16 > 9){
						sprintf(&*(line3+index), "%c", ten4%16+87);
					}
					else{
						sprintf(&*(line3+index), "%d", ten4%16);
					}
				}
				index++;
	     		ten4=ten4/16;
			}
			for (int i=0; i<strlen(line3); i++){
				*(line3_1+i)=*(line3+strlen(line3)-i-1);
			}
			printf("0x%s (%i)", line3_1,ten3);
		}
	}
	free(line1);
	line1=NULL;
	free(line2);
	line2=NULL;
	free(line3);
	line3=NULL;
	free(line3_1);
	line3_1=NULL;
	free(line3_2);
	line3_2=NULL;
}
void hex_1(char* line1){
	const int size=128;
	char* line3=calloc(size,sizeof(char));
	char* line3_1=calloc(size,sizeof(char));
	int ten3=0;
	for (int i=0; i<strlen(line1);i++){
		if (*(line1+i) == '1'){
			ten3+=pow(2,strlen(line1)-i-1);
		}
	}
	ten3+=1;
	int ten4=ten3;
	int index=0;
	while (ten4>0){
		if (ten4%16 == 0){
			*(line3+index)='0';
		}
		else{
			if (ten4%16 > 9){
				sprintf(&*(line3+index), "%c", ten4%16+87);
			}
			else{
				sprintf(&*(line3+index), "%d", ten4%16);
			}
		}
		index++;
     	ten4=ten4/16;
	}
	for (int i=0; i<strlen(line3); i++){
		*(line3_1+i)=*(line3+strlen(line3)-i-1);
	}
	printf("-0x%s (-%i)",line3_1,ten3);
	free(line1);
	line1=NULL;
	free(line3);
	line3=NULL;
	free(line3_1);
	line3_1=NULL;
}