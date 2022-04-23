CREATE TABLE grado (
	grado_id BIGINT auto_increment NOT NULL,
	grado_nombre varchar(100) NOT NULL,
	grado_codigo varchar(100) NOT NULL,
	CONSTRAINT grado_pk PRIMARY KEY (grado_id)
);
CREATE TABLE seccion (
	seccion_id BIGINT auto_increment NOT NULL,
	seccion_nombre varchar(100) NOT NULL,
	CONSTRAINT seccion_pk PRIMARY KEY (seccion_id)
);
CREATE TABLE alumno (
	alumno_id BIGINT auto_increment NOT NULL,
	alumno_nombre varchar(100) NOT NULL,
	alumno_clave varchar(100) NOT NULL,
	alumno_correo varchar(100) NOT NULL,
	alumno_promedio varchar(100) NOT NULL,
	CONSTRAINT alumno_pk PRIMARY KEY (alumno_id)
);
CREATE TABLE nota (
	nota_id BIGINT auto_increment NOT NULL,
	nota_primer_bimestre varchar(100) NOT NULL,
	nota_segundo_bimestre varchar(100) NOT NULL,
	nota_tercer_bimestre varchar(100) NOT NULL,
	nota_cuarto_bimestre varchar(100) NOT NULL,
	CONSTRAINT nota_pk PRIMARY KEY (nota_id)
);
CREATE TABLE asignado (
	asignado_id BIGINT auto_increment NOT NULL,
	alumno_id BIGINT NOT NULL,
	grado_id BIGINT  NOT NULL,
	nota_id BIGINT  NOT NULL,
	seccion_id BIGINT  NOT NULL,
	CONSTRAINT asignado_pk PRIMARY KEY (asignado_id)
);
ALTER TABLE asignado 
ADD CONSTRAINT asignado_alumno
FOREIGN KEY (alumno_id) REFERENCES alumno(alumno_id);

ALTER TABLE asignado 
ADD CONSTRAINT asignado_grado
FOREIGN KEY (grado_id) REFERENCES grado(grado_id);

ALTER TABLE asignado 
ADD CONSTRAINT asignado_seccion
FOREIGN KEY (seccion_id) REFERENCES seccion(seccion_id);

ALTER TABLE asignado 
ADD CONSTRAINT asignado_nota
FOREIGN KEY (nota_id) REFERENCES nota(nota_id);

select * from alumno;
select * from grado;
select * from seccion;
select * from nota;
select * from asignado;

select grado.grado_nombre, alumno.alumno_nombre, alumno.alumno_clave 
from asignado
inner join alumno on asignado.alumno_id = alumno.alumno_id
inner join grado on asignado.grado_id = grado.grado_id
where grado.grado_id = 5;


alter table seccion auto_increment=3;





