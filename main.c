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
    puts("\t\t\t\t\t\t ��˲� ��ֲ��Ҳ� ����������ί ˲���Ͳ \n\n ��� ���� ���������� ������ ");

	if ((fb = fopen("d:\\course_b.dat", "wb")) == NULL)
	{
		puts("Error open file");
		return 0;
	}
	count = Write_To_File(fb);
	system("cls");
	printf("\n ʳ������ ��� �������� %d:\n", count);

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
	  puts(" ��� ��������� �� ����� �������� 1 | ��� ��������� ���������� ����� �������� 2?");
	   ch = _getche();

	   switch (ch)
	   {
	 case '1':PRINT(ptr, count);
	 break;

	 case '2':
		puts(" ������ ���� ��� ���������� ����� ");
		gets(filename_t);

	    PRINT_to_FILE(ptr, count,filename_t, ft);

	    break;
	    default:puts(" �� ����� ����������� �����");
	    }
		menu();
		break;

    case '2':
    	system("cls");
    SORT_species(ptr, count);
   	puts("\n ��������� ���������� �������� \n �� ����� ������-1 \n �� ����-2 \n");
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
	   printf("\n ��� �������: %s ; ʳ������: %d \n\n",ptr[i]->species,j-i);
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
	   printf("\n ³�: %s ; ʳ������: %d \n\n",ptr[i]->age,j-i);
	   i=j;
	}		break;


	default:puts(" �� ����� ����������� �����");}

	menu();
	break;


	case '3':
		system("cls");
	SORT_species(ptr, count);


	for (i = 0; i < count; i++) {
    printf("%-15s  %10s  %5s\n", "Name", "Number", "Count");
}


	puts("\n ��� ��������� �������� �� ����� ������� �������� 1 | ��� ��������� �������� �� ���� ������� �������� 2");
	ch = _getche();


	switch (ch)
	{
	 case '1':
		puts("\n ������ ��� \n");
	    gets(buf);
		puts(" ������ ���� ��� ���������� ����� ");
		gets(filename_t);
		DIRECTOTY_to_FILE( ptr, count,ch, buf, ft,filename_t);

	break;

		case '2':
		puts("\n ������ �� \n");
	    gets(buf);
	    puts(" ������ ���� ��� ���������� ����� ");
		gets(filename_t);
		DIRECTOTY_to_FILE( ptr, count,ch, buf,  ft,filename_t );


    break;
    default:puts(" �� ����� ����������� �����");
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
	printf("\n ʳ������ ��� �������� %d:\n", count);

    fclose(fb);

	ptr = Read_From_File(fb, count);

	menu();
	break;

	case '5':
	system("cls");

	for (i = 0; i < count; i++)
        printf("\n %-15s\t%-10s\t%-5s\t%-5s\t%-s\n", ptr[i]->name, ptr[i]->foto, ptr[i]->species, ptr[i]->age, ptr[i]->guide);

	printf(" ��� ��������� ��������� ������ ������: ");
	gets(buf);
	count=Delete(ptr,count,buf,fb);

	ptr = Read_From_File(fb, count);

	menu();
	break;

		case '6':
		system("cls");

	puts("\n\n ����� �������� \n �� �������-1 \n �� ����-2 \n �� �����-3 \n �� ���������� �� ��������� ��������-4 \n �� ����-5 \n:\n");
    ch = _getche();
    printf(" ������ ������� ���\n");

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


	default:puts(" �� ����� ����������� �����");
	}

	menu();
	break;

	case '7':
	FREE(ptr, count);
	return  0;

	default:puts(" �� ����� ����������� �����");
	}
	}
}
