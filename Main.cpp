#include"ListaEstatica.cpp"
#include"Solicitud.cpp"

void Ingresar(ListaEstatica<Solicitud>&);
void Eliminar(ListaEstatica<Solicitud>&);
void Buscar(ListaEstatica<Solicitud>&);

int main(){
    ListaEstatica<Solicitud> myLista;
    int opc;

    do
    {
        std::cout<<"\t --- MENU --- \n";
        std::cout<<"[1] - Ingresar "<<std::endl;
        std::cout<<"[2] - Eliminar "<<std::endl;
        std::cout<<"[3] - Mostrar  "<<std::endl;
        std::cout<<"[4] - Ordenar  "<<std::endl;
        std::cout<<"[5] - Buscar  "<<std::endl;
        std::cout<<"[6] - Salir    "<<std::endl;
        std::cin>>opc;

        switch (opc){
        case 1:
            Ingresar(myLista);
            break;
        case 2: 
            Eliminar(myLista);
            break;
        case 3: 
            myLista.imprime();
            break;
        case 4: 
            std::cout<<"Ordenando la lista..."<<std::endl;
            myLista.QuickSortPublic();
            std::cout<<"Lista ordenada..."<<std::endl;
            break;
        case 5 : 
            Buscar(myLista);
            break;

        default:
            std::cout<<"Opcion invalida..."<<std::endl;
            break;
        }
    } while (opc != 6);
    
}



void Ingresar(ListaEstatica<Solicitud>& myLista){
    if(myLista.Llena()){
        std::cout<<"Lista llena... imposible insertar"<<std::endl;
    }else{
        Solicitud nueva_solicitud;
        std::cin>>nueva_solicitud;
        if(myLista.Vacia()){
            myLista.inserta(nueva_solicitud, 0);
        }else{

            myLista.inserta(nueva_solicitud,myLista.Ultimo());
            std::cout<<"Solicitud ingresada correctamente"<<std::endl;
        }
    }
}

void Eliminar(ListaEstatica<Solicitud>& myLista){
    if(myLista.Vacia()){
        std::cout<<"Lista vacia... imposible eliminar"<<std::endl;
    }else{
        std::string name;
        std::cout<<"Ingresa el nombre: "<<std::endl; 
        std::cin>>name;
        Solicitud solicitud_eliminar; 
        solicitud_eliminar.setNombre(name);
        int pos = myLista.buscar(solicitud_eliminar);
        myLista.elimina(pos);
    }
}


void Buscar(ListaEstatica<Solicitud>& myLista){
    if(myLista.Vacia()){
        std::cout<<"Lista vacia... imposible buscar"<<std::endl;
    }else{
        std::string name;
        std::cout<<"Ingresa el nombre: "<<std::endl; 
        std::cin>>name;
        Solicitud solicitud_buscar; 
        solicitud_buscar.setNombre(name);
        int pos = myLista.BusquedaBinaria(solicitud_buscar);
        if(pos == 0){
            std::cout<<"no hay  constancias faltantes"<<std::endl;
        }else{
            if(pos == 1){
                std::cout<<"Hay "<<pos<<" constancia faltante"<<std::endl;
            }else{
                std::cout<<"Hay "<<pos<<"constancias faltantes"<<std::endl;
            }
        }
    }
}