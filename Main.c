#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void menu();
void tambah_data();
void tampil_data();
void edit_data();
void hapus_data();
void cari_data();
void close();

struct DATA {
	char nama[30];
	int umur,id;
	char jk[30];
	float nilai[5];
	int total;
}
tambah,cekk,hapus;

int login(char username[10], char password[10]){
	FILE *p;
	char user[10], pass[10];
	p = fopen("login.txt", "r");

	fscanf(p, "%s @ %s", user, pass);

	if((strcmp(username,user)==0) && (strcmp(password,pass)==0)){
		printf("\nLOGIN BERHASIL!\n");
		system("pause");
		menu();
	}else{
		printf("\nLOGIN GAGAL!\n");
		system("pause");
		fclose(p);
		return 0;
	}
}
int main(){
	char username[10], password[10];
	printf("\n==================SELAMAT DATANG==================");
	printf("\n===DI PORTAL DATA RESPONDEN TEST BAHASA INGGRIS===");
	printf("\n\n<SILAHKAN LOGIN>\n");
	printf("Username: ");
	scanf("%s", username);
	printf("Password: ");
	scanf("%s", password);

	login(username,password);
}

void menu(){
	int pilih;
	menu:
		system("cls");
		printf("=====SELAMAT DATANG=====\n");
		printf("\nMENU:");
		printf("\n1. Tambah Data  ");
		printf("\n2. Tampil Data  ");
		printf("\n3. Cari Data    ");
		printf("\n4. Hapus Data   ");
		printf("\n5. Edit Data    ");	
		printf("\n6. Keluar       ");
		
		printf("\n\nPilihan : ");
		scanf("%d", &pilih);
		switch(pilih){
			case 1:tambah_data();
				break;
			case 2:tampil_data();
				break;
			case 3: cari_data();
				break;	
			case 4:hapus_data();
				break;
			case 5:edit_data();
				break;
			case 6:close();
				break;
			default:printf("\nPilihan Salah !");
				getche();
				goto menu;
		}
}
void tambah_data(){
	FILE *add1,*add2;
	add1 = fopen("data.txt","a");
		system("cls");
		add2 = fopen("data.txt","r");
		while (fscanf (add2,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
		{
			tambah.id++;	
		}
		cekk.id = tambah.id;
		fclose(add2);
		printf("Masukan nama responden : "); fflush(stdin);
		scanf("%[^\n]",tambah.nama);
		printf("Masukan JK responden : "); fflush(stdin);
		scanf("%[^\n]",tambah.jk);
		printf("Masukan umur responden : "); fflush(stdin);
		scanf("%d",&tambah.umur); 
		printf("Nilai Reading\t: ");
		scanf("%f",&tambah.nilai[0]);
		printf("Nilai Speaking\t: ");
		scanf("%f",&tambah.nilai[1]);
		printf("Nilai Writing\t: ");
		scanf("%f",&tambah.nilai[2]);
		printf("Nilai Listening\t: ");
		scanf("%f",&tambah.nilai[3]);
		tambah.nilai[4]=(tambah.nilai[0]+tambah.nilai[1]+tambah.nilai[2]+tambah.nilai[3])/4;
		tambah.total = tambah.nilai[4];
		fprintf(add1,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
		fclose(add2);
	
		printf("\nData Tersimpan!!");
		ulang:
		printf("\nTekan 1 untuk menu dan 2 untuk keluar : ");
		switch(getch()){
    		case '1': menu();
        		break;
        	case '2': close();
        		break;
        	default:printf("\nInput Salah!");
        		getche();
        		goto ulang;
 		}
}
void tampil_data()
{
	int tampil=0;
	FILE *tampildata;
	tampildata = fopen("data.txt","r");
	system ("cls");
	printf("Data Responden Test Bahasa Inggris\n\n");
	printf("+----+-------+-----+-------+-----------+------------+-----------+-------------+-----------+\n");
	printf("|ID  |NAMA   |JK   |UMUR   |Reading    |Speaking    |Writing    |Listening    |Rata-Rata  |  \n");
	printf("+----+-------+-----+-------+-----------+------------+-----------+-------------+-----------+\n");
	
		while (fscanf (tampildata,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
		printf("|%d   |%s   |%s    |%d     |%.2f      |%.2f       |%.2f      |%.2f        |%.2f      |\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
			printf("+----+-------+-----+-------+-----------+------------+-----------+-------------+-----------+\n");
		tampil++;
	}
	printf ("\nJumlah Data Responden : %d",tampil);
	fclose(tampildata);
	
	if(tampil==0)
	{

		system("cls");
		printf ("\nTidak ada Data! \n");
	}
	ulang:
    printf("\n\nTekan 1 untuk menu dan 2 untuk keluar : ");
    switch(getch()){
    	case '1': menu();
        	break;
        case '2': close();
        	break;
        default:printf("\nInput Salah!");
        	getche();
        	goto ulang;
 	}
}
void cari_data()
{
	FILE *search;
	int cek=0;
	system("cls");
	search = fopen("data.txt","r");
	system("cls");
	printf("Input ID Responden : ");
	scanf("%d", &cekk.id);
	while(fscanf (search,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF){
		if(tambah.id==cekk.id){
			cek=1;
			printf("+----+-------+-----+-------+-----------+------------+-----------+-------------+-----------+\n");
			printf("|ID  |NAMA   |JK   |UMUR   |Reading    |Speaking    |Writing    |Listening    |Rata-Rata  |  \n");
			printf("+----+-------+-----+-------+-----------+------------+-----------+-------------+-----------+\n");
			printf("|%d   |%s   |%s    |%d     |%.2f      |%.2f       |%.2f      |%.2f        |%.2f      |\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
			printf("+----+-------+-----+-------+-----------+------------+-----------+-------------+-----------+\n");
		}
	}
	fclose(search);
	if(cek!=1){
		system("cls");
		printf("\nData tidak ditemukan !\a\a\a");
		ulang:
		printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': cari_data();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto ulang;
        }
	}else{
		ulang1:
		printf("\n\n\nTekan 1 untuk ke menu dan 2 untuk keluar :");
        switch(getch()){
        	case '1': menu();
       			break;
       		case '2': close();
       			break;
       		default:printf("\nInput Salah!");
        		getche();
        		goto ulang1;
       	}	
    }	
	
}

void hapus_data()
{
	FILE *lama, *baru;
	int cek=0;
	lama = fopen("data.txt","r");
	baru = fopen("databaru.txt","w");
	system("cls");
	printf("Input No.ID Responden yang akan di hapus : ");
	scanf("%d", &hapus.id);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
		if(tambah.id != hapus.id)
		{
			fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);	
		}
		else{
			cek++;
			printf("\nData Terhapus!");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("data.txt");
	rename("databaru.txt","data.txt");
		if(cek==0){
            printf("\nData tidak ditemukan !\a\a\a");
            ulang:
            printf("\nTekan 1 untuk mencoba lagi, 2 untuk ke menu dan 3 untuk keluar :");
			switch(getch()){
            	case '1': hapus_data();
            		break;
            	case '2': menu();
            		break;
            	case '3': close();
            		break;
            	default:printf("\nInput Salah!");
            		getche();
            		goto ulang;
			}
    }
    else{
    	ulang1:
		printf("\nTekan 1 untuk ke menu dan 2 untuk keluar :");
        switch(getch()){
       		case '1': menu();
       			break;
       		case '2': close();
       			break;
       		default:printf("\nInput Salah!");
        		getche();
        		goto ulang1;
        }
    }
	
}
void edit_data()
{
	int pilih,cek=0;
	FILE *lama,*baru;
	lama = fopen("data.txt","r");
	baru = fopen ("databaru.txt","w");
	system("cls");
	
	printf ("Masukan ID Responden : ");
	scanf ("%d",&cekk.id);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;%f;%f;%f;%f\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.nilai[0],&tambah.nilai[1],&tambah.nilai[2],&tambah.nilai[3],&tambah.nilai[4])!=EOF)
	{
		if(tambah.id == cekk.id)
		{
			cek=1;
			ganti:
				printf("\n\nData yang akan diganti : ");
				printf("\n1. Nama");
				printf("\n2. Jenis Kelamin");
				printf("\n3. Umur");
				printf("\nPilihan : ");
				scanf("%d",&pilih);
				
				if(pilih == 1)
				{
					printf ("\nMasukan Data Nama Baru : ");fflush(stdin);
					scanf ("%[^\n]",cekk.nama);
					strcpy(tambah.nama,cekk.nama);
						fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data Jenis Kelamin L/P : ");fflush(stdin);
					scanf ("%[^\n]",cekk.jk);
					strcpy(tambah.jk,cekk.jk);
						fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Data Umur Baru : ");
					scanf ("%d",&cekk.umur);
					tambah.umur = cekk.umur;
					fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else{
					printf("\n\nInput Salah !");
					getche();
					goto ganti;
				}
		}
		else
		{
			fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;%f;%f\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.nilai[0],tambah.nilai[1],tambah.nilai[2],tambah.nilai[3],tambah.nilai[4]);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("data.txt");
	rename("databaru.txt","data.txt");
	if(cek!=1){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        ulang:
        printf("\nnTekan 1 untuk mencoba lagi, 2 untuk ke menu dan 3 untuk keluar :");
        switch(getch()){
            case '1': edit_data();
            	break;
            case '2': menu();
            	break;
            case '3': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto ulang;
        }
    }
    else{
    	ulang1:
		printf("\n\n\nTekan 1 untuk ke menu dan 2 untuk keluar :");
        switch(getch()){
        	case '1': menu();
        		break;
        	case '2': close();
        		break;
        	default:printf("\nInput Salah !");
        		getche();
        		goto ulang1;
        }
    }
}

	
