#include "pagalbines.h"


int main() {
    std::vector<Studentas> studentai{};
    studentu_ivestis_vector(studentai);
    studentu_atspausdinimas(studentai);
    isvestis(studentai);
}