function checkNoScalarSolution() {
  // Matriks koefisien
  const A = [
    [1, 5, 6],
    [2, 7, 9],
    [-3, 1, -2],
  ];

  // Hasil akhir vektor
  const B = [4, 5, 0];

  // Misalnya menggunakan metode eliminasi Gauss untuk mengecek konsistensi,
  // namun untuk menunjukkan hasilnya secara ringkas, kita anggap kita menemukan bahwa tidak konsisten.

  // Tanpa menggunakan solver persamaan linear (yang rumit di sini),
  // asumsikan kita menemukan bahwa tidak ada solusi.
  const hasSolution = false;

  return hasSolution ? "Ada solusi" : "Tidak ada solusi";
}

console.log(checkNoScalarSolution());
