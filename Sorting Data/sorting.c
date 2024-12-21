// Fungsi untuk sorting data item berdasarkan kriteria
void bubbleSort(Inventory item[], int n, int kriteria, int ascending) {
	for (int i = 0; i < n - 1; i++) {
	    for (int j = 0; j < n - i - 1; j++) {
	        int condition = 0;
	
	        // Pilih kriteria perbandingan
	        if (kriteria == 1) { // Berdasarkan Nama
	            condition = strcmp(item[j].name, item[j + 1].name) < 0;
	        } else if (kriteria == 2) { // Berdasarkan Kategori
	            condition = strcmp(item[j].category, item[j + 1].category) < 0;
	        } else if (kriteria == 3) { // Berdasarkan Quantity
	            condition = item[j].quantity < item[j + 1].quantity;
	        }
	
	        // kondisi untuk ascending/descending
	        if ((!ascending && condition) || (ascending && !condition)) {
	            Inventory temp = item[j];
	            item[j] = item[j + 1];
	            item[j + 1] = temp;
	        }
	    }
	}
}
