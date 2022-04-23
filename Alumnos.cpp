#include <iostream>
#include <mysql.h>

//FUNCION MENU DE BIENVENIDA//
void Alumnos();
//FUNCION DEL MENU DE ALUMNOS//
void AgregarAlumno();
void AgregarGrado();
void AgregarSeccion();
void AgregarNota();
void BuscarAlumno();
void BuscarGrado();
void BorrarAlumnooGrado();
void ModificardatoAlumno();
void ModificardatoGrado();
void AsignarAlumno();
void Listaralumnogradoyseccion();
//FUNCION DEL MENU BORRAR//
void BorrarAlumno();
void BorrarGrado();       
//FUNCION DEL MENU LISTAR//
void ListarGrado();
void ListarSeccion();

using namespace std;

char serverdb[] = "localhost";
char userdb[] = "Deyvid";
char passworddb[] = "Umg$2019";
char databasedb[] = "escuela";

 	
int main() {
	int opcion;
	char opc = 's';
	while (opc == 's')
	{
    system("cls");
	cout<<"Bienvenido al menu de Escuela ingrese una opcion"<<endl;
	cout<<"1. Registros Alumnos"<<endl;
	cout<<"2. Salir de Aplicacion"<<endl;
	cin>>opcion;
	if(opcion>2 && opcion <= 0)
	    {
            cout<<"\n \t\t\tOpcion invalida!!!"<<endl;
            cout<<"\n \t\t\tIngrese la Opcion Correcta: ";
            cin>>opcion;
    }
	switch(opcion)
	{
	
		case 1:
         		Alumnos();
        case 2:
        	cout<<"Desea salir de la aplicacion S/N ?\n"<<endl;
			cin>>opc;
			if (opc == 's'){
				return 0;
			}
			else	
        	{
        		return main();
			}
		}
	system("Pause()");
	}
}

