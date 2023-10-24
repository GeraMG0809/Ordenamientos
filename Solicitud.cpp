#include<iostream>
#include<string>


class Solicitud{
    private: 
        std::string Nombre;
        std::string Carrera;
        int Materias;
        float Promedio;

    public: 

        void setNombre(std::string);
        void setCarrera(std::string);
        void setMaterias(int);
        void setPromedio(float);

        std::string getNombre();
        std::string getCarrera();
        int getMaterias();
        float getPromedio();

        Solicitud();
        Solicitud(std::string,std::string,int,float);

        bool operator == (const Solicitud&)const;
        bool operator <  (const Solicitud&)const;
        bool operator >  (const Solicitud&)const;
        bool operator <= (const Solicitud&)const;
        bool operator >= (const Solicitud&)const;
        
        friend std::ostream& operator<<(std::ostream& os, Solicitud& solicitud){
            os << "Nombre del alumno: " << solicitud.getNombre() << std::endl;
            os << "Nombre de la carrera: " << solicitud.getCarrera() << std::endl;
            os << "Materias aprobadas: " << solicitud.getMaterias() << std::endl;
            os << "Promedio general: " << solicitud.getPromedio() << std::endl;
            return os;
        };

        friend std::istream& operator>>(std::istream& is ,  Solicitud& solicitud ){
            std::cout << "Nombre del alumno: ";
            is.ignore();
            getline(is, solicitud.Nombre);
            std::cout << "Nombre de la carrera: ";
            is.ignore();
            getline(is, solicitud.Carrera);
            std::cout << "Materias aprobadas: ";
            is.ignore();
            is >> solicitud.Materias;
            std::cout << "Promedio general: ";
            is.ignore();
            is >> solicitud.Promedio;
            return is;
            
        };

};

void Solicitud::setNombre(std::string nom){Nombre= nom;}

void Solicitud::setCarrera(std::string carr){Carrera = carr;}

void Solicitud::setMaterias(int mat){Materias = mat;}

void Solicitud::setPromedio(float prom){Promedio = prom;}

std::string Solicitud::getNombre(){return Nombre;}

std::string Solicitud::getCarrera(){return Carrera;}

int Solicitud::getMaterias(){return Materias;}

float Solicitud::getPromedio(){return Promedio;}

Solicitud::Solicitud(){}
 
Solicitud::Solicitud(std::string nom,std::string carr,int mat,float prom){
    Nombre = nom;
    Carrera = carr;
    Materias = mat;
    Promedio = Promedio;
}

bool Solicitud::operator==(const Solicitud& other)const{
    return Nombre == other.Nombre;
}

bool Solicitud::operator < (const Solicitud& other)const{
    return Nombre < other.Nombre;
}

bool Solicitud::operator > (const Solicitud& other)const{
    return Nombre > other.Nombre;
}

bool Solicitud::operator <= (const Solicitud& other)const{
    return Nombre <= other.Nombre;
}

bool Solicitud::operator >= (const Solicitud& other)const{
    return Nombre >= other.Nombre;
}