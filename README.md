En esto proyecto se va a replicar el juego "flappy birds" hecho con la libreria grafica de Raylib.

Esta sera la version 0.1 por lo que sus consignas seran reducidas

Sprint 1 (martes 5/10 a martes 12/10) - Tareas a realizar:
● Crear un nuevo proyecto vacío de C++ e integrar la biblioteca de programación raylib
para crear lo que terminará siendo un juego tipo Flappy Bird.
Dado que este será el único proyecto en la solución, al crearlo tildar la opción de que
coloque solución y proyecto en mismo directorio:
● Crear un nuevo repositorio para alojar este proyecto y versionar correctamente:
○ Crear gitignore correcto
○ No versionar archivos que se pueden regenerar (ejecutable, por ej.)
○ Escribir buenos mensajes de commit
○ Realizar commits atómicos
○ Agregar descripción a proyecto
○ Crear README.md con info adecuada
● Seguir los mismos procedimientos y buenas prácticas destacados hasta el momento
y en los documentos entregados hasta el momento, en lo relativo a:
○ Proyecto
○ Commits
○ Código
○ Aspectos de usabilidad
● 3 escenas con el siguiente flujo:
○ Menu
○ Creditos
○ Gameplay
● Personaje que controla el usuario:
○ Está en el lado izquierdo de la pantalla
○ Se mueve de arriba a abajo para esquivar lo que viene desde la derecha (el
  movimiento puede ser simple con las flechas, sin gravedad por el momento).
● Obstáculo:
○ Uno solo por el momento
○ Aparece desde la derecha
○ Se mueve hacia la izquierda
○ Al desaparecer por el lado izquierdo de pantalla vuelve a aparecer por la
derecha, a otra altura
● Condición de derrota: si obstáculo y personaje colisionan.
● Tanto en el menú como en los créditos debe figurar la versión del juego (0.1)
● Una vez realizado lo que se plantea aquí debe generar un tag de nombre 0.1 y subir
el ejecutable asociado al tag a Releases de GitHub.
● Para este sprint debe crearse un nuevo Project en GitHub con un tablero tipo
Kanban, crear cards de las tareas a realizar, e ir administrándolas en el tablero
según se vayan realizando.
Importante:
● No hace falta implementar nada extra en esta etapa. Es preferible que se tengan
estos requisitos mínimos y que se revisen los documentos de buenas prácticas para
hacer un chequeo de que esté todo según lo solicitado.
● No hay que hacer página de itch para el juego en esta etapa.
● Anotar las dudas que le surjan en el proceso, para traerlas a clase.