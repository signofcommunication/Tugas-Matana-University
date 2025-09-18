using System;

public class Karyawan
{
    protected string nama;
    private string alamat;
    private string telepon;

    public Karyawan(string nama)
    {
        this.nama = nama;
    }

    public virtual double Gaji()
    {
        return 1000000; // Gaji tetap 1 juta
    }

    public void SetAlamat(string alamat)
    {
        this.alamat = alamat;
    }

    public string GetAlamat()
    {
        return alamat;
    }

    public void SetTelepon(string telepon)
    {
        this.telepon = telepon;
    }

    public string GetTelepon()
    {
        return telepon;
    }
}

public class PartTime : Karyawan
{
    private int jamKerja;
    private double upah;

    public PartTime(string nama, double upah) : base(nama)
    {
        this.upah = upah;
    }

    public void SetJamKerja(int jamKerja)
    {
        this.jamKerja = jamKerja;
    }

    public override double Gaji()
    {
        return jamKerja * upah;
    }
}

public class FullTime : Karyawan
{
    private double gajiBulanan;
    private double uangLembur;
    private int lamaLembur;

    public FullTime(string nama, double gajiBulanan, double uangLembur) : base(nama)
    {
        this.gajiBulanan = gajiBulanan;
        this.uangLembur = uangLembur;
    }

    public void SetLamaLembur(int lamaLembur)
    {
        this.lamaLembur = lamaLembur;
    }

    public override double Gaji()
    {
        return gajiBulanan + (uangLembur * lamaLembur);
    }
}

public class MainProgram
{
    static void Main(string[] args)
    {
        Karyawan[] karyawan = new Karyawan[4];
        int index = 0;

        while (true)
        {
            Console.WriteLine("1. Input Data");
            Console.WriteLine("2. Keluar");
            Console.Write("Pilihan Anda : ");
            string pilihan = Console.ReadLine();

            if (pilihan == "2")
            {
                break;
            }
            else if (pilihan == "1")
            {
                while (index < 4)
                {
                    Console.Write("Masukkan nama: ");
                    string nama = Console.ReadLine();
                    Console.Write("Masukkan alamat: ");
                    string alamat = Console.ReadLine();
                    Console.Write("Masukkan telepon: ");
                    string telepon = Console.ReadLine();
                    Console.Write("Masukkan 1 jika part time dan 2 jika full time: ");
                    string status = Console.ReadLine();

                    if (status == "1")
                    {
                        Console.Write("Masukkan jam kerja: ");
                        int jamKerja = int.Parse(Console.ReadLine());
                        Console.Write("Masukkan upah per jam: ");
                        double upah = double.Parse(Console.ReadLine());

                        PartTime partTime = new PartTime(nama, upah);
                        partTime.SetAlamat(alamat);
                        partTime.SetTelepon(telepon);
                        partTime.SetJamKerja(jamKerja);
                        karyawan[index] = partTime;
                    }
                    else if (status == "2")
                    {
                        Console.Write("Masukkan gaji bulanan: ");
                        double gajiBulanan = double.Parse(Console.ReadLine());
                        Console.Write("Masukkan jam lembur: ");
                        int lamaLembur = int.Parse(Console.ReadLine());
                        Console.Write("Masukkan uang lembur per jam: ");
                        double uangLembur = double.Parse(Console.ReadLine());

                        FullTime fullTime = new FullTime(nama, gajiBulanan, uangLembur);
                        fullTime.SetAlamat(alamat);
                        fullTime.SetTelepon(telepon);
                        fullTime.SetLamaLembur(lamaLembur);
                        karyawan[index] = fullTime;
                    }

                    index++;

                    if (index < 4)
                    {
                        Console.Write("Apakah mau mengulangi mengisi data? (Ya/Tidak): ");
                        string ulang = Console.ReadLine();
                        if (ulang.ToLower() != "ya")
                        {
                            break;
                        }
                    }
                }

                // Tampilkan data karyawan
                Console.WriteLine("\nData Karyawan:");
                for (int i = 0; i < index; i++)
                {
                    Console.WriteLine($"Karyawan {i + 1}:");
                    Console.WriteLine($"Nama: {karyawan[i].GetType().Name}");
                    Console.WriteLine($"Alamat: {karyawan[i].GetAlamat()}");
                    Console.WriteLine($"Telepon: {karyawan[i].GetTelepon()}");
                    Console.WriteLine($"Gaji: {karyawan[i].Gaji():C}");
                    Console.WriteLine();
                }
            }
            else
            {
                Console.WriteLine("Pilihan tidak valid!");
            }
        }
    }
}
