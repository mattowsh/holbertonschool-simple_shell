Readme was created

**PENDING**

CODE
- error message
- error value in exit (errno)
- check if every token, of path, has at final byte a "/"

MEMORY LEAKS
- all files

TXT
- Readme
- Man
- Linkedin blog
- Flowchart

OTHER
- **test directory**



Flowdchart
==========

```mermaid
graph TD;
  Start0(Shell starts)
  Start0-->While0{Continue if it's interactive mode}
  While0-->If0{Is it interactive<br>mode?}
  If0-->Getline[Read input]
  Getline-->Fork0[Create a<br>child process]
  Fork0-->|Input is equal to exit|Exit0[Exit shell]
  Fork0-->Fork1{Check if it's<br>parent or<br>child}
  Fork1-->|Child|Execve[Execute<br>requested<br>command]
  Fork1-->|Parent|Wait[Wait for<br>child to<br>finish]
  ```
