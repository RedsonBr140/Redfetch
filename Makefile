PROJ_NAME=redfetch
SRC=./src/${PROJ_NAME}.c
OBJ=$(subst .c,.o,$(subst src,build,$(SRC)))

CC_FLAGS=-c			\
		  -W		\
		  -Wall		\
		  -pedantic 	\
		  -Werror 	# A warning at compile time is an error at runtime
all: options buildFolder $(PROJ_NAME)

$(PROJ_NAME):
	$(CC) -o build/$@ -static $(SRC)

buildFolder:
	@ mkdir -p build

options: 
	@echo $(PROJ_NAME) build options:
	@echo "CC_FLAGS = $(CC_FLAGS)"
	@echo "CC = $(CC)\n"

clean:
	rm -rf $(PROJ_NAME) $(OBJ) build

install: all
	@echo $(PREFIX)
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f $(PROJ_NAME) ${DESTDIR}${PREFIX}/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/$(PROJ_NAME)

uninstall:
	rm -f $(DESTDIR)/usr/bin/$(PROJ_NAME)

.PHONY: all options clean install uninstall
