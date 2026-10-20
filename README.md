# DLLIntegrityMonitor

This tool is built using C++ and Win32 API. 
The purpose of this tool is to verify the integrity of DLLs that are currently being used. 
The program will take a snapshot of currently running DLLs and run them through a SHA-256 hashing algorithm, which will act as a baseline to compare against. 
Any unexpected changes or modifications will be detected by running the same DLL through a hash algorithm and getting a different hash. 
This mimics the same methods used to detected hijacked DLLs used in EDR and anti-cheat software.
