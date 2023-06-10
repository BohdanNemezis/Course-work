#include "struct.h"
int Write_To_File(FILE* file)//ф-ція запису у файл
{


	int ch, count = 0;
	PETS m;
	while (1)
	{   printf(" Кличка: "); gets(m.name);
		rewind(stdin);
		printf(" Фото: "); gets(m.foto);
		printf(" Вид тварини: "); scanf("%s",m.species);
		rewind(stdin);
		printf(" Вік: "); gets(m.age);
		rewind(stdin);
		printf(" Файл з примітками: "); scanf("%s",m.guide);
		rewind(stdin);

		fwrite(&m, sizeof(PETS), 1, file);
		count++;
		puts(" Продовжити так-1/ ні-2? ");
			ch = _getche();
		if (ch == '2') break;
	}

	return count;
}

PETS** Read_From_File(FILE* fb, int count)//зчитування
{
	PETS** ptr = (PETS**)malloc(count*sizeof(PETS*));
	int i = 0;
	if ((fb = fopen("d:\\course_b.dat", "rb")) == NULL)
	{
		puts("Error open file");
		return 0;
	}
	while (i < count)

	{
		ptr[i] = (PETS*)malloc(sizeof(PETS));
		fread(ptr[i], sizeof(PETS), 1, fb);

		i++;
	}
    fclose(fb);
	return ptr;
}


