#include "struct.h"

int Write_To_File(FILE* file);
PETS** Read_From_File(FILE* fb, int count);
void PRINT(PETS** ptr, int count);
int PRINT_to_FILE(PETS** ptr, int count, char* filename_t, FILE* ft );
int DIRECTOTY_to_FILE(PETS** ptr, int count,char ch, char *buf, FILE* ft, char *filename_t);
int Delete(PETS** ptr, int count, char *buf, FILE* fb );
void SEARCH_CHAR(PETS** ptr, int count,char ch, char *buf);
void SEARCH_INT(PETS** ptr, int count,int ch, int search);
void SORT_species(PETS** ptr, int count) ;
void FREE(PETS** ptr, int count);
void menu(void);
