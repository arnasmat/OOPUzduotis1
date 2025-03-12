
template <typename Container>
void studentu_kategorizacija_testavimas(Container& studentai, const int rodyti_pasirinkimas, const int rusiuoti_pagal, std::chrono::duration<double>& testavimo_laikas, const int i) {
    //ekvivalentu "kietekams" ir "vargsiukams", tiesiog formaliau pavadinta
    std::vector<Studentas> islaike_studentai{};
    std::vector<Studentas> neislaike_studentai{};

    auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
    studentu_galutiniu_pazymiu_skaiciavimas(studentai);
    studentu_rusiavimas(studentai, rusiuoti_pagal);
    auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu rusiavimas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;


    nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
    if(rusiuoti_pagal == 3) {
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_vidurkis>=5.0f;}
            );
            islaike_studentai.assign(studentai.begin(), partition_iteratorius);
            neislaike_studentai.assign(partition_iteratorius, studentai.end());
    } else if(rusiuoti_pagal == 4) {
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_vidurkis<=5.0f;}
            );
        neislaike_studentai.assign(studentai.begin(), partition_iteratorius);
        islaike_studentai.assign(partition_iteratorius, studentai.end());
    }else if(rusiuoti_pagal==5){
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_mediana>=5.0f;}
            );
            islaike_studentai.assign(studentai.begin(), partition_iteratorius);
            neislaike_studentai.assign(partition_iteratorius, studentai.end());
    } else if(rusiuoti_pagal==6){
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_mediana<=5.0f;}
            );
        neislaike_studentai.assign(studentai.begin(), partition_iteratorius);
        islaike_studentai.assign(partition_iteratorius, studentai.end());
        neislaike_studentai.shrink_to_fit();
        islaike_studentai.shrink_to_fit();
        studentai.clear();
    }

    sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu kategorizavimas istrinant originalu vektoriu truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;
    return;

    try {
        nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
        std::ofstream islaike_output("../data/output/islaike_studentai.txt");
        isvestis(islaike_studentai, islaike_output, rodyti_pasirinkimas);
        islaike_output.close();
        sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
        std::cout<<i<<" Irasu islaikiusiuju irasymo i faila laikas: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
        testavimo_laikas+=sugaistas_laikas;

        nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
        std::ofstream neislaike_output("../data/output/neislaike_studentai.txt");
        isvestis(neislaike_studentai, neislaike_output, rodyti_pasirinkimas);
        neislaike_output.close();
        sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
        std::cout<<i<<" Irasu neislaikiusiuju irasymo i faila laikas: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
        testavimo_laikas+=sugaistas_laikas;
    } catch(std::exception& e) {
        std::cerr<<"Ivyko klaida isvedant i failus failus: "<<e.what()<<"\n";
    }
}

template <typename Container>
void nuskaitymo_ir_isvesties_testavimas(Container& temp_studentai, const std::vector<int>& kiekiai, bool& praejo){
    for(auto &i: kiekiai) {
        std::chrono::duration<double> testavimo_laiku_suma{0};
        for(int j=0; j<3; j++) {
            std::chrono::duration<double> testavimo_laikas{0};
            fs::path failo_pavadinimas{"../data/input/studentai_isvestis" + std::to_string(i) + ".txt"};
            auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
            studentu_ivestis_is_failo(temp_studentai, failo_pavadinimas, praejo);
            auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
            // std::cout<<"Failo su "<<i<<" studentais nuskaitymas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
            testavimo_laikas+=sugaistas_laikas;
            // studentu_kategorizacija_testavimas(temp_studentai, 3, 3,testavimo_laikas, i);
            // studentu_kategorizacija_1_strategija_testavimas(temp_studentai, 3, 3,testavimo_laikas, i);
            studentu_kategorizacija_2_strategija_testavimas(temp_studentai, 3, 3,testavimo_laikas, i);
            // std::cout<<i<<" irasu testavimo laikas: "<<testavimo_laikas.count()<<"\n";
            testavimo_laiku_suma +=testavimo_laikas;
            temp_studentai.clear();
        }
        std::cout<<i << " vidurkis: " << testavimo_laiku_suma.count()/3 <<"\n";
        // std::cout<<"\n---------------------------------------------------\n";
    }
}

template <typename Container>
void studentu_kategorizacija_1_strategija_testavimas(Container& studentai, const int rodyti_pasirinkimas, const int rusiuoti_pagal, std::chrono::duration<double>& testavimo_laikas, const int i) {
    //ekvivalentu "kietekams" ir "vargsiukams", tiesiog formaliau pavadinta
    std::vector<Studentas> islaike_studentai{};
    std::vector<Studentas> neislaike_studentai{};

    auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
    studentu_galutiniu_pazymiu_skaiciavimas(studentai);
    studentu_rusiavimas(studentai, rusiuoti_pagal);
    auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu rusiavimas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;

    if(rusiuoti_pagal==3 || rusiuoti_pagal==4) {
        for(auto &stud :studentai) {
            if(stud.galutinis_vidurkis >= 5.0) {
                islaike_studentai.push_back(stud);
            } else {
                neislaike_studentai.push_back(stud);
            }
        }
    } else if(rusiuoti_pagal==5 || rusiuoti_pagal==6) {
        for(auto &stud :studentai) {
            if(stud.galutinis_mediana >= 5.0) {
                islaike_studentai.push_back(stud);
            } else {
                neislaike_studentai.push_back(stud);
            }
        }
    }
    neislaike_studentai.shrink_to_fit();
    islaike_studentai.shrink_to_fit();
    studentai.clear();

    sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu kategorizavimas istrinant originalu vektoriu truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;
    // Toliau nerasau, nes testavimui reikalinga tik tiek :)
}

template <typename Container>
void studentu_kategorizacija_2_strategija_testavimas(Container& studentai, const int rodyti_pasirinkimas, const int rusiuoti_pagal, std::chrono::duration<double>& testavimo_laikas, const int i) {
    //ekvivalentu "kietekams" ir "vargsiukams", tiesiog formaliau pavadinta
    std::vector<Studentas> islaike_studentai{};
    std::vector<Studentas> neislaike_studentai{};

    auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
    studentu_galutiniu_pazymiu_skaiciavimas(studentai);
    studentu_rusiavimas(studentai, rusiuoti_pagal);
    auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu rusiavimas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;

    if (rusiuoti_pagal == 3 || rusiuoti_pagal == 4) {
        for (auto it = studentai.begin(); it != studentai.end(); ) {
            if (it->galutinis_vidurkis >= 5.0f) {
                islaike_studentai.push_back(*it);
                it = studentai.erase(it);
            } else {
                ++it;
            }
        }
    } else if (rusiuoti_pagal == 5 || rusiuoti_pagal == 6) {
        for (auto it = studentai.begin(); it != studentai.end(); ) {
            if (it->galutinis_mediana >= 5.0f) {
                islaike_studentai.push_back(*it);
                it = studentai.erase(it);
            } else {
                ++it;
            }
        }
    }
    islaike_studentai.shrink_to_fit();

    sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu kategorizavimas istrinant originalu vektoriu truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;
    // Toliau nerasau, nes testavimui reikalinga tik tiek :)
}