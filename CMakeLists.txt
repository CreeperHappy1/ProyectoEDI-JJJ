cmake_minimum_required(VERSION 3.16)

project(ProyectoEDI-JJJ LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#flags precompilación: descomenta las que quieras activar
#add_compile_definitions(ARBOLYPUBLICADOS)
#add_compile_definitions(LISTA)

#archivos en el directorio build/Desktop-Debug/ también tendrán que ser añadidos al .gitignore
add_executable(ProyectoEDI-JJJ main.cpp.backup
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
    BSTree.h
    gestorusuarios.h gestorusuarios.cpp
    pruebas/PruebaGestorUsuarios.h
    pruebas/PruebaGestorUsuarios.cpp
    sistema.h sistema.cpp
    build/Desktop-Debug/patinetes.csv build/Desktop-Debug/estaciones.csv
    pruebas/PruebaSistema.h
    pruebas/PruebaSistema.cpp
    .gitignore
    build/Desktop-Debug/alquilerPatinetes.csv
    build/Desktop-Debug/distribucionPatinetes.csv
    ProgPrincipal.cpp
    KeyValue.h
)

include(GNUInstallDirs)
install(TARGETS ProyectoEDI-JJJ
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
