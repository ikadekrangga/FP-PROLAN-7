int jumpSearchString(Inventory item[], int n, const char *query, int kriteria) {
	int step = sqrt(n); // Panjang langkah
	int prev = 0;
	
	// Jump sampai elemen lebih besar atau sama dengan query
	while (1) {
	    int index = (step < n ? step : n) - 1;
	    int hasilJump;
	
		if (kriteria == 1) { // Berdasarkan Nama
	        hasilJump = strcmp(item[index].name, query);
	    } else if (kriteria == 2) { // Berdasarkan Kategori
	        hasilJump = strcmp(item[index].category, query);
	    } else {
	        return -1; // Kriteria tidak valid untuk pencarian string
	    }
	
	    if (hasilJump >= 0) {
	        break; // Ditemukan blok yang sesuai
	    }
	
	    prev = step;
	    step += sqrt(n);
	    if (prev >= n) {
	        return -1; // Tidak ditemukan
	    }
	}
	
	// Linear search di blok yang ditemukan
	for (int i = prev; i < step && i < n; i++) {
	    if ((kriteria == 1 && strcmp(item[i].name, query) == 0) ||
	        (kriteria == 2 && strcmp(item[i].category, query) == 0)) {
	        return i; // Elemen ditemukan
	    }
	}
	
	return -1; // Tidak ditemukan
}

// Fungsi Jump Search untuk Quantity
int jumpSearchQTY(Inventory item[], int n, int query) {
    int step = sqrt(n);
    int prev = 0;
       
	// Lompat hingga elemen lebih besar atau sama dengan query
	while (item[(step < n ? step : n) - 1].quantity < query) {
    	prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; // Tidak ditemukan
        }
    }

    // Linear search di blok yang ditemukan
    for (int i = prev; i < step && i < n; i++) {
        if (item[i].quantity == query) {
            return i; // Elemen ditemukan
        }
    }

    return -1; // Tidak ditemukan
}
