# invoke SourceDir generated makefile for empty.pem4f
empty.pem4f: .libraries,empty.pem4f
.libraries,empty.pem4f: package/cfg/empty_pem4f.xdl
	$(MAKE) -f C:\TI_RTOS\TM4C\Labs\Lab_06\blink_TM4C_SWI/src/makefile.libs

clean::
	$(MAKE) -f C:\TI_RTOS\TM4C\Labs\Lab_06\blink_TM4C_SWI/src/makefile.libs clean

