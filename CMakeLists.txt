cmake_minimum_required(VERSION 3.16)

project(sesion0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sesion0 main.cpp
    Usuario.h Usuario.cpp
    cuentabancaria.h cuentabancaria.cpp    
    patinete.h patinete.cpp
    pruebas/pruebas.h pruebas/pruebasCuentaBancaria.cpp pruebas/pruebasUsuario.cpp pruebas/pruebasPatinete.cpp
    build/Desktop-Debug/usuarios.csv build/Desktop-Debug/out.csv
    Cola.h
    estacion.h estacion.cpp
    pruebas/pruebasEstacion.h
    pruebas/pruebasEstacion.cpp
    ListaDPI.h
    gestorusuarios.h gestorusuarios.cpp
    pruebas/PruebaGestorUsuarios.h
    pruebas/PruebaGestorUsuarios.cpp
    sistema.h sistema.cpp
    build/Desktop-Debug/patinetes.csv build/Desktop-Debug/estaciones.csv
    pruebas/PruebaSistema.h
    pruebas/PruebaSistema.cpp)

include(GNUInstallDirs)
install(TARGETS sesion0
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
