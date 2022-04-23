# Manual de usuario
## Ingresar Registros de Alumnos

Desde el codigo Dev-C++ se establece una coneccion a la base de datos Localhost
### Menu para ingresar los datos de alumnos 
Acontinucacion se presentan los pasos para guardar datos en el comando C++ con coneccion a Mysql
  
1. Ingresar un Almno con datos

-Nombre
-Clave
-Correo
-Promedio

2. Ingresar un Grado con datos

-Nombre
-Codigo

3. Ingresar una Seccion con datos 

-Nombre
-Codigo

4. Ingresar notas Por Bimestre

-Primer Bimestre
-Segundo Bimestre
-Tercer Bimestre
-Cuarto Bimestre

5. Buscar un alumno
se debe buscar por medio del nombre del grado, ya ingresado en el insiso 2

6. Buscar un grado
de igual manera en el insiso 5 se busca por medio del nombre del alumno ya ingresado en el insiso 1

7. Borrar un Alumno o grado
Se muestran 2 opciones
-Borrar Alumno
-Borrar Grado
el alumno se debe borrar por medio del nombre o la asignacion
de igual manera el grado se borrar por medio del nombre o la asignacion

8. Modificar los datos de un alumno
Se modificaran por medio del nombre y el id que se genero en la base de datos, se muestra un listado de los alumnos que fueron ingresados.

9. Modificar los datos de  un Grado
Se modificaran por medio del nombre e id que genero la base de datos, tambien se muestra un listado de los grados que fueron ingresados.

10. Asignar a un Alumno
Para poder ingresar un alumno se tomara en cuenta el id de cada una de las opciones anteriores, se muestra un listado de todos los datos que fueron ingresados en la base de datos para poder relacionar cada uno

11. Listar los Alumnos de un grado o seccion
Se muestran dos opciones
-Listar grado
-Listar seccion

Al listar los grados se muestran los datos de todos los grados,al elegir un grado se listaran todos los alumnos de dicho grado
Al listar las secciones se muestran los datos de todas las secciones, al eligir un nombre de seccion apareceran todos los alumnos que fueron asignados a dicha seccion.
 
12. Se regresar al Menu principal o se saldra de la aplicacion


