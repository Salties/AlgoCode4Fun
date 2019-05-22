PROJECT=lps
CFLAGS+=-g -Wall

${PROJECT}: ${PROJECT}.c

clean:
	rm -f ${PROJECT}
