#include "pagalbines.h"


int main() {
    std::vector<Studentas> studentai{};
    studentu_ivestis(studentai);
    studentu_atspausdinimas(studentai);
    isvestis(studentai);
}