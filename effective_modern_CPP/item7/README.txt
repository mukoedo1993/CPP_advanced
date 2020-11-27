A novel feature of braced initialization is that it prohibits implicit narrowing conversions 
among built-in types. 


To drawback to braced initialization is the sometimes-surprising behavior that accompanies it. Such 
behaviro grows out of the unusually tangled relationship among braced initializers, std::initializer_list,
and constructor oberload resolution.
