/**
 * @file Point_documented.h
 * @brief File header yang mendefinisikan kelas Point untuk merepresentasikan
 *        titik lokasi 2D serta fungsi perhitungan jarak Euclidean.
 * @details Dirancang agar portabel di berbagai kompiler (Clang++/G++) tanpa
 *          membocorkan namespace global ke file yang meng-include header ini.
 */

#pragma once

#include <cmath>  // mengimport library cmath untuk fungsi matematika seperti std::hypot
#include <string> // mengimport library string agar titik dapat menyimpan kode nama (misal: M, A, B)

/**
 * @class Point
 * @brief Merepresentasikan sebuah titik lokasi pada bidang Kartesius 2D.
 */
class Point {
private:
    std::string name; ///< Kode identitas titik/kota (misal: "M", "A", "B")
    double x;         ///< Nilai koordinat pada sumbu X
    double y;         ///< Nilai koordinat pada sumbu Y

public:
    /**
     * @brief Konstruktor default (menginisialisasi titik di pusat koordinat dengan nama kosong).
     */
    Point() {
        name = ""; // menginisialisasi nama titik kosong secara default
        x = 0.0;   // menginisialisasi nilai awal x menjadi 0.0 secara default
        y = 0.0;   // menginisialisasi nilai awal y menjadi 0.0 secara default
    }

    /**
     * @brief Konstruktor berparameter untuk membuat objek Point dengan data spesifik.
     * @param pname Kode nama lokasi.
     * @param px Nilai koordinat sumbu X.
     * @param py Nilai koordinat sumbu Y.
     */
    Point(std::string pname, double px, double py) {
        name = pname; // memasukkan nilai parameter pname ke variable name
        x = px;       // memasukkan nilai parameter px ke variable x
        y = py;       // memasukkan nilai parameter py ke variable y
    }

    /**
     * @brief Mengambil kode nama titik.
     * @return std::string Nama titik yang tersimpan.
     */
    std::string getName() const {
        return name; // mengembalikan nilai variable name
    }

    /**
     * @brief Mengambil nilai koordinat sumbu X.
     * @return double Koordinat X dari titik.
     */
    double getX() const {
        return x; // mengembalikan nilai variable x
    }

    /**
     * @brief Mengambil nilai koordinat sumbu Y.
     * @return double Koordinat Y dari titik.
     */
    double getY() const {
        return y; // mengembalikan nilai variable y
    }
}; // akhir class Point

/**
 * @brief Menghitung jarak lurus (Euclidean Distance) antara dua objek Point.
 * @details Menggunakan std::hypot untuk menghindari overflow/underflow saat selisih
 *          koordinat bernilai sangat besar atau sangat kecil.
 * @param p1 Objek Point pertama.
 * @param p2 Objek Point kedua.
 * @return double Jarak Euclidean antara titik p1 dan p2.
 */
inline double dist(const Point& p1, const Point& p2) {
    return std::hypot(p1.getX() - p2.getX(), p1.getY() - p2.getY());
}