void PRINT(PETS** ptr, int count)//ф-ція виводу даних
{
    int i;
    for (i = 0; i < count; i++)
        printf("\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age, ptr[i]->guide);
}


int PRINT_to_FILE(PETS** ptr, int count, char* filename_t, FILE* ft)//ф-ція запису до файлу
{
    int i;
    if ((ft = fopen(filename_t, "wt")) == NULL) {
        puts("Error open file");
        return 0;
    }
    for (i = 0; i < count; i++)
        fprintf(ft, "\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age, ptr[i]->guide);
    printf(" Запис відбувся успішно");
    fclose(ft);
    return count;
}


int DIRECTOTY_to_FILE(PETS** ptr, int count,char ch, char *buf, FILE* ft, char *filename_t)//ф-ція запису до файлу за певним полем (довідник)
{

    int i,k=0;







	if ((ft = fopen(filename_t, "wt")) == NULL)
	{
		puts("Error open file");
		return 0;
	}
	  if(ch=='1')
        {for (i = 0; i < count; i++)
	     if(strcmp(ptr[i]->species,buf)==0)
	       { k++;
	        fprintf(ft,"\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age, ptr[i]->guide);
	       {
	     }
		 }
		if(k==0){
		printf(" Не існує такого виду тварини");
		fclose(ft);
		remove(filename_t);
	   }
		else printf(" Запис відбувся успішно");
		}

		if(ch=='2')
		{
		for (i = 0; i < count; i++)
	     {
	     if(strcmp(ptr[i]->age,buf)==0)
	      { k++;
	     fprintf(ft,"\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age, ptr[i]->guide);
	      }
		 }
		if(k==0)
		{printf(" Не існує такого текстового документу");
		fclose(ft);
		remove(filename_t);
	   }
		else printf(" Запис відбувся успішно");}
		fclose(ft);
		return count;
}


int Delete(PETS** ptr, int count, char *buf, FILE* fb )//ф-ція видалення пацієнта
{
	int i,k=0;
	if ((fb = fopen("d:\\course_b.dat", "wb")) == NULL)
	{
		puts("Error open file");
		return 0;
	}
        for (i = 0; i < count; i++)
	    {
	     if(strcmp(ptr[i]->name,buf)!=0)
	     { k++;
	      fwrite(ptr[i], sizeof(PETS
), 1, fb);
		 }
		}

		if(k==count)printf(" Не існує такого пацієнта");
		else printf(" Видалення успішне");
		fclose(fb);
		return k;
}


void SEARCH_CHAR(PETS** ptr, int count,char ch, char *buf)// ф-ція пошуку за символьним рядком
{
		int i,k=0;
	    if(ch=='1')
        {
		  for (i = 0; i < count; i++)
	      {
	        if(strcmp(ptr[i]->name,buf)==0)
	          { k++;
	     printf("\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age,ptr[i]->guide);
	          }
		  }
		if(k==0)printf("Пошук не дав результатів");
		}
		if(ch=='2')
        {
		for (i = 0; i < count; i++)
	     {
	     if(strcmp(ptr[i]->foto,buf)==0)
	      { k++;
	     printf("\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age,ptr[i]->guide);
	      }
		 }
	     if(k==0)printf("Пошук не дав результатів");
		}
		if(ch=='3')
        {
		  for (i = 0; i < count; i++)
	       {
	         if(strcmp(ptr[i]->species,buf)==0)
	             {  k++;
	            printf("\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age,ptr[i]->guide);
	             }
		    }
		   if(k==0)printf("Пошук не дав результатів");
		}
		if(ch=='4')
            {
		     for (i = 0; i < count; i++)
	           {
	             if(strcmp(ptr[i]->guide,buf)==0)
	                { k++;
	                printf("\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age,ptr[i]->guide);
	                 }
				}
		         if(k==0)printf("Пошук не дав результатів");
		    }
        if(ch=='5')
            {
		     for (i = 0; i < count; i++)
	           {
	             if(strcmp(ptr[i]->age,buf)==0)
	                { k++;
	                printf("\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age,ptr[i]->guide);
	                 }
				}
		         if(k==0)printf("Пошук не дав результатів");
		    }



}


void SEARCH_INT(PETS** ptr, int count,int ch, int search)// ф-ція пошуку за числовими даними
{
	int i,k;
        if(ch=='5')
        {
		  for (i = 0; i < count; i++)
	       {
	        if(ptr[i]->guide==search)
	         {  k++;
	         printf("\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age,ptr[i]->guide);
	         }
			}
		if(k==0)printf("Пошук не дав результатів");}
			if(ch=='6')
            {
		     for (i = 0; i < count; i++)
	        {
	          if(ptr[i]->entry==search)
	          { k++;
	            printf("\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age,ptr[i]->guide);
	          }
			}

		if(k==0)printf("Пошук не дав результатів");
		    }
		if(ch=='7')
        {for (i = 0; i < count; i++)
	    {
	     if(ptr[i]->exit==search)
	     { k++;
	     printf("\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age,ptr[i]->guide);
	     }
	    }
		if(k==0)printf("Пошук не дав результатів");
		}
	}


void SORT_species(PETS** ptr, int count)//ф-ція сортування за видами та віками тварин
{
    PETS* temp;
      int i,j,s,r;
	  for (i = 0; i < count - 1; i++)
		for (j = i + 1; j < count; j++)
			if (strcmp(ptr[i]->species,ptr[j]->species)>0)
	        {temp=ptr[i];
	         ptr[i]=ptr[j];
	         ptr[j]=temp;
			}
	i=0;
	while(i<count)
	{
	   j=i;
	   while ((j<count)&&(strcmp(ptr[i]->species,ptr[j]->species)==0))
	   j++;

	   for(s=i;s<j-1;s++)
	    for	(r=s+1;r<j;r++)
	      if(strcmp(ptr[s]->age,ptr[r]->age)>0)
	      {temp=ptr[s];
	        ptr[s]=ptr[r];
	        ptr[r]=temp;
		  }

		i=j;
	}
	}


	void FREE(PETS** ptr, int count)//вивільнення пам'яті
{
    int i;
	  for (i = 0; i < count; i++)
		free(ptr[i]);
		ptr[i]=NULL;
	}


	void menu(void) //вивід меню
{
	printf(
		"\n\n"
		"1. Переглянути список.\n"
		"2. Визначити чисельність.\n"
		"3. Створити довідник.\n"
		"4. Доповнити список.\n"
		"5. Видалити список.\n"
		"6. Пошук.\n"
		"7. Вийти.\n\n"
		"\n"
	);
}
