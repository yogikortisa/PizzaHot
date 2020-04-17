#include<stdio.h>
#include<string.h>
#include<windows.h>

main()
{
      /* Declaration */
      int i,j,k,menu,ket,jumlah, total, bayar, kembali;
      float diskon;
      char qty[3];
      char lagi;
      char data[5][3][100] = {{"1","","50000"},{"2","","25000"},
                              {"3","","18000"},{"4","","15000"},
                              {"0","",""}};
                              
      /*---------------------- Program Information -------------------------*/
	  system("color 0A");
	  system("cls");
	  printf("\n\n\n\n\n\n\n\n");
	  printf("\t\t+-----------------------------------------+\n"); Sleep(100);
	  printf("\t\t|\t   PROGRAM KASIR RESTORAN         |\n");      Sleep(100);
	  printf("\t\t+-----------------------------------------+\n"); Sleep(500);
	  printf("\n\n");
	  getch();
	  system("cls");
	  
      /*--------------- Copyright (c) Yogi Kortisa - 2014 ------------------*/
      
      /**** Ini Untuk Login ****/
      char username[20], password[20];
      system("cls");
      printf("\n\n");
      printf("\tLogin Sebagai Administrator\n");
      printf("\t+--------------------------+\n");
      printf("\tUsername : ");
      scanf("%s", &username);
      printf("\tPassword : ");
      scanf("%s", &password);
      printf("\t+--------------------------+\n");
      if (strcmp(username,"admin")==0 && strcmp(password,"1234")==0)
      {
      system("cls");
      system("color 1F");
      printf("\t\tLogin Succesfully\n");
      system("cls");
      printf("\t+-------------------------------------------+\n");
      printf("\t|\tSelamat Datang Administrator	    |\n");
      printf("\t+-------------------------------------------+\n");
      getch();
      system("cls");
      /**** Login Selesai ****/
      
      strcpy(data[0][1], "Super Pizza\t");
      strcpy(data[1][1], "Cheese Pizza Deluxe");
      strcpy(data[2][1], "Mochaccino\t");
      strcpy(data[3][1], "Pepsi Cool\t");
      strcpy(data[4][1], "Selesai Membeli\t");
      printf("\t+-----------------------------------------+\n");
      printf("\t|\t    Restoran Pizza Hot \t          |\n");
      printf("\t+-----------------------------------------+\n");
      printf("\t| Kode |           Menu\t\t  | Harga |\t\n");
      printf("\t+-----------------------------------------+");
      for(i=0;i<5;i++)
      {
      printf("\n\n");
               for(j=0;j<3;j++)
               {
                  printf("\t    %s", data[i][j]);
               }
      }
      printf("\n\n\t+-----------------------------------------+");
      printf("\n\n\tKet:\tPilih menu berdasarkan kode nya\n");
      printf("\t\tMasukkan nomor 0 setelah selesai.\n\n");
      
      FILE *Fout, *Barang;
      Fout = fopen("struk.txt", "w");
      Barang = fopen("barang.txt", "w");
      int baris = 0;
      while(menu != 0)
      {
                 printf("\n\nMasukkan nomor menu yang anda inginkan: ");
                 scanf("%i", &menu);
                 if (menu == 0)
                 {        
                          fclose(Barang);
                          fclose(Fout);
                          FILE *Barang, *Fin;
                          Barang = fopen("menu.txt", "r");
                          Fin = fopen("struk.txt", "r");
                          int x[baris];
                          int struk[baris][2];
                          jumlah = 0;
                          char hasilnya;
                          printf("\n\n\t---------------------------------------------\n");
                          printf("\t\t\tP I Z Z A  H O T\n");
                          printf("\n\tJl. Gajah Mada No. 38\n\tTelp. 080989999");
                          printf("\n\t---------------------------------------------\n");
                          printf("\tMenu\t\t   Jumlah\tHarga");
                          printf("\n\t---------------------------------------------");
                          for (i=0;i<baris;i++) {
                          printf("\n");
                          fscanf(Barang, "%i", &x[i]);
                          printf("\t%s", data[x[i]-1][1]);
                              for (j=0;j<2;j++) {
                                  fscanf(Fin, "%i", &struk[i][j]);
                                  printf("\t%i", struk[i][j]);
                              }
                              jumlah = jumlah + struk [i][0] * struk[i][1];     
                          }
                          fclose(Fin);
                          fclose(Barang);
                          printf("\n\t---------------------------------------------\n");
                          printf("\n\t%i Item\t\tJUMLAH\t:\t%i\n", baris, jumlah);
                          /* Hitung Diskon */
                          if (jumlah >= 75000 && jumlah < 100000)
                          {
                              diskon = jumlah * 0.05;
                              printf("\t\t\tDISCOUNT:\t%.0f (5 persen)\n", diskon);
                          }
                          else if (jumlah >= 100000)
                          {
                              diskon = jumlah * 0.1;
                              printf("\t\t\tDISCOUNT:\t%.0f (10 persen)\n", diskon);
                          }
                          else
                          {
                              diskon = 0;
                              printf("\t\t\tDISCOUNT:\t-\n");
                          }
                          total = jumlah - diskon;
                          printf("\t\t\tTOTAL\t:\t%i\n", total);
                          printf("\t\t\tBAYAR\t:\t");
                          scanf("%i", &bayar);
                          kembali = bayar - total;
                          printf("\t\t\tKEMBALI\t:\t%i\n", kembali);
                          printf("\n\n\tNB:\tBarang yg sudah dibeli tidak dapat");
                          printf("\n\t\tditukar/dikembalikan.");
                          printf("\n\t\tMohon periksa kembali barang anda");
                          printf("\n\t\tsebelum meninggalkan counter kami.\n");
                          getch();
                          exit(1);     
                 }
                 printf("\nJumlah beli: ");
                 scanf("%s", &qty);
                 fprintf(Barang, "%s ", data[menu-1][0]);
                 fprintf(Fout, "%s ", qty);
                 fprintf(Fout, "%s ", data[menu-1][2]);
                 baris++;
      }
}else{
      system("cls");
      printf("\n\n\n\n");
      printf("\t\tMaaf, username atau password yang anda masukkan salah!\n\t\t\t\tSilahkan coba lagi.");
      getch();
}

return 0;
}
