class ExpertSystem:
    def __init__(self):
        # Inisialisasi fakta awal berdasarkan dokumen
        self.facts = {
            "volume_silinder": 280,  # cc
            "rasio_kompresi": 12,   # 12:1
            "daya_kuda": 26,        # HP
            "torsi_optimal": True,
            "karburator": "PWK",
            "cdi": "BRT",
            "suara_mesin_baik": True,
            "tuning_ulang": True
        }
        # Inisialisasi aturan dari basis pengetahuan
        self.rules = [
            {"id": 1, "condition": lambda f: 250 <= f["volume_silinder"] <= 300 and 11 <= f["rasio_kompresi"] <= 13, 
             "action": "syarat_teknis_dasar", "percentage": 20},
            {"id": 2, "condition": lambda f: f["daya_kuda"] >= 25, 
             "action": "syarat_performa", "percentage": 20},
            {"id": 3, "condition": lambda f: f["karburator"] == "PWK" and f["cdi"] == "BRT", 
             "action": "syarat_komponen", "percentage": 20},
            {"id": 5, "condition": lambda f: f["rasio_kompresi"] >= 11, 
             "action": "efisiensi_daya_kuda_meningkat", "percentage": 10},
            {"id": 6, "condition": lambda f: "efisiensi_daya_kuda_meningkat" in f, 
             "action": "akselerasi_torsi_meningkat", "percentage": 10},
            {"id": 8, "condition": lambda f: f["suara_mesin_baik"], 
             "action": "oli_berkualitas", "percentage": 5},
            {"id": 9, "condition": lambda f: f["suara_mesin_baik"] and 11 <= f["rasio_kompresi"] <= 13, 
             "action": "durabilitas_tinggi", "percentage": 5},
            {"id": 4, "condition": lambda f: "syarat_teknis_dasar" in f and "syarat_performa" in f and "syarat_komponen" in f and "durabilitas_tinggi" in f, 
             "action": "layak_balapan", "percentage": 10}
        ]
        # Persentase kelayakan
        self.percentage = 0

    def forward_chaining(self):
        # Proses inferensi Forward Chaining
        applied_rules = set()  # Menyimpan aturan yang sudah diterapkan
        new_facts = True

        while new_facts:
            new_facts = False
            for rule in self.rules:
                if rule["id"] not in applied_rules and rule["condition"](self.facts):
                    # Terapkan aturan dan tambahkan fakta baru
                    self.facts[rule["action"]] = True
                    applied_rules.add(rule["id"])
                    self.percentage += rule["percentage"]
                    new_facts = True
                    print(f"Rule {rule['id']} applied: {rule['action']} (+{rule['percentage']}%)")

        # Tampilkan hasil akhir
        print("\nFakta akhir:", self.facts)
        print(f"Total persentase kelayakan: {self.percentage}%")
        if self.percentage >= 70:
            print("Kesimpulan: Motor Yamaha Scorpio Z LAYAK untuk balapan trek lurus.")
        else:
            print("Kesimpulan: Motor Yamaha Scorpio Z TIDAK LAYAK untuk balapan trek lurus. Perlu peningkatan.")

    def run(self):
        print("Memulai evaluasi kelayakan motor Yamaha Scorpio Z...\n")
        print("Fakta awal:", self.facts)
        print("\nProses Forward Chaining:")
        self.forward_chaining()

# Jalankan sistem pakar
if __name__ == "__main__":
    system = ExpertSystem()
    system.run()