void Alumnos(){
	int opcion;
	char opc = 's';
	while (opc == 's')
	{
    system("cls");
	int opcion;
	cout<<"Ingrese una de las siguientes ocpiones"<<endl;
	cout<<"1-Agregar Alumno"<<endl; 
	cout<<"2-Agregar Grado"<<endl;
	cout<<"3-Agregar Seccion"<<endl;
	cout<<"4-Agregar Nota"<<endl;
	cout<<"5-Buscar a un Alumno"<<endl;
	cout<<"6-Buscar un Grado"<<endl;
	cout<<"7-Borrar un Alumno o Grado"<<endl;
	cout<<"8-Modificar los datos de un Alumno"<<endl;
	cout<<"9-Modificar los datos de un Grado"<<endl;
	cout<<"10-Asignar a un Alumno"<<endl;
	cout<<"11-Listar los alumnos de un grado y seccion"<<endl;
	cout<<"12-Regresar al menu principal"<<endl;
	cin>>opcion;
switch (opcion)
	{
	
		case 1: 
         		AgregarAlumno();
        break;
        case 2: 
         		AgregarGrado();
        break;
        case 3: 
         		AgregarSeccion();
        break;
        case 4: 
         		AgregarNota();
		break;
        case 5: 
         		BuscarAlumno();
        break;
        case 6: 
         		BuscarGrado();
        break;
        case 7: 
         		BorrarAlumnooGrado();
        break;
        case 8: 
         		ModificardatoAlumno();		
        break;
        case 9: 
         		ModificardatoGrado();
        break;
        case 10: 
         		AsignarAlumno();
        break;
        case 11: 
         		Listaralumnogradoyseccion();
        break;
        case 12: 
         		cout<<"Desea regresar al menu principal S/N ?\n"<<endl;
                fflush(stdin);
				cin>>opc;
		break;
		}
	system("Pause()");
	}
}
//////////////////////AGREGAR ALUMNO///////////////////
void AgregarAlumno(){
	MYSQL* connection;
	long alumno_id;
	string alumno_nombre;
	string alumno_clave;
	string alumno_correo;
	string alumno_promedio;
	string sql;
	string sql2;
	int result;
	const char* query;
	connection = mysql_init(0);
	if (connection)
	{
		cout<< "La libreria MySQL se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection,serverdb, userdb, passworddb,databasedb, 3306, NULL,0);
		if(connection)
	{
		cout<<"Conexion exitosa a la base de datos "<<endl;
	    fflush(stdin);
	    cout<<endl;
		cout << "Ingrese el nombre del alumno: ";
		getline(cin, alumno_nombre);
			do{
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql2 = "SELECT * FROM alumno where alumno_nombre='" + alumno_nombre + "'";
			query = sql2.c_str();
			result = mysql_query(connection, query);
			if (result == 0)
			{
				cout << "Se han obtenido los datos del alumno" << endl;	
				cout<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 4; i < countColumns; i++)
					{
						cout << "Id: " << row[0] << endl;
     					cout << "Nombre: " << row[1] << endl;      
      					cout << "Clave: " << row[2] << endl;      
      					cout << "Correo: " << row[3] << endl;
      					cout << "Promedio: " << row[4] << endl; 
					}
					cout << endl;
					if (result == result)
    			{
    			cout<<"El Registro ya fue ingresado"<<endl;
    			}	
				}
			} 
		}
		while(result != result);
		cout<<"ingrese de nuevo el nombre del alumno:";
		fflush(stdin);
		getline(cin, alumno_nombre);
		
		cout << "Ingrese la clave del alumno: ";
		getline(cin, alumno_clave);
		cout << "Ingrese el correo del alumno: ";
		getline(cin, alumno_correo);
		cout << "Promedio del alumno: "; 
		getline(cin, alumno_promedio);
		sql = "INSERT INTO alumno(alumno_nombre,alumno_clave,alumno_correo,alumno_promedio) VALUES ('" + alumno_nombre + "','" + alumno_clave + "','" + alumno_correo + "','" + alumno_promedio + "')";
		query = sql.c_str();
		result = mysql_query(connection, query);
		if(result == 0)
		{
			cout<<"Datos de alumno guardado"<<endl;
			cout<<endl;
		}	
		else
		{
			cout<<"no fue posible guardar dato de alumno"<<mysql_error(connection)<<endl;
		}		
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}
//////////////////////AGREGAR GRADO///////////////////
void AgregarGrado(){
	MYSQL* connection;
	long grado_id;
	string grado_nombre;
	string grado_codigo;
	string sql;
	int result;
	const char* query;
	connection = mysql_init(0);
	if (connection)
	{
		cout<< "La libreria MySQL se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection,serverdb, userdb, passworddb,databasedb, 3306, NULL,0);
		if(connection)
	{
		cout<<"Conexion exitosa a la base de datos " << endl;
		fflush(stdin);
	    cout<<endl;
		cout << "Ingrese el nombre del grado: "; 
		getline(cin, grado_nombre); 
		cout << "Ingrese el codigo del grado: "; 
		getline(cin, grado_codigo); 
		sql = "INSERT INTO grado(grado_nombre,grado_codigo) VALUES ('" + grado_nombre + "','" + grado_codigo + "')";
		query = sql.c_str();
		result = mysql_query(connection, query);
		if(result == 0)
		{
			cout<<"Datos de grado guardado"<<endl;
			cout<<endl;
		}	
		else
		{
			cout<<"no fue posible guardar dato de grado"<<mysql_error(connection)<<endl;
		}	
			
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}
//////////////////////AGREGAR SECCION///////////////////
void AgregarSeccion(){
	MYSQL* connection;
	long seccion_id;
	string seccion_nombre;
	string sql;
	int result;
	const char* query;
	connection = mysql_init(0);
	if (connection)
	{
		cout<< "La libreria MySQL se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection,serverdb, userdb, passworddb,databasedb, 3306, NULL,0);
		if(connection)
	{
		cout<<"Conexion exitosa a la base de datos " << endl;
		fflush(stdin);
	    cout<<endl;
		cout << "Ingrese el nombre de la seccion: "; 
		getline(cin, seccion_nombre);  
		sql = "INSERT INTO seccion(seccion_nombre) VALUES ('" + seccion_nombre + "')";
		query = sql.c_str();
		result = mysql_query(connection, query);
		if(result == 0)
		{
			cout<<"Datos de seccion guardado"<<endl;
			cout<<endl;
		}	
		else
		{
			cout<<"no fue posible guardar dato de seccion"<<mysql_error(connection)<<endl;
		}		
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}
//////////////////////AGREGAR NOTA///////////////////
void AgregarNota(){
	MYSQL* connection;
	long nota_id;
	string nota_primer_bimestre;
	string nota_segundo_bimestre;
	string nota_tercer_bimestre;
	string nota_cuarto_bimestre;
	string sql;
	int result;
	const char* query;
	connection = mysql_init(0);
	if (connection)
	{
		cout<< "La libreria MySQL se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection,serverdb, userdb, passworddb,databasedb, 3306, NULL,0);
		if(connection)
	{
		cout<<"Conexion exitosa a la base de datos " << endl;
		fflush(stdin);
	    cout<<endl;
		cout << "Ingrese la nota del primer bimestre: "; 
		getline(cin, nota_primer_bimestre); 
		cout << "Ingrese la nota del segundo bimestre: "; 
		getline(cin, nota_segundo_bimestre);
		cout << "Ingrese la nota del tercer bimestre: "; 
		getline(cin, nota_tercer_bimestre);
		cout << "Ingrese la nota del cuarto bimestre: "; 
		getline(cin, nota_cuarto_bimestre);
		sql = "INSERT INTO nota(nota_primer_bimestre,nota_segundo_bimestre,nota_tercer_bimestre,nota_cuarto_bimestre) VALUES ('" + nota_primer_bimestre + "','" + nota_segundo_bimestre + "','" + nota_tercer_bimestre + "','" + nota_cuarto_bimestre + "')";
		query = sql.c_str();
		result = mysql_query(connection, query);
		if(result == 0)
		{
			cout<<"Datos de nota guardado"<<endl;
			cout<<endl;
		}	
		else
		{
			cout<<"no fue posible guardar dato de nota"<<mysql_error(connection)<<endl;
		}		
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}
////////////////////BUSCAR ALUMNO///////////////////////////////
void BuscarAlumno(){
	MYSQL* connection;
	long alumno_id;
	string alumno_nombre;
	string sql;
	int result;
	const char* query;
	connection = mysql_init(0);
	if (connection)
	{
		cout<< "La libreria MySQL se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection,serverdb, userdb, passworddb,databasedb, 3306, NULL,0);
		if(connection)
	{
		cout<<"Conexion exitosa a la base de datos "<<endl;
	    fflush(stdin);
	    cout<<endl;
		cout << "Ingrese el nombre del alumno a buscar: ";
		cin>>alumno_nombre; 
		//pendiente de obtener
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "SELECT * FROM alumno where alumno_nombre='" + alumno_nombre + "'";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0)
			{
				cout << "Se han obtenido los datos del alumno" << endl;	
				cout<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 4; i < countColumns; i++)
					{
						cout << "Id: " << row[0] << endl;
     					cout << "Nombre: " << row[1] << endl;      
      					cout << "Clave: " << row[2] << endl;      
      					cout << "Correo: " << row[3] << endl;
      					cout << "Promedio: " << row[4] << endl; 
					}
					cout << endl;
				}
			}
			else
			{
      		cout << "No se han obtenido los datos del alumno, aun no existe" << endl;
      		}
		}
		else
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}
////////////////////MODIFICAR GRADO//////////////////////////////////////////////
void ModificardatoGrado(){
	MYSQL* connection;
	string grado_id;
	string grado_nombre;
	string grado_codigo;
	string sql;
	string sql3;
	string modify;
	int result;
	MYSQL_ROW row;
	MYSQL_RES* data;
	const char* query;
	connection = mysql_init(0);
	if (connection)
	{
		cout<< "La libreria MySQL se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection,serverdb, userdb, passworddb,databasedb, 3306, NULL,0);
		if(connection)
	{
		sql3 = "SELECT * FROM grado ";
			query = sql3.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han obtenido los datos del grado" << endl;
				cout<<endl;	
				cout<<"Registros de Grados Ingresados para Modificar:"<<endl;
				cout<<endl;
				cout<<"Id"<<"\t"<<"Nombres"<<" "<<"Codigo"<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout << row[i] << "\t";
     				    
					}
					cout << endl;
				}
			}
			cout<<endl;	
		cout<<"Conexion exitosa a la base de datos "<<endl;
	    fflush(stdin);
	    cout<<endl;
		cout << "Ingrese el nombre del grado a modificar: ";
		cin>>grado_nombre; 
		cout << "Ingrese el id del grado a modificar: ";
		cin>>grado_id; 
		//pendiente de obtener
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "SELECT * FROM grado where grado_nombre='" + grado_nombre + "'";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0)
			{
				cout << "Se han obtenido los datos del grado" << endl;	
				cout<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 2; i < countColumns; i++)
					{
						cout << "Id: " << row[0] << endl;
     					cout << "Nombre: " << row[1] << endl;      
      					cout << "Codigo: " << row[2] << endl;      
      				
					}
					cout << endl;
				}
			}
			fflush(stdin);
	    	cout<<endl;
			cout << "Ingrese el nuevo nombre del grado: ";
			getline(cin, grado_nombre); 
			cout << "Ingrese el nuevo codigo del grado: ";
			getline(cin, grado_codigo);
			//pendiente de obtener
			modify = "UPDATE grado SET grado_nombre='" + grado_nombre + "',grado_codigo='" + grado_codigo + "' WHERE grado_id='" + grado_id + "'";
			query = modify.c_str();
			result = mysql_query(connection, query);
			if(result == 0)
		{
			fflush(stdin);
	    	cout<<endl;
			cout<<"Datos del grado actualizado"<<endl;
			cout<<"Nuevo nombre del grado:"<< grado_nombre<<endl;
			cout<<"Nuevo codigo del grado:"<< grado_codigo<<endl;
			cout<<endl;
		}	
			else
			{
      		cout << "No se han obtenido los datos del grado, aun no existe" << endl;
      		}
		}
		else
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}

