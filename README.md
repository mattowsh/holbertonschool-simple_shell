Readme was created

**PENDING**

CODE
- error message: por que pone salto de linea el return??
- check if every token, of path, has at final byte a "/"
- checkeo cuando input es \n\t\nexit\t\n, estoy trabajando con una copia de b,
no deberia generarnos problema...

MEMORY LEAKS
- all files

TXT
- Readme
- Man
- Linkedin blog
- Flowchart



Flowdchart
==========

```mermaid
graph TD;
  Start0(Shell starts)
  Start0-->While0{Continue if it's interactive mode}
  While0-->If0{Is it interactive<br>mode?}
  While0-->Exit1(End non<br>interactive<br>mode)
  If0-->Getline[Read input]
  Getline-->Fork0[Create a<br>child process]
  Fork0-->|Input is equal to exit|Exit0(Exit shell)
  Fork0-->Fork1{Check if it's<br>parent or<br>child}
  Fork1-->|Child|Execve[Execute<br>requested<br>command]
  Fork1-->|Parent|Wait[Wait for<br>child to<br>finish]
  Execve-->|Finish process|Wait
  Wait-->While0
  ```
