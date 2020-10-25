AMP = @

CC = ${AMP}gcc
CC_FLAGS = -fPIC -Wall

INCLUDE_FLAG = -Iinclude
LINK_FLAG = -lorepl

AR = ${AMP}ar
RM = ${AMP}rm -f

OREPL_NAMES = 
OREPL_NAMES += orepl

OREPL_OBJ_NAMES = ${addsuffix .o, ${OREPL_NAMES}}
OREPL_OBJS = ${addprefix build/, ${OREPL_OBJ_NAMES}}

OREPL_STATIC_LIB = build/liborepl.a
OREPL_DYNAMIC_LIB = build/liborepl.so

MAIN_SRC = src/main.c
MAIN_OBJ = build/main.o

BIN = build/orepl

default: clean lib ${BIN}

lib: ${OREPL_STATIC_LIB} ${OREPL_DYNAMIC_LIB}

debug:
	${eval AMP := }

${BIN}: ${MAIN_OBJ} ${OREPL_OBJS}
	${CC} $^ -o $@

${MAIN_OBJ}: ${MAIN_SRC}
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}

${OREPL_OBJS}: build/%.o: lib/%.c include/%.h
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}

${OREPL_STATIC_LIB}: ${OREPL_OBJS}
	${AR} rcs $@ $^

${OREPL_DYNAMIC_LIB}: ${OREPL_OBJS}
	${CC} -shared $^ -o $@

redo: clean default

run: ${BIN}
	@${BIN}

move:
	sudo cp ${BIN} /usr/bin

clean:
	${RM} ${BIN}
	${RM} ${MAIN_OBJ}
	${RM} ${OREPL_OBJS}
	${RM} ${OREPL_STATIC_LIB}
	${RM} ${OREPL_DYNAMIC_LIB}