void AsignarAlumno(){
	MYSQL* connection;
	long asignado_id;
	string alumno_id;
	string grado_id;
	string seccion_id;
	string nota_id;
	string sql;
	string sql3;
	string sql4;
	string sql5;
	string sql6;
	int result;
	MYSQL_ROW row;
	MYSQL_RES* data;
	const char* query;
	connection = mysql_init(0);
	if (connection)
	{
		cout<< "La libreria MySQL se ha iniciado correctamente"<<endl;
		cout<<endl;
		connection = mysql_real_connect(connection,serverdb, userdb, passworddb,databasedb, 3306, NULL,0);
		if(connection)
	{
			sql3 = "SELECT * FROM alumno ";
			query = sql3.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout<<"Registros de Alumnos Ingresados para Asignar:"<<endl;
				cout<<"Id"<<"\t"<<"Nombres "<<"\t"<<"Clave"<<"\t"<<"Correo"<<"\t\t"<<"Promedio nota"<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout << row[i] << "\t";
     				    
					}
					cout << endl;
				}
			}
			cout<<endl;
			sql4 = "SELECT * FROM grado ";
			query = sql4.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout<<"Registros de Grados Ingresados para Asignar:"<<endl;
				cout<<"Id"<<"\t"<<"Nombres"<<" "<<"Codigo"<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout << row[i] << "\t";
     				    
					}
					cout << endl;
				}
			}
			cout<<endl;
			sql6 = "SELECT * FROM nota ";
			query = sql6.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout<<"Registros de Notas por Bimestre Ingresadas para Asignar:"<<endl;
				cout<<"Id"<<"\t"<<"Bim(1)"<<" "<<"Bim(2)"<<" "<<"Bim(3)"<<" "<<"Bim(4)"<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout << row[i] << "\t";
     				    
					}
					cout << endl;
				}
			}
			cout<<endl;
			sql5 = "SELECT * FROM seccion ";
			query = sql5.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout<<"Registros de Seccion Ingresados para Asignar:"<<endl;
				cout<<"Id"<<"\t"<<"Nombres"<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout << row[i] << "\t";
     				    
					}
					cout << endl;
				}
			}
			cout<<endl;				
		cout<<"Conexion exitosa a la base de datos "<<endl;
	    fflush(stdin);
	    cout<<endl;
		cout << "Ingrese el id del alumno a asignar: ";
		getline(cin, alumno_id); 
		cout << "Ingrese el id del grado para asignar al alumno: ";
		getline(cin, grado_id);
		cout << "Ingrese el  id de la seccion para asignar al alumno: ";
		getline(cin,seccion_id);
		cout << "Ingrese el id de la nota para asignar al alumno: ";
		getline(cin,nota_id);
		//pendiente de obtener
		sql = "INSERT INTO asignado(alumno_id, grado_id, seccion_id,nota_id) VALUES ('" + alumno_id + "','" + grado_id + "','" + seccion_id + "','" + nota_id + "')";
		query = sql.c_str();
		result = mysql_query(connection, query);
		if(result == 0)
		{
			cout<<"Datos de alumno guardado"<<endl;
			cout<<endl;
		}	
		else
		{
			cout<<"no fue posible guardar dato de alumno"<<mysql_error(connection)<<endl;
		}		
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
	
}

