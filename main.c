#include "header.h"

int main()
{
	int  count, i, j, s;
	char buf[100],c,ch,ch1;
	char filename_t[100];
	FILE* fb, * ft;
	PETS** ptr;


	setlocale(LC_ALL, "Ukr");
    system("chcp 1251");
    puts("\t\t\t\t\t\t ОБЛІК ПАЦІЕНТІВ ВЕТЕРЕНАРНОЇ ЛІКАРНІ \n\n Для його заповнення введіть ");

	if ((fb = fopen("d:\\course_b.dat", "wb")) == NULL)
	{
		puts("Error open file");
		return 0;
	}
	count = Write_To_File(fb);
	system("cls");
	printf("\n Кількість усіх пацієнтів %d:\n", count);

    fclose(fb);

	ptr = Read_From_File(fb, count);

	menu();

	while(1)
	{
		c = _getche();
		switch (c)
	  {
			case '1':
				system("cls");
	  puts(" Для виведення на екран натисніть 1 | Для створення текстового файлу натисніть 2?");
	   ch = _getche();

	   switch (ch)
	   {
	 case '1':PRINT(ptr, count);
	 break;

	 case '2':
		puts(" Введіть шлях для створеного файлу ");
		gets(filename_t);

	    PRINT_to_FILE(ptr, count,filename_t, ft);

	    break;
	    default:puts(" Ви ввели неправильну цифру");
	    }
		menu();
		break;

    case '2':
    	system("cls");
    SORT_species(ptr, count);
   	puts("\n Визначити чисельність пацієнтів \n за видом тварин-1 \n за віком-2 \n");
	ch = _getche();


	switch (ch)
	{

	 case '1':
	 i=0;
	  while(i<count)
	   {
	   j=i;
	   while ((j<count)&&(strcmp(ptr[i]->species,ptr[j]->species)==0))
	   j++;
	   printf("\n Вид тварини: %s ; Кількість: %d \n\n",ptr[i]->species,j-i);
	   i=j;
	   }
	   	break;

	case '2':
	i=0;
	while(i<count)
	{
	   j=i;
	   while ((j<count)&&(strcmp(ptr[i]->age,ptr[j]->age)==0))
	   j++;
	   printf("\n Вік: %s ; Кількість: %d \n\n",ptr[i]->age,j-i);
	   i=j;
	}		break;


	default:puts(" Ви ввели неправильну цифру");}

	menu();
	break;


	case '3':
		system("cls");
	SORT_species(ptr, count);


	for (i = 0; i < count; i++) {
    printf("%-15s  %10s  %5s\n", "Name", "Number", "Count");
}


	puts("\n Для створення довідника за видом тварини натисніть 1 | Для створення довідника за віком тварини натисніть 2");
	ch = _getche();


	switch (ch)
	{
	 case '1':
		puts("\n Введіть вид \n");
	    gets(buf);
		puts(" Введіть шлях для створеного файлу ");
		gets(filename_t);
		DIRECTOTY_to_FILE( ptr, count,ch, buf, ft,filename_t);

	break;

		case '2':
		puts("\n Введіть вік \n");
	    gets(buf);
	    puts(" Введіть шлях для створеного файлу ");
		gets(filename_t);
		DIRECTOTY_to_FILE( ptr, count,ch, buf,  ft,filename_t );


    break;
    default:puts(" Ви ввели неправильну цифру");
	}

    menu();
	break;

	case '4':
	system("cls");
		if ((fb = fopen("d:\\course_b.dat", "ab")) == NULL)
		{
		puts("Error open file");
		return 0;
	    }
	count =count+ Write_To_File(fb);
	system("cls");
	printf("\n Кількість усіх пацієнтів %d:\n", count);

    fclose(fb);

	ptr = Read_From_File(fb, count);

	menu();
	break;

	case '5':
	system("cls");

	for (i = 0; i < count; i++)
        printf("\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age, ptr[i]->guide);

	printf(" Для видалення пацієнгта введіть кличку: ");
	gets(buf);
	count=Delete(ptr,count,buf,fb);

	ptr = Read_From_File(fb, count);

	menu();
	break;

		case '6':
		system("cls");

	puts("\n\n Пошук пацієнтів \n за Кличкою-1 \n за фото-2 \n за видом-3 \n за посиланням на текстовий документ-4 \n за віком-5 \n:\n");
    ch = _getche();
    printf(" Введіть пошукові дані\n");

     switch (ch)
	 {
      case '1':
	 	gets(buf);
	 	SEARCH_CHAR(ptr, count, ch,buf);
	  break;

	case '2':
		gets(buf);
		SEARCH_CHAR(ptr, count, ch,buf);
	 break;

	case '3':
		gets(buf);
		SEARCH_CHAR(ptr, count, ch,buf);
	break;

	case '4':
		gets(buf);
	    SEARCH_CHAR(ptr, count, ch,buf);
	break;

	case '5':
        gets(buf);
	    SEARCH_CHAR(ptr, count, ch,buf);
	break;


	default:puts(" Ви ввели неправильну цифру");
	}

	menu();
	break;

	case '7':
	FREE(ptr, count);
	return  0;

	default:puts(" Ви ввели неправильну цифру");
	}
	}
}
