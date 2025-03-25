#include <cstddef>
#include <iostream>
#include <cstring>
#include "Matrice.h"

Matrice::Matrice(const char* nom_, int nl_, int nc_, int valeur) {
    size_t length = std::strlen(nom_);
    nom = new char[length + 1];
    std::strncpy(nom, nom_, length);
    nom[length] = '\n';
    nl = nl_;
    nc = nc_;
    mat = new float*[nl];
    for (int i = 0; i < nl; i++) {
        mat[i] = new float[nc];
    }
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            mat[i][j] = valeur;
        }
    }
}
Matrice::Matrice(const Matrice &matrice_) {
    size_t length = std::strlen(matrice_.nom);
        nom = new char[length + 1];
        std::strncpy(nom, matrice_.nom, length);
        nom[length] = '\n';
        nl = matrice_.nl;
        nc = matrice_.nc;
        mat = new float*[nl];
        for (int i = 0; i < nl; i++) {
            mat[i] = new float[nc];
        }
        for (int i = 0; i < nl; i++) {
            for (int j = 0; j < nc; j++) {
                mat[i][j] = matrice_.mat[i][j];
            }
        }
}
Matrice::~Matrice() {
    delete[] nom;
    for (int i = 0; i < nl; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}
void Matrice::lecture(float ** mat_, const int &nl_, const int &nc_) {
    if (nc != nc_) {
        for (int i = 0; i < nl; i++) {
            delete[] mat[i];
            mat[i] = new float[nc];
        }
        nc = nc_;
    }
    if (nl != nl_) {
        delete[] mat;
        mat = new float*[nl];
        nl = nl_;
    }
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            mat[i][j] = mat_[i][j];
        }
    }
}
void Matrice::afficher() const {
    std::cout << "La matrice " << nom << NEW_LINE;
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << NEW_LINE;
    }
}
Matrice *Matrice::transposee() {
    Matrice *matrice_ = new Matrice(nom, nc, nl);
    float **mat_ = new float*[nc];
    for (int i = 0; i < nc; i++) {
        mat_[i] = new float[nl];
    }
    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nl; j++) {
            mat_[j][i] = mat[i][j];
        }
    }
    matrice_->lecture(mat_, nc, nl);
    return matrice_;
}