///////////////////////LISTAR ALUMNO GRADO Y SECCION//////////////////
void Listaralumnogradoyseccion(){
	int opcion;
	char opc = 's';
	while (opc == 's')
	{
    system("cls");
	int opcion;
	cout<<"Ingrese una de las siguientes ocpiones"<<endl;
	cout<<"1-Listar Los Alumnos de un Grado"<<endl; 
	cout<<"2-Listar Los Alumnos de una Seccion"<<endl;
	cout<<"3-Regresar al menu"<<endl;
	cin>>opcion;
switch (opcion)
	{
	
		case 1: 
         		ListarGrado();
        break;
        case 2: 
         		ListarSeccion();
        break;
        case 3: 
         		cout<<"Desea regresar al menu de listar alumnos S/N ?\n"<<endl;
                fflush(stdin);
				cin>>opc;
		break;
		}
	}
}
////////////////////////LISTAR GRADO//////////////////////////
void ListarGrado(){
	MYSQL* connection;
	long asignado_id;
	string grado_nombre;
	string sql;
	string sql2;
	int result;
	MYSQL_ROW row;
	MYSQL_RES* data;
	const char* query;
	connection = mysql_init(0);
	if (connection)
	{
		cout<< "La libreria MySQL se ha iniciado correctamente"<<endl;
		connection = mysql_real_connect(connection,serverdb, userdb, passworddb,databasedb, 3306, NULL,0);
		if(connection)
	{
		cout<<endl;
			sql2 = "SELECT * FROM grado ";
			query = sql2.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout<<"Registros de Grados Ingresados para Listar:"<<endl;
				cout<<"Id"<<"\t"<<"Nombres"<<" "<<"Codigo"<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout << row[i] << "\t";
     				    
					}
					cout << endl;
				}
			}
			cout<<endl;
		cout<<"Conexion exitosa a la base de datos "<<endl;
	    fflush(stdin);
	    cout<<endl;
		cout << "Ingrese el nombre del grado para Listar a los alumnos asignados: ";
		cin>>grado_nombre; 
		//pendiente de obtener
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "SELECT grado.grado_nombre, alumno.alumno_nombre, alumno.alumno_clave , alumno.alumno_correo , alumno.alumno_promedio FROM asignado inner join alumno on asignado.alumno_id = alumno.alumno_id  inner join grado on asignado.grado_id = grado.grado_id where grado.grado_nombre = '" + grado_nombre + "'";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0)
			{
				cout << "Se han obtenido los alumnos asignados al grado"<<" "<<grado_nombre<< endl;	
				cout<<endl;
				cout<<"Grado"<<"\t\t"<<"Nombres de Alumnos"<<"\t"<<"Clave"<<"\t\t"<<"Correo"<<"\t\t\t"<<"Promedio nota"<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout << row[i] <<"\t\t";
					}
					cout << endl;
				}
			}
			else
			{
      		cout << "No se han obtenido los datos del grado" << endl;
      		}
		}
		else
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
	cout<<endl;
	system("Pause()");
}
void ListarSeccion(){
	MYSQL* connection;
	long asignado_id;
	string seccion_nombre;
	string sql;
	string sql2;
	int result;
	MYSQL_ROW row;
	MYSQL_RES* data;
	const char* query;
	connection = mysql_init(0);
	if (connection)
	{
		cout<< "La libreria MySQL se ha iniciado correctamente"<<endl;
		cout<<endl;
		connection = mysql_real_connect(connection,serverdb, userdb, passworddb,databasedb, 3306, NULL,0);
		if(connection)
	{
		sql2 = "SELECT * FROM seccion ";
			query = sql2.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout<<"Registros de Seccion Ingresados para Asignar:"<<endl;
				cout<<"Id"<<"\t"<<"Nombres"<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout << row[i] << "\t";
     				    
					}
					cout << endl;
				}
			}
			cout<<endl;	
		cout<<"Conexion exitosa a la base de datos "<<endl;
	    fflush(stdin);
	    cout<<endl;
		cout << "Ingrese el nombre de la seccion para Listar a los alumnos asignados: ";
		cin>>seccion_nombre; 
		//pendiente de obtener
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "SELECT seccion.seccion_nombre, alumno.alumno_nombre, alumno.alumno_clave , alumno.alumno_correo , alumno.alumno_promedio FROM asignado inner join alumno on asignado.alumno_id = alumno.alumno_id  inner join seccion on asignado.seccion_id = seccion.seccion_id where seccion.seccion_nombre = '" + seccion_nombre + "'";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0)
			{
				cout << "Se han obtenido los alumnos asignados a la seccion"<<" "<<seccion_nombre<< endl;	
				cout<<endl;
				cout<<"Seccion"<<"\t\t"<<"Nombres de Alumnos"<<"\t"<<"Clave"<<"\t\t"<<"Correo"<<"\t\t\t"<<"Promedio nota"<<endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout << row[i] <<"\t\t";
					}
					cout << endl;
				}
			}
			else
			{
      		cout << "No se han obtenido los datos de la seccion" << endl;
      		}
		}
		else
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
	cout << endl;
	system("Pause()");
}
