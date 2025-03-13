# OOPUzduotis1 (Studentų surašymo ir skirstymo programa) - v1.0
Studentų pažymių surašymo (ranka, automatiškai sugeneruojamų arba iš failo) bei vidurkių skaičiavimo ir studentų
kategorizacijos į dvi grupes programa </br>

# 🛠️ Projekto kompiliavimo instrukcijos
1. Atsisiųsti [CMake (Bent v. 3.29)](https://cmake.org/download/)
2. [Klonuoti šio projekto direktoriją](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)
3. Atsidaryti komandinę eilutę (cmd arba powershell) ir į ją įvesti </br> `cmake -B build -S . ; cmake --build build`
4. Eiti į naujai sukurtą /build/ direktoriją ir joje paleisti <strong>OOPUžduotis1.exe</strong> :)

# Projekto naudojimosi instrukcijos
Įjungus programą turėtumete matyti meniu su galimais pasirinkimais:
1. Studentus ir pazymius ivesti ranka - Leidžia studentų vardus ir pažymius įvesti ranka
2. Generuoti pazymius, bet studentus ivesti ranka - Automatiškai sugeneruoja pažymius jūsų įvestiems studentams
3. Generuoti pazymius ir studentus - Automatiškai sugeneruoja nuo 1 iki 10 studentų ir jų pažymių
4. Ivesti pazymius is failo, siuo metu pasirinktas failas: ... - Leidžia naudotis programą su 5 punkte pasirinktu failu
5. Pasirinkti ivesties faila - leidžia pasirinkti įvesties failą iš visų galimų data/input direktorijoje
6. Generuoti faila - sugeneruoja jūsų norimo dydžio pavyzdinį studentų failą
7. Testavimo rezimas - programos spartumo testavimas
8. Baigti programos darba

### Jeigu norite įkelti savo failą programos 4. ir 5. punktams, tai galima padaryti įkėlus atitinkamą failą į projekto data/input/ direktoriją. </br>

Testuojant programos spartą:
1. Failu kurimo greiti
2. Failu nuskaitymo greiti (su senos versijos testiniais failais) - būtina turėti testavimo failus.
3. Failu nuskaitymo, rusiavimo, kategorizavimo ir isvesties greiti - būtina pirma sugeneruoti failus su 1. punktu.
Greitis gali priklausyti nuo sugeneruotų failų pažymių kiekio.

-----------------------------
## Programos testavimo kompiuterio specifikacijos
| Komponentas | Specifikacija           |
|-------------|-------------------------|
| CPU         | Intel i7-13700H 2.40GHz |
| RAM         | 16 GB DDR5              |
| HDD         | SSD                     |

# Strategiju testavimo rezultatai
(Testai daryti be -O3. Programos naudojimo metu rezultatai bus greitesni.)

## Strategija 1
### Su Vector
![S1_Vector](img/S1_Vec.png)
### Su List
![S1_List](img/S1_List.png)
### Su Deque
![S1_Deque](img/S1_Deque.png)
</br>

## Strategija 2
(Patobulinta versija)
### Su Vector
![img.png](img/S2_Vec.png)
### Su List
![img_1.png](img/S2_List.png)
### Su Deque
![img_2.png](img/S2_Deque.png)
</br>

## Strategija 3
Pagal strategija 2 naudojant std::stable_partition
### Su Vector
![img.png](img/S3_Vec.png)
### Su List
![img_1.png](img/S3_List.png)
### Su Deque
![img_2.png](img/S3_Deque.png)
</br>

-------------------------
# Programos testavimo rezultatai pradiniam release:
Testuojama tik failo nuskaitymas, įrašų rūšiavimas bei kategorizavimas. Pateikiamas trijų testų vidurkis. </br>
Visi failai turi po 5 ND pažymius.
### Testavimas su vector:
![img.png](img/img.png)

### Testavimas su list:
![img_1.png](img/img_1.png)

### Testavimas su deque:
![img_2.png](img/img_2.png)** 