int main() {
	
    // Data item
    Inventory item[DATABASE] = {
        {"Anemoculus", "Oculi", 131},
        {"Dendroculus", "Oculi", 211},
        {"Electroculus", "Oculi", 246},
        {"Geoculus", "Oculi", 186},
        {"Teyvat's Egg", "Food", 1000},
        {"Resin", "Consumable", 160},
        {"Primogems", "Gacha", 189},
        {"Pizza Eula", "Food", 23},
        {"Widhsith", "Weapon", 11},
        {"Claymore", "Weapon", 189}
    };

    int jumlahItem = DATABASE;
    int kriteria, ascending, opsi;
    char searchQuery[50];
    int searchQTY;
    const char *filename = "Inventory-Genshin.txt";
    int nameSorted = 0;     // 0 = belum disortir berdasarkan nama
	int categorySorted = 0; // 0 = belum disortir berdasarkan kategori
	int quantitySorted = 0; // 0 = belum disortir berdasarkan kuantitas



    do {
    	printf("\n +-----------------------------+\n");
        printf(" |        GENSHIN IMPACT       |");
        printf("\n +-----------------------------+\n");
        printf(" | ==== I N V E N T O R Y ==== |");
        printf("\n +---+-------------------------+\n");
        printf(" | 1 | Open Inventory          |\n");
        printf(" | 2 | Sort Item               |\n");
        printf(" | 3 | Find Item               |\n");
        printf(" | 4 | Save Database           |\n");
        printf(" | 5 | Load Database           |\n");
        printf(" | 6 | Exit                    |");
        printf("\n +---+-------------------------+\n");
        printf("\n Select option: ");
        scanf("%d", &opsi);

        switch (opsi) {
        	
        case 1:
            printf("\n Inventory:\n");
            printData(item, jumlahItem);
            break;
            
        case 2:
            printf("\n Pilih Kriteria Sortir:\n");
            printf(" 1. Name\n");
            printf(" 2. Category\n");
            printf(" 3. Quantity\n");
            printf("\n Masukkan opsi (1-3): ");
            scanf("%d", &kriteria);

            printf("\n Pilih Urutan: \n");
            printf(" 1. Ascending\n");
            printf(" 2. Descending\n");
            printf("\n Masukkan opsi (1-2): ");
            scanf("%d", &ascending);

            bubbleSort(item, jumlahItem, kriteria, ascending == 1);
		    // Set status sorting
		    if (kriteria == 1) {
		        nameSorted = 1;
		        categorySorted = 0; // Reset status kategori
		        quantitySorted = 0; // Reset status kuantitas
		    } else if (kriteria == 2) {
		        nameSorted = 0; // Reset status nama
		        categorySorted = 1;
		        quantitySorted = 0; // Reset status kuantitas
		    } else if (kriteria == 3) {
		        nameSorted = 0;	// Reset status nama
		        categorySorted = 0; // Reset status kategori
		        quantitySorted = 1;
		    }
            printf("\n Inventory setelah di-sortir:\n");
            printData(item, jumlahItem);
            break;
            
    	case 3:
		    // Pastikan data sudah di-sortir berdasarkan kriteria
		    if ((kriteria == 1 && !nameSorted) ||
		        (kriteria == 2 && !categorySorted) ||
		        (kriteria == 3 && !quantitySorted)) {
		        printf("\n Data belum disortir... Silakan sortir terlebih dahulu!\n");
		        break;
		    }
		    printf("\n Pilih Kriteria Pencarian:\n");
		    printf(" 1. Name\n");
		    printf(" 2. Category\n");
		    printf(" 3. Quantity\n");
		    printf("\n Masukkan opsi (1-3): ");
		    scanf("%d", &kriteria);
		
		    /* Pastikan data sudah di-sortir 
			(Jika data ditemukan sebelum di-sortir, artinya linear search...) */
		    bubbleSort(item, jumlahItem, kriteria, 1);
		
		    if (kriteria == 3) {
		        printf("\n Masukkan quantity yang ingin dicari: ");
		        scanf("%d", &searchQTY);
		        int found = 0; // Flag apakah ada item ditemukan
				printf("\n Item yang ditemukan:\n");
				for (int i = 0; i < jumlahItem; i++) {
    				if (item[i].quantity == searchQTY) {
        				printData(&item[i], 1);
        				found = 1; // flag 1 jika item ditemukan
    				}
				}
				if (!found) {
	    			printf("\n Item dengan quantity %d tidak ditemukan.\n", searchQTY);
				}

		        
		    } else {
		    	while (getchar() != '\n'); 
		        printf("\n Masukkan keyword yang ingin dicari: ");
		        scanf("%[^\n]", searchQuery); // %[^\n] agar bisa cari nama item yang lebih dari 1 kata
		        int found = 0; // Flag apakah ada item ditemukan
		        printf("\n Item yang ditemukan:\n");
		        for (int i = 0; i < jumlahItem; i++) {
		            if ((kriteria == 1 && strcmp(item[i].name, searchQuery) == 0) ||
		                (kriteria == 2 && strcmp(item[i].category, searchQuery) == 0)) {
		                printData(&item[i], 1);
		                found = 1; // flag 1 jika item ditemukan
		            }
		        }
		        if (!found) {
		            printf("\n Item dengan keyword '%s' tidak ditemukan.\n", searchQuery);
		        }
		    }
		    break;

        case 4:
        	saveDatabase(item, jumlahItem, filename);
            break;
            
        case 5: 
    		jumlahItem = loadDatabase(item, filename);
    		break;

        case 6:
            printf("\n Keluar...\n");
            break;
            
        default:
            printf("\n Opsi invalid...\n");
        }
        
    } while (opsi != 6);

    return 0;
}
blablabla;