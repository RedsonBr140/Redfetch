PROJ_NAME=redfetch
SRC=$(wildcard ./src/*.c)
OBJ=$(subst .c,.o,$(subst src,build,$(SRC)))

CC_FLAGS=-c			\
		  -W		\
		  -Wall		\
		  -pedantic \
		  -Werror 	# A warning at compile time is an error an runtime”
all: options buildFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) $^ -o $@ -static

buildFolder:
	@ mkdir -p build

options: 
	@echo $(PROJ_NAME) build options:
	@echo "CC_FLAGS = $(CC_FLAGS)"
	@echo "CC = $(CC)\n"

$(OBJ): $(SRC)
	$(CC) $< $(CC_FLAGS) -o $@

clean:
	rm -rf $(PROJ_NAME) $(OBJ) build

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f $(PROJ_NAME) ${DESTDIR}${PREFIX}/bin
	chmod 755 $(DESTDIR)/usr/bin/$(PROJ_NAME)

uninstall:
	rm -f $(DESTDIR)/usr/bin/$(PROJ_NAME)

.PHONY: all options clean install uninstall
