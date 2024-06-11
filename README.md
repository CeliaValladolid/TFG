# Válvula ventriculoperitoneal regulada por un sensor de presión

## Alumna: Celia Valladolid Portal
## Tutor: Guirguis Zaki Guirguis Abdelmessih

En este repositorio se encuentran todos los documentos elaborados a lo largo de la realización de este proyecto.
Los contenidos de este repositorio son los siguientes:
- **Carpeta img**: en esta carpeta se incluyen todas la imágenes empleadas en el proyecto, tanto para la memoria como para los anexos.
- **Carpeta tex**: esta carpeta está compuesta por 14 documentos LaTex **.tex** y 1 documento **.txt**.
  - 1_objetivos.tex: documento que contiene la información acerca de los objetivos del proyecto, objetivo general y objetivos específicos.
  - 2_abreviaturas.tex: documento que contiene las abreviaturas y siglas empleadas en el proyecto.
  - 3_introduccion.tex: documento que contiene los conceptos teóricos acerca de la hidrocefalia y estado del arte y trabajos relacionados.
  - 4_metodologia.tex: documento que contiene la información relativa a los datos del proyecto y técnicas y herramientas empleadas para su desarrollo.
  - 5_conclusiones.tex: documento que contiene los resultados, discusión y aspectos relevantes del proyecto.
  - 6_lineas_futuras.tex: documento que contiene información acerca de futuras mejoras del proyecto e indicaciones  e ideas sugeridas para ello.
  - A_planificacion.tex: documento que contiene la planificación del proyecto tanto temporal como económica y la viabilidad legal.
  - B_manual_usuario.tex: documento que contiene los requisitos de software y hardware así como demostraciones del prototipo.
  - C_manual_programador.tex: documento que contiene la estructura de directorios e instrucciones para mejoras o modificaciones futuras del proyecto.
  - D_datos.tex: documento que contiene todo lo referente a la adquisición y tratamiento de datos.
  - E_diseno.tex: documento que contiene la información referente al diseño del prototipo.
  - F_requisitos.tex: documento que contiene diagramas de casos de uso junto con su explicación.
  - G_experimental.tex: documento que contiene el cuaderno de trabajo con la explicación de los resultados tanto positivos como negativos.
  - H_ODS.tex: documento que contiene una reflexión personal acerca de los aspectos de sostenibilidad que se abordan en el proyecto.
  - readme.txt: documento que contiene todas las fuentes latex para memoria y anexos.
- **Carpeta memoria**: esta carpeta contiene dos archivos **.pdf** y **.tex** referentes a la memoria del proyecto.
  - memoria.pdf: documento pdf que contiene la memoria del proyecto.
  - memoria.tex: documento LaTex que contiene la estructura de la memoria del proyecto.
- **Carpeta anexos**: esta carpeta contiene dos archivos **.pdf** y **.tex** referentes a los anexos del proyecto.
  - anexos.pdf: documento pdf que contiene los anexos del proyecto.
  - anexos.tex: documento LaTex que contiene la estructura de los anexos del proyecto.
- **Carpeta bibliografia**: esta carpeta contiene dos archivos **.bib** referentes a la bibliografía del proyecto.
  - bibliografia.bib: documento que contiene la bibliografía empleada en la memoria del proyecto.
  - bibliografiaAnexos.bib: documento que contiene la bibliografía empleada en los anexos del proyecto.
- **Carpeta arduino**: carpeta que contiene el documento **.ino** correspondiente al programa del proyecto.
-  **Carpeta demostraciones**: carpeta que contiene un vídeo para demostrar la funcionalidad del proyecto.
- **datasheetMPX5010dp.pdf**: documento pdf correspondiente al datasheet del sensor empleado.
- **README.md**: documento de presentación del repositorio.

### Resumen
Lo más importante para desarrollar un proyecto es tener una idea y a partir de ahí trabajar en ella teniendo un propósito. La idea de este proyecto surge durante mi estancia de prácticas en el Hospital Universitario de Burgos, concretamente durante mi rotación por el servicio de Neurocirugía. Tras haber finalizado la revisión de una válvula ventriculoperitoneal a un paciente con hidrocefalia, el neurocirujano encargado de llevar a cabo la operación mencionó tanto la importancia como la falta de telemetría en el campo de la neurocirugía y ahí fue cuando esta idea comenzó a coger forma. Actualmente en el mercado no hay un dispositivo que cumpla con la idea de este proyecto, controlar la apertura de la válvula a través de un sensor de presión intracraneal, todos ellos se programan de forma manual mediante herramientas magnéticas y por lo tanto no tienen la posibilidad de monitorear de forma continua, remota y en tiempo real al paciente. En este proyecto se ha simulado la funcionalidad de la válvula haciendo uso de diferentes componentes electrónicos. La mini bomba empleada sería la válvula, encargada de dejar pasar un fluido en función de las lecturas previas que realice el sensor de presión. El desarrollo de una aplicación móvil que permita el monitoreo se ha planteado como una mejora futura aunque es un aspecto clave en este dispositivo.

